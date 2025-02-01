#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n){
    int indexOfMin, temp;
    printf("The selection sort of given array is:\n");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main(){
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    // int A[] = {3, 5, 2, 13, 12};
    // int n = 5;
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int A[n],i;
    struct timespec start, end;
    srand(time(NULL));
    // printf("Enter the element in the array:\n");
    for(i=0;i<n;i++){
        // scanf("%d",&A[i]);
        A[i]=rand()%100;
    }
    printf("The given array is:\n");
    printArray(A, n);
    clock_gettime(CLOCK_MONOTONIC, &start);
    selectionSort(A, n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    printArray(A, n);
    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    printf("\nThe time taken to sort is %lld ns\n", elapsed_ns);


    return 0;
}
