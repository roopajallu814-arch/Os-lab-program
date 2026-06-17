#include <stdio.h>

int main()
{
    int n, i, time = 0, remain, quantum;
    int bt[20], rt[20];
    float wait_time = 0, tat = 0;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    i = 0;
    while(remain != 0)
    {
        if(rt[i] <= quantum && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            remain--;

            printf("P%d\t\t%d\t\t%d\n",
                   i + 1,
                   time,
                   time - bt[i]);

            tat += time;
            wait_time += time - bt[i];
        }
        else if(rt[i] > 0)
        {
            rt[i] -= quantum;
            time += quantum;
        }

        if(i == n - 1)
            i = 0;
        else
            i++;
    }

    printf("\nAverage Turnaround Time = %.2f",
           tat / n);
    printf("\nAverage Waiting Time = %.2f\n",
           wait_time / n);

    return 0;
}
