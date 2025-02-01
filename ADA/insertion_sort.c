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
    for(int i=1;i<=n-1;i++){      //loop for pass
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){  //loop for each pass
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}
int main(){
    // -1    0   1   2   3   4   5
    //       12,|54, 65, 07, 23, 09 -->i=1,key=54,j=0
    //       12,|54, 65, 07, 23, 09 -->1st pass done (i=1)!

    //       12, 54,|65, 07, 23, 09 -->i=2,key=65,j=1
    //       12, 54,|65, 07, 23, 09 -->2nd pass done (i=2)!

    //       12, 54, 65,|07, 23, 09 -->i=3,key=7,j=2
    //       12, 54, 65,|65, 23, 09 -->i=3,key=7,j=1
    //       12, 54, 54,|65, 23, 09 -->i=3,key=7,j=0
    //       12, 12, 54,|65, 23, 09 -->i=3,key=7,j=-1
    //       07, 12, 54,|65, 23, 09 -->3rd pass done (i=3)!

    //       07, 12, 54, 65,|23, 09 -->i=4,key=23,j=3
    //       07, 12, 54, 65,|65, 09 -->i=4,key=23,j=2
    //       07, 12, 54, 54,|65, 09 -->i=4,key=23,j=1
    //       07, 12, 23, 54,|65, 09 -->4th pass done (i=4)!

    //       07, 12, 23, 54, 65,|09 -->i=5,key=9,j=4
    //       07, 12, 23, 54, 65,|65 -->i=5,key=9,j=3
    //       07, 12, 23, 54, 54,|65 -->i=5,key=9,j=2
    //       07, 12, 23, 23, 54,|65 -->i=5,key=9,j=1
    //       07, 12, 12, 23, 54,|65 -->i=5,key=9,j=0
    //       07, 09, 12, 23, 54,|65 -->5th pass done (i=5)!

    //       07, 09, 12, 23, 54, 65 -->sorted array
    int A[]={12,54,65,7,23,9};
    int n=6;
    printf("The given array is:\n");
    printArray(A,n);
    insertionsort(A,n);
    printArray(A,n);
    return 0;
    
}