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


void levelOrder(struct node* root)
{
	queue<struct node*>q;

	q.push(root);

	while(!q.empty())
	{
		struct node* temp=q.front();
        
        cout<<temp->data<<" ";
		q.pop();

		if(temp->left!=NULL)
			q.push(temp->left);

		if(temp->right!=NULL)
			q.push(temp->right);
	}
}

int main()
{
	struct node* root=NULL;

	root=newNode(10);
	root->left=newNode(8);
	root->right=newNode(14);

	root->left->left=newNode(6);
	//root->left->right=newNode(9);

	root->left->left->left=newNode(4);
	root->left->left->right=newNode(5);

	root->right->left=newNode(12);
	root->right->right=newNode(16);

	// struct node* ans=search(root,4);

	// if(ans==NULL)
	// 	cout<<"Not found\n";

	// else
	// 	cout<<"found\n";
   levelOrder(root);
}