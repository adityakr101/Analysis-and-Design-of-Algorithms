#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void selectionsort(int *A, int n)
{
    int indexofMin, temp;
    printf("The selection sort of the given array is:\n");
    for (int i = 0; i < n - 1; i++)
    {
        indexofMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexofMin])
            {
                indexofMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexofMin];
        A[indexofMin] = temp;
    }
}
int main()
{
    int A[] = {10, 5, 13, 45, 6, 0};
    int n = 6;
    printf("The given array is:\n");
    printArray(A, n);
    selectionsort(A, n);
    printArray(A, n);
    return 0;
}