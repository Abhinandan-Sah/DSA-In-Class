#include<iostream>
using namespace std;

struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head;
void beg(int item)
{
	struct node *p=new struct node;
	if(p==NULL)
	{
		cout<<"overflow";
		return;
	}
	p->data=item;
	p->next=NULL;
	p->prev=NULL;
	if(head==NULL)
	{
		head=p;
		cout<<"Node Inserted";
		return;
	}
	else
	{
		p->next=head;
		head->prev=p;
		head=p;
		cout<<"Node Inserted";
	}
}

void display(struct node *h)
{
	while(h!=NULL)
	{
		cout<<h->data<<"->";
		h=h->next;
	}
}
int main()
{
	int item, ch;
	do
	{
		cout<<"\nEnter item: ";
		cin>>item;
		beg(item);
		cout<<"\n Enter 0 to add more: ";
		cin>>ch;
		if(ch!=0)
		{
			break;
		}
		}
		while(ch==0);
		display(head);
		return 0;
	}