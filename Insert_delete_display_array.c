#include <stdio.h>
void main()
{
    int arr[100];
    int n, p, v;
    int c;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the elements: ");
        scanf("%d", &arr[i]);
    }
cs:
    printf("\n Choose Your Desired Operation - \n Press 1 to Insert. \n Press 2 to Delete. \n Press 3 to Display.\n");
    printf("Your C:-->");
    scanf("%d", &c);
    switch (c)
    {
    case 1: // insertion
        int num, index;
        printf("Enter The Element You Want to Enter:\n");
        scanf("%d", &num);
        printf("Enter The index where You Want to Enter:\n");
        scanf("%d", &index);
        for (int i = n; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = num;
        n++;
        goto cs;
    case 2: // deletion
        int index1;
        printf("Enter The index which You Want to delete:\n");
        scanf("%d", &index1);
        for (int i = index1; i <= n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
        goto cs;
    case 3: // display
        printf("The Output Array: {");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("}");
    }
}