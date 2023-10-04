#include <stdio.h>
#include <stdlib.h>

//ANUBHAV JAIN
//22BIT0210

struct Cqueue {
    int a[5];
    int front;
    int rear;
}cq;


void cqueue_insertion_rear()
{   int item;
    if (cq.front==(cq.rear+1)%5)
        {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter the item:");
        scanf("%d",&item);
        if(cq.rear==-1)
        {
            cq.rear++;
            cq.front++;
            cq.a[cq.rear]=item;
        }
        else
        { cq.rear=((cq.rear+1)%5);
          cq.a[cq.rear]=item;

        }
    }
}

void queue_delete() {
    if (cq.rear == -1) {
        printf("Queue is empty\n");
    }
    else
    {
        if (cq.front == cq.rear)
        {
            cq.front = cq.rear = -1;
        }
        else
        {
            cq.front = ((cq.front+1)%5);
        }
    }
}

void display()
{ int temp;
  if(cq.rear==-1)
    printf("queue empty");
  else
  {
      temp=cq.front;
      while(temp!=cq.rear)
      {
          printf("%d ",cq.a[temp]);
          temp=(temp+1)%5;
      }
      printf("%d ",cq.a[temp]);
  }

}

int main()
{   int choice;
    cq.front = -1;
    cq.rear = -1;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                cqueue_insertion_rear();
                break;
            case 2:
                queue_delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}


