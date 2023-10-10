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

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    struct Array arr1;
    int i, key;

    printf("Enter the length of the array (up to 10): ");
    scanf("%d", &arr1.length);

    if (arr1.length > 10 || arr1.length < 1)
    {
        printf("Invalid length. Please enter a length between 1 and 10.\n");
        return 1;
    }

    printf("Enter %d sorted elements for the array:\n", arr1.length);
    for (i = 0; i < arr1.length; i++)
    {
        scanf("%d", &arr1.A[i]);
    }
    arr1.size = 10;

    printf("Enter the value to search for: ");
    scanf("%d", &key);

    int result = BinarySearch(arr1, key);

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

