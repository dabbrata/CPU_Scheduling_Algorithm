#include<stdio.h>
#include<conio.h>
#define max 30
int main(){
    int i,j,n,burst_time[max],waiting_time[max],turn_arnd_time[max];
    float avg_wt=0,avg_tat=0;
    printf("Enter the number the process :");
    scanf("%d",&n);
    printf("Enter the burst time of the process :");
    for(int i=0;i<n;i++){
        scanf("%d",&burst_time[i]);
    }
    printf("Process\tBust time\t waiting time\t turn around time\n");
    for(int i=0;i<n;i++){
        waiting_time[i] = 0;
        turn_arnd_time[i] = 0;
        for(int j=0;j<i;j++){
            waiting_time[i] += burst_time[j];
        }
        turn_arnd_time[i] = waiting_time[i] + burst_time[i];
        avg_wt = avg_wt + waiting_time[i];
        avg_tat = avg_tat + turn_arnd_time[i];

        printf("%d\t%d\t\t %d\t\t %d\n",i+1,burst_time[i],waiting_time[i],turn_arnd_time[i]);

    }
        avg_wt = avg_wt/n;
        avg_tat = avg_tat/n;
        printf("avg waiting time : %f\n",avg_wt);
        printf("avg turn around time : %f\n",avg_tat);
        getch();
}
