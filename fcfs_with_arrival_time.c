#include<stdio.h>
#include<conio.h>
#define max 30
int main(){
    int i,j,n,bt[max],at[max],tmp[max],wt[max],tat[max];
    float avg_wt=0,avg_tat=0;
    printf("Enter the number the process :");
    scanf("%d",&n);
    printf("Enter the burst time of the process :");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("Enter the arrival time of the process :");
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    tmp[0]=0;
    printf("Process\tBust time\tArrival time\t waiting time\t turn around time\n");
    for(int i=0;i<n;i++){
        wt[i] = 0;
        tat[i] = 0;
        tmp[i+1] = tmp[i] + bt[i];
        wt[i] = tmp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];

        printf("%d\t%d\t\t%d\t\t %d\t\t %d\n",i+1,bt[i],at[i],wt[i],tat[i]);

    }
        avg_wt = avg_wt/n;
        avg_tat = avg_tat/n;
        printf("avg waiting time : %f\n",avg_wt);
        printf("avg turn around time : %f\n",avg_tat);
        getch();
}

