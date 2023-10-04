//stack using linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void push(void);
void pop(void);
void display(void);
struct node
{
int data;
struct node *next;
};struct node
*nw,*top,*temp;
void main()
{
int choice;
nw=((struct node*)malloc(sizeof(struct node)));
nw->data=0;
nw->next=NULL;
top=nw;
do
{
printf("\n1.push\n2.pop\n3.display");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
}}while(choice<4);
getch();
}
void push()
{
int item;
printf("\nenter theitem");
scanf("%d",&item);
if(top->data==0)
top->data=item;
else
{
nw=((struct node*)malloc(sizeof(struct node)));
nw->data=item;
nw->next=top;
top=nw;
}}
void pop()
{
if(top->data==0)
printf("\nstack underflow");
else
top=top->next;
}
void display()
{
if(top->data==0)
printf("\nstack empty");
else
{
temp=top;
while(temp!=NULL)
{
printf("\t%d",temp->data)
;
temp=temp->next;
}}}
