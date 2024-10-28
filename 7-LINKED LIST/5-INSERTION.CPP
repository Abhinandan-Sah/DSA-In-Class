#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *head;
//void node *head;
void sorted_list(int item)
{
	struct node *ptr, *prev;
	struct node *p=new struct node;
	if(p==NULL)
	{
		cout<<"Overflow";
		return;
	}
	p->data=item;
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
		cout<<"Node inserted";
		return;
	}
	ptr=head;
	prev=NULL;
	while((ptr!=NULL)&&(item>ptr->data))
	{
		prev=ptr;
		ptr=ptr->next;
	}
	if(prev==NULL)
	{
		p->next=head;
		head=p;
	}
	else
	{
		p->next=ptr;
		prev->next=p;
	}
	cout<<"Node Inserted";
}
void display(struct node *h)
{
	cout<<"\nSorted list is: ";
	while(h!=NULL)
	{
		cout<<h->data<<"->";
		h=h->next;
	}
}
int main(){
	int item,choice;
	do{
		cout<<"\nEnter item: ";
		cin>>item;
		sorted_list(item);
		cout<<"\nEnter O to add more: ";
		cin>>choice;
		if(choice!=0)
		{
			break;
		}
	}while(choice==0);
	display(head);
	return 0;
}