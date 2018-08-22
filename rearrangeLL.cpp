#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* next;
};


struct node* push(struct node** refHead,int data)
{
	struct node* head=*refHead;

    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    
    newNode->data=data;
	newNode->next=NULL;

	if(head==NULL)
	{
		
		head=newNode;

		*refHead=head;

		return *refHead;
	}

	struct node* ptr=head;

	while(ptr->next!=NULL)
		ptr=ptr->next;

	ptr->next=newNode;

	*refHead=head;

	return *refHead;


}

void printList(struct node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
}


struct node* middleNode(struct node** refHead)
{
     struct node* slowptr=*refHead;
     struct node* fastptr=*refHead;

     struct node* prevNode=*refHead;

     while(fastptr->next!=NULL)
     {  
     	prevNode=slowptr;
     	slowptr=slowptr->next;
     	fastptr=fastptr->next->next;

     	if(fastptr==NULL)
           break;


     }
     
     prevNode->next=NULL;


     return slowptr;
}


struct node* reverseLL(struct node** refHead)
{
	struct node* prevNode=NULL;
	struct node* curNode=*refHead;
	struct node* temp=NULL;

    struct node* secondMid=NULL;
   


	while(curNode!=NULL)
	{
		temp=curNode->next;
		curNode->next=prevNode;
		prevNode=curNode;
		curNode=temp;
	}
    
    *refHead=prevNode;

	return *refHead;


}

struct node* altRearrange(struct node* first,struct node* second)
{
	struct node* head=first;
	first=first->next;

	head->next=second;
	second=second->next;
    

    struct node* temp=NULL;
	temp=head->next;


	while(first!=NULL && second!=NULL)
	{
		temp->next=first;
		first=first->next;

		temp=temp->next;
		temp->next=second;

		second=second->next;

		temp=temp->next;
	}

	while(first!=NULL)
	{
		temp->next=first;

		temp=temp->next;

		first=first->next;
	}



	while(second!=NULL)
	{
		temp->next=second;

		temp=temp->next;

		second=second->next;
	}


	return head;

}

int main()
{
	struct node* head=NULL;

	head=push(&head,1);
	head=push(&head,2);
	head=push(&head,3);
	head=push(&head,4);
    //head=push(&head,5);
    
    struct node* first=head;
    struct node* second=middleNode(&head);

    second=reverseLL(&second);

    head=altRearrange(first,second);

    printList(head);



    

}