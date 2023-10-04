//queue using linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void insertion(void);
void deletion(void);
void display(void);
struct node
{
int data;
struct node *next;
};struct node
*nw,*front,*rear,*temp;
void main()
{
int choice;
nw=((struct node*)malloc(sizeof(struct node)));
nw->data=0;
nw->next=NULL;
front=nw;
rear=nw;
do
{
printf("\n1.insertion\n2.deletion\n3.display");
printf("\nenter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
insertion();
break;
case 2:
deletion();
break;
case 3:
display();
break;
}}while(choice<4);
getch();
}
void insertion()
{
int item;
printf("\nenter the item");
scanf("%d",&item);
if(rear->data==0)
rear->data=item;
else
{
nw=((struct node*)malloc(sizeof(struct node)));
nw->data=item;
nw->next=NULL;
rear->next=nw;
rear=nw;
}}
void deletion()
{
if(rear->data==0)
printf("\nqueue empty");
else if(front!=rear)
front=front->next;
else
rear->data=0;
}
void display()
{
if(rear->data==0)
printf("\nqueue empty");
else
{
temp=front;
while(temp!=NULL)
{
printf("\t%d",temp->data);
temp=temp->next;
}}}
