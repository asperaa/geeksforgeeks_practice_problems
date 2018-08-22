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

void leftTraversal(Node* root)
{
	if(root)
	{

		if(root->left==NULL && root->right==NULL)
			return;

		cout<<root->data<<" ";

		if(root->left==NULL && root->right!=NULL)
			leftTraversal(root->right);
		else
			leftTraversal(root->left);
	}
}

void rightTraversal(Node* root)
{
	if(root)
	{	if(root->left==NULL && root->right==NULL)
			return;

		
        if(root->right==NULL && root->left!=NULL)
        	rightTraversal(root->left);
        else
			rightTraversal(root->right);
		
		cout<<root->data<<" ";
	}

}



void leavesAnti(Node* root)
{
	if(root==NULL)
		return;

	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<" ";
	}


	leavesAnti(root->left);
	leavesAnti(root->right);
}

void Boundry(Node* root)
{
	cout<<root->data<<" ";

	leftTraversal(root->left);
	leavesAnti(root);
	rightTraversal(root->right);
}

int main()
{
	Node* root=NULL;

	root=newNode(10);
	root->left=newNode(8);
	root->right=newNode(14);

	root->left->left=newNode(6);
	root->left->right=newNode(9);

	root->left->left->left=newNode(4);
	root->left->left->right=newNode(5);

	root->right->left=newNode(12);
	root->right->right=newNode(16);


    Boundry(root);

}


