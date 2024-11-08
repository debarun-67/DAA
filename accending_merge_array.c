#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void main()
{
    int n, l, arr1[100], arr2[100], outarr[100];
    printf("Enter the size of the 1st array :\t");
    scanf("%d", &n);
    printf("Enter the Elements of the First Array");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the 2nd array:\t ");
    scanf("%d", &l);
    printf("Enter the Elements of the Second Arra : ");
    for (int k = 0; k < l; k++)
    {
        scanf("%d", &arr2[k]);
    }
    for (int i = 0; i < n + l; i++)
    {
        if (i < n)
        {
            outarr[i] = arr1[i];
        }
        else
        {
            outarr[i] = arr2[i - n];
        }
    }
    printf("The Merged Array is:{");
    for (int i = 0; i < n + l; i++)
    {
        printf("%d ", outarr[i]);
    }
    printf("}\n");
    sort(outarr, n + l);
    printf("Sorted array in ascending order:{ ");
    for (int i = 0; i < n + l; i++)
    {
        printf("%d ", outarr[i]);
    }
    printf("}\n");
}