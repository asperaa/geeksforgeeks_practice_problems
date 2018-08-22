#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* nextright;
};

Node* newNode(int data)
{
	Node* treeNode=(Node*)malloc(sizeof(Node));

	treeNode->data=data;
	treeNode->left=NULL;
	treeNode->right=NULL;

	return treeNode;
}

Node* getnextRight(Node* p)
{
	Node* temp=p;

	while(temp!=NULL)
	{
		if(temp->left!=NULL)
			return temp->left;

		if(temp->right!=NULL)
			return temp->right;

		temp=temp->nextright;
	}

	return NULL;
}


void connect(struct node* p)
{
	Node* temp;

	if(!p)
		return ;

	p->nextright=NULL;


    while(p!=NULL)
    {
    	Node* q=p;

    	while(q!=NULL)
    	{
    		if(q->left)
    		{
    			if(q->right)
    				q->left->nextright=q->right;

    			else
    				q->left->nextright=getnextRight(q);
    		}

    		if(q->right)
    			q->right=getnextRight(q->right);


    		q=q->nextright;
    	}


    	if(p->left)
    		p=p->left;

    	else if(p->right)
    		p=p->right;
    	else
    		p=getnextRight(p);
    }

}




