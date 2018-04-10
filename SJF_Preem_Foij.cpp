#include <stdio.h>

int main()
{
    int arrival_time[10], burst_time[10], temp[10], end;
    int i, smallest, count = 0, time, n,wait_time = 0;

    float average_waiting_time;

    printf("\nEnter the Total Number of Processes:\t");
    scanf("%d", &n);
    printf("\nEnter Details of %d Processes\n", n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time:\t");
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }

    burst_time[n]=9999;
    for(time = 0; count != n; time++)
    {
        smallest = n;
        for(i = 0; i < n; i++)
        {
            if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
            {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if(burst_time[smallest] == 0)
        {
            count++;
            end = time + 1;
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];

        }
    }

    average_waiting_time = wait_time / n;
    printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);

    return 0;
}

