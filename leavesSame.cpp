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

int height(struct node* root)
{
	if(root==NULL)
		return 0;

	int lh=1+height(root->left);
	int rh=1+height(root->right);

	if(lh>rh)
		return lh;
	else
		return rh;
}

bool sameLevel(struct node* root,int curHeight,int height)
{
	if(root->left==NULL && root->right==NULL && curHeight==height)
		return true;
    
    if(root->left==NULL && root->right==NULL && curHeight!=height)
    	return false;
    
    if(root->left!=NULL)
	  sameLevel(root->left,curHeight+1,height);
	if(root->right!=NULL)
	  sameLevel(root->right,curHeight+1,height);



}
int main()
{
	struct node* root=NULL;

	root=newNode(12);
	root->left=newNode(5);
	//root->right=newNode(7);


	root->left->left=newNode(3);
	root->left->right=newNode(9);

	root->left->left->left=newNode(1);

	root->left->right->left=newNode(2);

	//root->left->right->left=newNode(6);
	//root->right->right=newNode(1);
   
    int h=height(root);
    cout<<sameLevel(root,1,h);

}