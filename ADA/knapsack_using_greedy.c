#include<stdio.h>
int main(){
    float weight[50],profit[50],ratio[50],totalvalue,temp,capacity,amount;
    int n,i,j;
    printf("Enter the number of items:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the weight and profit for the item[%d]:\n",i);
        scanf("%f%f",&weight[i],&profit[i]);
    }
    printf("Enter the capacity of the knapsack:\n");
    scanf("%f",&capacity);
    for(i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;
            }
        }
    }
    printf("knapsack problem using greedy algorithm:\n");
    for(i=0;i<n;i++){
        if(weight[i]>capacity){
            break;
        }
        else{
            totalvalue+=profit[i];
            capacity-=weight[i];
        }
    }
    if(i<n){
        totalvalue+=(ratio[i]*capacity);
    }
    printf("\n The maximum value is:%f\n",totalvalue);
    return 0;
}