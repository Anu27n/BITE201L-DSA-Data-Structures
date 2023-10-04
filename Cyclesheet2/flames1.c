#include<stdio.h>
#include<stdlib.h>
char a[]="flames";
typedef struct node
{
char data;
struct node *next,*prev;
}node;
node *top=NULL,*temp;
node* ins(char a)
{
struct node *new1;
new1=malloc(sizeof(struct node));
new1->data=a;
new1->next=NULL;
new1->prev=NULL;
if(top==NULL)
{
top=new1;
temp=top;
}
else
{ temp->next=new1;
new1->prev=temp;
temp=new1;
}
return top;
}
void check(int j)
{
int count1,flag=0,i;
for(i=0;a[i]!='\0';i++)
top=ins(a[i]);
struct node *cur=top,*prev1;
temp->next=top;
top->prev=temp;
while(1)
{
count1=1;
while(count1<j)
{
cur=cur->next;
count1++;
}
node *temp1=cur;
prev1=cur->prev;
cur->prev->next=cur->next;
cur->next->prev=cur->prev;
temp1->next=NULL;
free(temp1);
cur=prev1->next;
node *test=cur;
if(test->data==test->next->data)
break;
}
switch(cur->data)
{
case 'f':
printf("FRIENDS&&");
break;
case 'l':
printf("LOVE<3");
break; case 'a':
printf("AFFECTION$");
break;
case 'm':
printf("MARRIAGE:)");
break;
case 'e':
printf("ENEMY:(");
break;
case 's':
printf("SIBLING");
break;
}
}
void omit(char a[])
{
for(int i=0;a[i]!='\0';i++)
{
if(a[i]>='a'&&a[i]<='z')
{}
else if(a[i]>='A'&&a[i]<='Z')
{}
else
a[i]='0';
}
}
int main()
{
char name1[50],name2[50];
int n1,n2;
printf("Enter First Person's Name:");
scanf("%s",name1);
printf("Enter Second Person's Name:");
scanf("%s",name2);
int i,j;
omit(name1);
omit(name2);
for(i=0;name1[i]!='\0';i++) for(j=0;name2[j]!='\0';j++)
if((name1[i]==name2[j]||name1[i]==name2[j]+32))
{
name1[i]='0';
name2[j]='0';
break;
}
j=0;
for(i=0;name1[i]!='\0';i++)
if(name1[i]!='0')
j++;
for(i=0;name2[i]!='\0';i++)
if(name2[i]!='0')
j++;
if(j==0)
printf("NO FLAMES");
else
check(j);
}
