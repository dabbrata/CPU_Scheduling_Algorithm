#include<stdio.h>
#include<conio.h>
#define max 10
int main()
{
    int i,j,n,qt,sq=0,cnt=0,r_bt[max],p[max],bt[max],wt[max],tat[max],tmp;
    float avg_wt=0,avg_tat=0;
    printf("Enter the number the process :");
    scanf("%d",&n);

    printf("Enter the burst time of the process :");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
        r_bt[i] = bt[i];
    }

    printf("Enter the quantum number :");
    scanf("%d",&qt);


    while(1)
    {
        for(int i=0;i<n; i++)
        {

            tmp=qt;
            if(r_bt[i] == 0)
            {
                cnt++;
                continue;
            }
            if(r_bt[i] > qt)
            {
                r_bt[i] = r_bt[i] - qt;

            }
            else
            {
                if(r_bt[i] >= 0)
                {
                    tmp=r_bt[i];
                    r_bt[i] = 0;
                }
            }
            sq += tmp;
            tat[i] = sq;
        }
        if(n == cnt)break;
    }
    printf("Process\tBust time\t turn around time\twaiting time\n");

    for(int i=0; i<n; i++)
    {
        wt[i] = tat[i] - bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("%d\t%d\t\t %d\t\t\t%d\n",i+1,bt[i],tat[i],wt[i]);

    }
    avg_wt = avg_wt/n;
    avg_tat = avg_tat/n;
    printf("avg waiting time : %f\n",avg_wt);
    printf("avg turn around time : %f\n",avg_tat);
    getch();
}

