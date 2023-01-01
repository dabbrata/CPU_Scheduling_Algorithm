#include<stdio.h>
#include<conio.h>
#define max 30
int main(){
    int i,j,n,k=1,b=0,min,bt[max],at[max],tmp[max],wt[max],tat[max],pr[max],t;
    float avg_wt=0,avg_tat=0;
    printf("Enter the number the process :");
    scanf("%d",&n);
    printf("Enter the burst time , arrival time and priority of the process :\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&bt[i],&at[i],&pr[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(at[i]<at[j]){
                t=at[j];
                at[j]=at[i];
                at[i]=t;

                t=bt[j];
                bt[j]=bt[i];
                bt[i]=t;
            }
        }
    }

    for(int j=0;j<n;j++){
        b=b+bt[j];
        min=bt[k];
        for(int i=k;i<n;i++){
            min=pr[k];
            if(b>=at[i]){
                if(pr[i]<min){
                    t=at[k];
                    at[k]=at[i];
                    at[i]=t;

                    t=bt[k];
                    bt[k]=bt[i];
                    bt[i]=t;

                    t=pr[k];
                    pr[k]=pr[i];
                    pr[i]=t;
                }
            }
        }
        k++;
    }


    tmp[0]=0;
    printf("Process\tBust time\tArrival time\t Priority \t waiting time\t turn around time\n");
    for(int i=0;i<n;i++){
        wt[i] = 0;
        tat[i] = 0;
        tmp[i+1] = tmp[i] + bt[i];
        wt[i] = tmp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];

        printf("%d\t%d\t\t%d\t\t %d\t\t %d\t\t %d\n",i+1,bt[i],at[i],pr[i],wt[i],tat[i]);

    }
        avg_wt = avg_wt/n;
        avg_tat = avg_tat/n;
        printf("avg waiting time : %f\n",avg_wt);
        printf("avg turn around time : %f\n",avg_tat);
        getch();
}

