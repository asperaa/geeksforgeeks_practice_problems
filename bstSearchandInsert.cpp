#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* treeNode=(struct node*)malloc(sizeof(struct node));

	treeNode->data=data;
	treeNode->left=NULL;
	treeNode->right=NULL;

	return treeNode;
}

struct node* search(struct node* root,int data)
{
	if(root==NULL)
		return NULL;

	else if(root->data==data)
		return root;

	else if(data < root->data)
		return search(root->left,data);

	else if(data > root->data)
		return search(root->right,data);


}

struct node* insert(struct node* root,int data)
{
	if(root==NULL)
		return newNode(data);

	else if(data < root->data)
		root->left=insert(root->left,data);

	else if(data > root->data)
		root->right=insert(root->right,data);


	return root;
}



void inOrder(struct node* root)
{
	if(root==NULL)
		return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}




int main()
{
	struct node* root=NULL;

	root=newNode(10);
	root->left=newNode(8);
	root->right=newNode(14);

	root->left->left=newNode(6);
	root->left->right=newNode(9);

	root->left->left->left=newNode(4);
	root->left->left->right=newNode(5);

	root->right->left=newNode(12);
	root->right->right=newNode(16);

	// struct node* ans=search(root,4);

	// if(ans==NULL)
	// 	cout<<"Not found\n";

	// else
	// 	cout<<"found\n";
    inOrder(root);
    cout<<"After\n";
    root=insert(root,3);
    inOrder(root);
}