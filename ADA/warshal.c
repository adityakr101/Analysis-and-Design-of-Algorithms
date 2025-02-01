#include<stdio.h>
void warshal(int adj[10][10],int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j]=(adj[i][j])||(adj[i][k]&&adj[k][j]);
            }
        }
    }
    printf("The transitive closure is:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n,adj[10][10];
    printf("Enter the no. of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    warshal(adj,n);
    return 0;
}