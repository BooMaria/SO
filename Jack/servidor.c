/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Sevidor, este codigo gestiona las peticiones de las estaciones para generar
 * un servidor dedicado.
 */

#define _GNU_SOURCE

#include "semaphore_v2.h"
#include "servidor.h"

pid_t pid1;
int flag = FALSE;
int memid;
Elemento *dades;//compartido
Llista estacions;
Config config;

//semaphore semExclu;
semaphore semSincron;

int socket_fd;

void close_server() {
    kill(pid1, SIGINT);//ACABA FILL
    write(1, CLOSE_SERVER, sizeof(CLOSE_SERVER));
    close(socket_fd);
    shmdt(dades);
    shmctl(memid, IPC_RMID, NULL);
    SEM_destructor(&semSincron);
    //SEM_destructor(&semExclu);
    free(config.ip);
    exit(0);
}

void close_lloyd(){
    write(1, CLOSE_LLOYD, strlen(CLOSE_LLOYD));
    LLISTAREFER_destrueix(&estacions);
    exit(0);
}

int launch_server(int port, char *ip, int *socket_fd) {
    struct sockaddr_in s_addr;
    *socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*socket_fd < 0) {
        write(1, ERROR_SOCKET, sizeof(ERROR_SOCKET));
        return -1;
    }
    bzero(&s_addr, sizeof (s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons (port);
    s_addr.sin_addr.s_addr = inet_addr(ip);
    if (bind (*socket_fd, (void *) &s_addr, sizeof (s_addr)) < 0) {
        write(1, ERROR_BIND, sizeof(ERROR_BIND));
        return -1;
    }
    listen(*socket_fd, LISTEN_BACKLOG);
    return 0;
}

void dadesNoves(char *nom, char *thisDades){
    //SEM_wait(&semExclu);
    LLISTAREFER_setDADES(thisDades, dades, nom);
    SEM_signal(&semSincron);
}

void run_server(int socket_fd) {
    struct sockaddr_in c_addr;
    socklen_t c_len = sizeof(c_addr);
    SERDEDICAT_crea();
    write(1, WAIT_CONNECT, sizeof(WAIT_CONNECT));
    while (1) {
        int fd;
        fd = accept(socket_fd, (void *) &c_addr, &c_len);
        if (!SERDEDICAT_run(fd)) {
            break;
        }
    }
}

void guardarEstacions(){
    flag = FALSE;
    FITXER_writeDades(&estacions);
    write(1, "\nGuarda estacions\n", 18);
    signal(SIGALRM, guardarEstacions);
    alarm(120);
}

int main(int argc, char const *argv[]) {
    write(1, SERVER_INIT, strlen(SERVER_INIT));

   // SEM_constructor_with_name(&semExclu, ftok("mensaje.c", 'a'));
    SEM_constructor_with_name(&semSincron, ftok("servidor.c", 'b'));
    //SEM_init(&semExclu, 1);
    SEM_init(&semSincron, 0);

    memid = shmget(IPC_PRIVATE, sizeof(Elemento), IPC_CREAT | IPC_EXCL | 0600);
    if(memid > 0){
        dades = shmat(memid, 0, 0);
        pid1 = fork();
        switch (pid1) {
            case -1:
                write(1, ERROR_FORK, strlen(ERROR_FORK));
                break;
            case 0://fill, lloyd
                flag = TRUE;
                write(1, LLOYD_INIT, strlen(LLOYD_INIT));
                signal(SIGALRM, guardarEstacions);
                signal(SIGINT, close_lloyd);
                alarm(40);//120
                estacions = LLISTAREFER_crea();
                while(TRUE){//Pregunta com millora la sincronitzacio, mutex perque son el qui entren?
                    SEM_wait(&semSincron);
                    if(flag) {
                        LLISTAREFER_insereixV2(&estacions, *dades);
                        LLISTAREFER_print(estacions);
                        //SEM_signal(&semExclu);
                    }
                    flag = TRUE;
                }
            default://Pare
                if (argc != ARGS) {
                    write(1, ERROR_ARGS, sizeof(ERROR_ARGS));
                    close_server();
                    return -1;
                }
                FITXER_readConfig(argv[1], &config);
                if (launch_server(config.port, config.ip, &socket_fd) < 0) {
                    write(1, ERROR_MAIN, sizeof(ERROR_MAIN));
                }
                signal(SIGINT, close_server);
                run_server(socket_fd);
                break;
        }
    }else{
        write(1, ERROR_MEMO_COMP, strlen(ERROR_MEMO_COMP));
    }
    return 0;
}


