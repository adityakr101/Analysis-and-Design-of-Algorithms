#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int Maximum(int A[],int n){
    int Max=INT_MIN;
    for(int i=0;i<n;i++){
        if(Max<A[i]){
            Max=A[i];
        }
    }
    return Max;
}
void countsort(int *A,int n){
    int i,j;
    // find the Maximum element in A
    int Max=Maximum(A,n);
    // create the count array
    int* count=(int *)malloc((Max+1)*sizeof(int));
    // initialize the array element to 0
    for(i=0;i<Max+1;i++){
        count[i]=0;
    }
    // increment the corresponding index in the count array
    for(i=0;i<n;i++){
        count[A[i]]=count[A[i]]+1;
    }
    i=0;  //counter for count array
    j=0;  //counter for given array A
    while(i<=Max){
        if(count[i]>0){
            A[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
}
int main(){
    int A[]={9,1,4,14,4,15,6};
    int n=7;
    printf("The given array is:\n");
    printArray(A,n);
    printf("The count sort of the given array is:\n");
    countsort(A,n);
    printArray(A,n);
    return 0;
}