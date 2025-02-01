#include<stdio.h>
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int floyd(int D[10][10],int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
            }
        }
    }
    printf("all pairs shortest path is:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d\t",D[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n,D[10][10];
    printf("Enter the no. of nodes:\n");
    scanf("%d",&n);
    printf("Enter the weighted graph:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&D[i][j]);
        }
    }
    floyd(D,n);
    return 0;
}