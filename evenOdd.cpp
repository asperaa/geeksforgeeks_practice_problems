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
    
    struct node* temp=head;
	
	while(temp->next!=NULL)
		temp=temp->next;

	temp->next=newNode;

	return *refHead;

}


struct node* reverse(struct node** refHead)
{
	struct node* prevNode=NULL;
	struct node* curNode=*refHead;
	struct node* temp=NULL;

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


struct node* arrange(struct node** refHead)
{
	if(*refHead==NULL)
		return NULL;
	
	struct node* oddHead=*refHead;
	struct node* evenHead=(*refHead)->next;
    
    struct node* oddPtr=oddHead;
    struct node* evenPtr=evenHead;

 
    struct node* ptr=NULL;

    if(evenPtr==NULL)
    	return *refHead;

    ptr=evenPtr->next;

    while(1)
    {
    	oddPtr->next=ptr;
    	oddPtr=oddPtr->next;
        
        if(ptr==NULL)
        	break;
    	ptr=ptr->next;

    	evenPtr->next=ptr;
    	evenPtr=evenPtr->next;

    	if(ptr==NULL)
    		break;
    	ptr=ptr->next;
    }

    if(oddPtr!=NULL)
    	oddPtr->next=NULL;
    
    if(evenPtr!=NULL)
    	evenPtr->next=NULL;
    
 
    evenHead=reverse(&evenHead);

    struct node* temp=oddHead;

    while(temp->next!=NULL)
    	temp=temp->next;

    temp->next=evenHead;

    *refHead=oddHead;

    return *refHead;

 }

void printList(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}

}

int main()
{
	struct node* head=NULL;

	head=push(&head,1);
	head=push(&head,2);
	head=push(&head,3);
	head=push(&head,4);
	head=push(&head,5);
    head=push(&head,6);

	//head=reverse(&head);
    
    head=arrange(&head);

	printList(head);





}