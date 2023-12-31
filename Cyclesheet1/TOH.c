#include <stdio.h>
//Anubhav Jain
//22BIT0210
void towers(int, char, char, char);

int main()
{
    int num;

    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", frompeg, topeg);
        return;
    }

    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n Move disk %d from tower %c to tower %c", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}
