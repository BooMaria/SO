#!/bin/bash

# How to use: call the script as: bash limpiador_de_memoria_v2.sh
# If the memory does not free try passing your username as a parameter:
# bash limpiador_de_memoria_v2.sh user.name

if [ -z $1 ]; then
	ME=`whoami`
else
	ME=$1
fi

MSG='Deleting'

IPCS_S=`ipcs -s | grep $ME | cut -f2 -d" "`
IPCS_M=`ipcs -m | grep $ME | cut -f2 -d" "`
IPCS_Q=`ipcs -q | grep $ME | cut -f2 -d" "`

echo $MSG $ME memory

for id in $IPCS_M;
do
 echo $MSG 'shared memory' $id;
 ipcrm -m $id;
done

for id in $IPCS_S;
do
  echo $MSG 'semaphore' $id;
  ipcrm -s $id;
done

for id in $IPCS_Q;
do
  echo $MSG 'queue' $id;
  ipcrm -q $id;
done

echo 'Done'
