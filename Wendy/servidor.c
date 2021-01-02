

#define _GNU_SOURCE

#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>


#include "servidor.h"


#define ERR_NOFILEAVAILABLE         "\nNo files available"

#define ARGS                2

int socket_fd;

Config config;

void close_server() {
    write(1, CLOSE_SERVER, sizeof(CLOSE_SERVER));
    free(config.ip);
    close(socket_fd);
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

int main(int argc, char const *argv[]) {
    if (argc != ARGS) {
        write(1, ERROR_ARGS, sizeof(ERROR_ARGS));
        return -1;
    }
    FITXER_readConfig(argv[1], &config);
    write(1, SERVER_INIT, strlen(SERVER_INIT));
    if (launch_server(config.port, config.ip, &socket_fd) < 0) {
        write(1, ERROR_MAIN, sizeof(ERROR_MAIN));
        return 0;
    }
    signal(SIGINT, close_server);
    run_server(socket_fd);
    return 0;
}


