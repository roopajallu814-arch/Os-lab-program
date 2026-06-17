#include <stdio.h>

int main()
{
    int n, tq, i, time = 0, remain;
    int bt[10], rt[10];
    float wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    i = 0;

    while(remain != 0)
    {
        if(rt[i] <= tq && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;

            printf("P%d\t\t%d\t\t%d\n",
                   i + 1,
                   time,
                   time - bt[i]);

            tat += time;
            wt += time - bt[i];
            remain--;
        }
        else if(rt[i] > 0)
        {
            rt[i] -= tq;
            time += tq;
        }

        if(i == n - 1)
            i = 0;
        else
            i++;
    }

    printf("\nAverage Turnaround Time = %.2f", tat / n);
    printf("\nAverage Waiting Time = %.2f\n", wt / n);

    return 0;
}
