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
}

struct node* bstInsert(struct node* root,int data)
{
	if(root==NULL)
		return newNode(data);

	if(data <root->data)
		root->left=bstInsert(root->left,data);

	else if(data >root->data)
		root->right=bstInsert(root->right,data);


	return root;
}


struct node* rangeRemove(struct node* root,int min,int max)
{
	if(root==NULL)
		return NULL;


	if(root->data >=min && root->data <=max)
	{
		root->left=rangeRemove(root->left,min,max);
		root->right=rangeRemove(root->right,min,max);
	}

	else if(root->data < min)
	{
		struct node* temp=root->right;
		delete root;
		return temp;
	}

	else if(root->data > max)
	{
		struct node* temp=root->left;
		delete root;
		return temp;
	}


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

	root=bstInsert(root,6);
	root=bstInsert(root,-13);
	root=bstInsert(root,14);
	root=bstInsert(root,-8);
	root=bstInsert(root,13);
	root=bstInsert(root,15);
	root=bstInsert(root,7);

	inOrder(root);

	root=rangeRemove(root,-10,13);

	cout<<"After\n";

	inOrder(root);




}