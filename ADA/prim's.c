#include<stdio.h>
int visited[10];
void main(){
    int mincost=0,cost[10][10],n,i,j,ne,a,b,min,u,v;
    printf("Enter the no. of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
        cost[i][j]=999;
    }
    for(i=2;i<=n;i++)
    visited[i]=0;
    visited[1]=1;
    ne=1;
    while(ne<n){
        for(min=999,i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j]<min)
        if(visited[i]==0)
        continue;
        else{
            min=cost[i][j];
            a=u=i;
            b=v=j;
        }
        if(visited[u]==0 || visited[v]==0){
            printf("%dedges(%d,%d)=%d\n",ne++,a,b,min);
            mincost+=min;
            visited[v]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("The minimum cost of spanning tree is:%d\n",mincost);
}