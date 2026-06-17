#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msgbuf
{
    long mtype;
    char mtext[100];
};

int main()
{
    key_t key;
    int msgid;
    struct msgbuf message;

    key = 1234;

    /* Create Message Queue */
    msgid = msgget(key, 0666 | IPC_CREAT);

    if(msgid == -1)
    {
        printf("Message Queue Creation Failed\n");
        exit(1);
    }

    printf("Enter Message: ");
    fgets(message.mtext, sizeof(message.mtext), stdin);

    message.mtype = 1;

    /* Send Message */
    msgsnd(msgid, &message, sizeof(message.mtext), 0);

    printf("Message Sent: %s", message.mtext);

    /* Receive Message */
    msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);

    printf("Message Received: %s", message.mtext);

    /* Delete Message Queue */
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
