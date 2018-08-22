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


struct node* insert(struct node* root,int data)
{
	if(root==NULL)
		return newNode(data);

	if(data < root->data)
		root->left=insert(root->left,data);

	if(data > root->data)
		root->right=insert(root->right,data);


	return root;
}


struct node* minVal(struct node* root)
{
	struct node* temp=root;
   while(temp->left!=NULL)
   	temp=temp->left;

   return temp;
}



struct node* del(struct node* root,int data)
{

	if(root==NULL)
		return root;

	if(data < root->data)
		root->left=del(root->left,data);

	else if(data > root->data)
		root->right=del(root->right,data);

	else
	{
		if(root->left==NULL)
		{
			struct node* temp=root->right;

			delete root;

			return temp;
		}

		else if(root->right==NULL)
		{
			struct node* temp=root->left;
			
			delete root;

			return temp;
		}


		struct node* succ=minVal(root->right);

		root->data=succ->data;

		root->right=del(root->right,succ->data);
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

	root=newNode(50);
	root->left=newNode(30);
	root->right=newNode(70);

	root->left->left=newNode(20);
	root->left->right=newNode(40);

	root->right->left=newNode(60);
	root->right->right=newNode(80);

    inOrder(root);
    cout<<"after\n";

	root=del(root,20);

	inOrder(root);



}