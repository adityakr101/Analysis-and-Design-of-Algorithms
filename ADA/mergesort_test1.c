#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void Merge(int A[],int mid,int low,int high){
    int i,j,k,B[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high){
        B[k]=A[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        A[i]=B[i];
    }
}
void Mergesort(int A[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        Mergesort(A,low,mid);      //Mergesort for left half of array
        Mergesort(A,mid+1,high);   //Mergesort for right half of array
        Merge(A,mid,low,high);
    }
}
int main(){
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int A[n],i;
    struct timespec start, end;
    srand(time(NULL));
    for(i=0;i<n;i++){
        A[i]=rand()%100;
    }
    printf("The given array is:\n");
    printArray(A,n);
    printf("The Merge sort of the given array is:\n");
     clock_gettime(CLOCK_MONOTONIC, &start);
    Mergesort(A,0,n-1);
     clock_gettime(CLOCK_MONOTONIC, &end);
    printArray(A,n);
    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    printf("\nThe time taken to sort is %lld ns\n", elapsed_ns);
    return 0;
}