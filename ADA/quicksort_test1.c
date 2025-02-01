#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int partition(int *A,int low,int high){
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    // swap A[low] and A[j]
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}
void quicksort(int *A,int low,int high){
    int partitionIndex;   //Index of pivot after partition
    if(low<high){
        partitionIndex=partition(A,low,high);
        quicksort(A,low,partitionIndex-1);    //sort left subarray
        quicksort(A,partitionIndex+1,high);  //sort right subarray
    }
}
int main(){
    // int A[]={2,4,3,9,1,4,8,7,5,6};
    // int n=10;
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int A[n],i;
    struct timespec start, end;
    srand(time(NULL));
    for(i=0;i<n;i++){
        A[i]=rand()%100;
    }
    printf("The array is:\n");
    printArray(A,n);
    printf("The quick sort of the array is:\n");
    clock_gettime(CLOCK_MONOTONIC, &start);
    quicksort(A,0,n-1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    printArray(A,n);
    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    printf("\nThe time taken to sort is %lld ns\n", elapsed_ns);

    return 0;
}