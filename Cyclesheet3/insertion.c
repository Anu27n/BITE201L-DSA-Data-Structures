#include <stdio.h>
#include <stdlib.h>

void Insertion(int A[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
int main()
{
    int n,i;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int A[n];
    printf("Enter %d integers :",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    Insertion(A,n);
    printf("Sorted Array: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

