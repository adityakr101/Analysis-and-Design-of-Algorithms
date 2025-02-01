#include<stdio.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void insertionsort(int *A,int n){
    int key,j;
    printf("The insertion sort of the given array is:\n");
    for(int i=1;i<=n-1;i++){
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}
int main(){
    int A[]={12,32,23,45,67,98,0};
    int n=7;
    printf("The given array is:\n");
    printArray(A,n);
    insertionsort(A,n);
    printArray(A,n);
    return 0;
}