#include<stdio.h>
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
    int A[]={9,5,7,4,1,0,4,10};
    int n=8;
    printf("The given array is:\n");
    printArray(A,n);
    printf("The Merge sort of the given array is:\n");
    Mergesort(A,0,7);
    printArray(A,n);
    return 0;
}