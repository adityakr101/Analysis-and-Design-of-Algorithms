#include<stdio.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void bubblesort(int *A,int n){
    int temp;
    int issorted=0;
    printf("The bubble sort of the given array is:\n");
    for(int i=0;i<n-1;i++){
         printf("working no of pass %d\n",i+1);
         issorted=1;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                issorted=0;
            }
        }
        if(issorted){
            return;
        }
    }
}
int main(){
    int A[]={12,23,45,6,8,9,0};
    int n=7;
    printf("The given array is:\n");
    printArray(A,n);
    bubblesort(A,n);
    printArray(A,n);
    return 0;
}