#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{
    int shmid;
    key_t key = 1234;
    char *shm_ptr;

    /* Create Shared Memory */
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if(shmid < 0)
    {
        printf("Shared Memory Creation Failed\n");
        exit(1);
    }

    /* Attach Shared Memory */
    shm_ptr = (char *)shmat(shmid, NULL, 0);

    if(shm_ptr == (char *)-1)
    {
        printf("Shared Memory Attachment Failed\n");
        exit(1);
    }

    /* Parent Process Writes */
    if(fork() != 0)
    {
        strcpy(shm_ptr, "Hello from Parent Process");
        printf("Parent wrote: %s\n", shm_ptr);

        wait(NULL);
    }
    else
    {
        sleep(1);

        /* Child Process Reads */
        printf("Child read: %s\n", shm_ptr);
    }

    /* Detach Shared Memory */
    shmdt(shm_ptr);

    /* Remove Shared Memory */
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
