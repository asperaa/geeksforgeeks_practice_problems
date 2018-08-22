#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Node* newNode(int data)
{
   Node* node=(Node*)malloc(sizeof(Node));
    
   node->data=data;
   node->next=NULL;

   return node;
}

struct Node* insert(Node* head,int data)
{
	Node* temp=newNode(data);

	if(head==NULL)
	{
		head=temp;
		return head;
	}

	
	Node* ptr=head;

	while(ptr->next!=NULL)
		ptr=ptr->next;

	ptr->next=temp;
	

	return head;
}


Node* intersection(Node* headA,Node* headB)
{
	set<int>s;

	Node* tempA=headA;
	Node* tempB=headB;
    

	while(tempA!=NULL)
	{
		s.insert(tempA->data);
		tempA=tempA->next;
	}

	Node* ans=NULL;
	Node* ansPtr=NULL;

	while(tempB!=NULL)
	{
		if(s.find(tempB->data)!=s.end())
		{

			if(ans==NULL)
			{
				ans=newNode(tempB->data);
                ansPtr=ans;
			}

			else
			{
				
				ansPtr->next=newNode(tempB->data);
				ansPtr=ansPtr->next;

			}


		}

		tempB=tempB->next;

	}

	return ans;
}

Node* uni(Node* headA,Node* headB)
{
	set<int>s;

	Node* tempA=headA;
	Node* tempB=headB;

	Node* ans=NULL;
	Node* ansPtr=NULL;


	while(tempA!=NULL)
	{
		s.insert(tempA->data);
	
        

		if(ans==NULL)
		{
			ans=newNode(tempA->data);
			ansPtr=ans;
		}

		else
		{
			ansPtr->next=newNode(tempA->data);
			ansPtr=ansPtr->next;
		}
        
        
		tempA=tempA->next;
	}


	while(tempB!=NULL)
	{
	
		if(s.find(tempB->data)!=s.end())
	    {
	    	tempB=tempB->next;
	    	continue;
	    }
        
        if(ans==NULL)
		{
			ans=newNode(tempB->data);
			ansPtr=ans;
		}

		else
		{
			
			ansPtr->next=newNode(tempB->data);
			ansPtr=ansPtr->next;
		}

		tempB=tempB->next;

	}

	return ans;

}

void printList(Node* head)
{
	Node* temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}


int main()
{
	Node* l1=NULL;
	Node* l2=NULL;

	l1=insert(l1,10);
    l1=insert(l1,15);
    l1=insert(l1,4);
    l1=insert(l1,20);

    l2=insert(l2,8);
    l2=insert(l2,4);
    l2=insert(l2,2);
    l2=insert(l2,10);

    
    cout<<"Intersection\n";
    
    Node* ansI=intersection(l1,l2);

    printList(ansI);
    
    cout<<"\nUnion\n";

    Node* ansU=uni(l1,l2);

    printList(ansU);


}