#include<stdio.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void selectionsort(int *A,int n){
    int indexofMin,temp;
    printf("The selection sort of the given array is:\n");
    for(int i=0;i<n-1;i++){
        indexofMin=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[indexofMin]){
                indexofMin=j;
            }
        }
        // swap A[i] and A[indexofMin]
        temp=A[i];
        A[i]=A[indexofMin];
        A[indexofMin]=temp;
    }
}
int main(){
    // if the array size is n then the no. of pass is n-1!
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After the first pass
    //  00  01  02  03  04
    // 02, |05, 03, 13, 12

    // After the second pass
    //  00  01  02  03  04
    // 02, 03, |05, 13, 12

    // After the third pass
    //  00  01  02  03  04
    // 02, 03, 05, |13, 12

    // After the fourth pass
    //  00  01  02  03  04
    // 02, 03, 05, 12, |13

    // int A[]={3,5,2,13,12};
    // int n=5;
    int n;
    printf("Enter the array size:\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("The given array is:\n");
    printArray(A,n);
    selectionsort(A,n);
    printArray(A,n);
    return 0;
}