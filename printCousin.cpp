#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


Node* newNode(int data)
{
	Node* treeNode=(Node*)malloc(sizeof(Node));
	treeNode->data=data;
	treeNode->left=NULL;
	treeNode->right=NULL;

	return treeNode;
}


int height(Node* root,int data)
{   
	
	if(root==NULL)
	{
		
		return 0;
	}

	if(data < root->data )
		return 1 + height(root->left,data);

	else if(data > root->data )
		return 1 + height(root->right,data);

	else if(data==root->data)
		return 1;
}


void printCousin(Node* root,int data,int heightP,int curheight)
{
	if(root==NULL)
		return;
	if(curheight==heightP)
	{
		if(root->left!=NULL && root->left->data==data)
			return;

		if(root->right!=NULL && root->right->data==data)
			return;
        
        if(root->left!=NULL)
          cout<<root->left->data<<" ";

        if(root->right!=NULL)
        	cout<<root->right->data<<" ";
        
    }

    else
    {
    	
    	printCousin(root->left,data,heightP,curheight+1);
    	printCousin(root->right,data,heightP,curheight+1);
    }


			
	
}

void printCousinFun(Node* root,int data)
{
	int h=height(root,data);
   // cout<<h<<" ";
	printCousin(root,data,h-1,1);




}


int main()
{
	Node* root=NULL;

	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
    
    // cout<<root->left->data<<" ";
	root->left->left=newNode(4);
	root->left->right=newNode(5);

	// root->left->left->left=newNode(4);
	// root->left->left->right=newNode(5);

	root->right->left=newNode(6);
	root->right->right=newNode(7);

	printCousinFun(root,6);
}