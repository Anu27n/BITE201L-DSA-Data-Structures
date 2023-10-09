#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr1;
    int i;

    printf("Enter the length of the array (up to 10): ");
    scanf("%d", &arr1.length);

    if (arr1.length > 10 || arr1.length < 1)
    {
        printf("Invalid length. Please enter a length between 1 and 10.\n");
        return 1;
    }

    printf("Enter %d elements for the array:\n", arr1.length);
    for (i = 0; i < arr1.length; i++)
    {
        scanf("%d", &arr1.A[i]);
    }
    arr1.size = 10;

    int key;
    printf("Enter the value to search for: ");
    scanf("%d", &key);

    int result = LinearSearch(&arr1, key);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    Display(arr1);
    return 0;
}
