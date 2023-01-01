#include<stdio.h>
#include<conio.h>
#define max 30
int main(){
    int i,j,n,p[max],bt[max],wt[max],tat[max],tp;
    float avg_wt=0,avg_tat=0;
    printf("Enter the number the process :");
    scanf("%d",&n);
    printf("Enter the processes :");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the burst time of the process :");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
               tp=bt[j];
               bt[j]=bt[j+1];
               bt[j+1]=tp;

               tp=p[j];
               p[j]=p[j+1];
               p[j+1]=tp;
            }
        }
    }
    printf("Process\tBust time\t waiting time\t turn around time\n");
    for(int i=0;i<n;i++){
        wt[i] = 0;
        tat[i] = 0;
        for(int j=0;j<i;j++){
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];

        printf("%d\t%d\t\t %d\t\t %d\n",i+1,bt[i],wt[i],tat[i]);

    }
        avg_wt = avg_wt/n;
        avg_tat = avg_tat/n;
        printf("avg waiting time : %f\n",avg_wt);
        printf("avg turn around time : %f\n",avg_tat);
        getch();
}
