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

	if(data < root->data)
		root->left=bstInsert(root->left,data);

	else if(data > root->data)
		root->right=bstInsert(root->right,data);


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

struct node* insert(int a[],int n)
{
    struct node* root=NULL;

	for(int i=0;i<n;i++)
        root=bstInsert(root,a[i]);

    return root;
}

int main()
{
    int a[]={10,5,1,7,40,50};

    struct node* root=insert(a,6);

    inOrder(root);
}