#include<stdio.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void bubblesort(int *A,int n){
    int temp;
    printf("The bubble sort of the given array is:\n");
    for(int i=0;i<n-1;i++){        //for number of pass
        for(int j=0;j<n-1-i;j++){  //for comparison in each pass
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}
int main(){
    int A[]={7,11,9,2,17,4};
    int n=6;
    printf("The given array is:\n");
    printArray(A,n);    //printing the array before sorting
    bubblesort(A,n);    //function to sort the array
    printArray(A,n);    //printing the array after sorting
    return 0;
}