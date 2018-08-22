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


Node* bstInsert(Node* root,int data)
{
	if(root==NULL)
		return newNode(data);

	if(data > root->data)
		root->right=bstInsert(root->right,data);
	if(data < root->data)
    	root->left=bstInsert(root->left,data);
   
    return root;

}

bool bstSearch(Node* root,int data)
{
	if(root==NULL)
		return false;

	if(root->data==data)
		return true;

	if(data>root->data)
		return bstSearch(root->right,data);

	if(data<root->data)
		return bstSearch(root->left,data);
}

void inOrder(Node* root)
{
	if(root==NULL)
		return;

	inOrder(root->left);
	
	cout<<root->data<<" ";
	
	inOrder(root->right);

}


void duplet(Node* root,Node** rootRef,int sum,pair<int,int>& ans)
{
	if(root==NULL)
		return;

    
	int comp=sum-root->data;

	if(bstSearch(*rootRef,comp))
	{
		ans=make_pair(comp,root->data);
	}

	duplet(root->left,rootRef,sum,ans);
	duplet(root->right,rootRef,sum,ans);


}

int main()
{
	Node* root=NULL;

	root=bstInsert(root,15);
	root=bstInsert(root,10);
	root=bstInsert(root,20);
	root=bstInsert(root,8);
	root=bstInsert(root,12);
	root=bstInsert(root,16);
	root=bstInsert(root,25);

    //inOrder(root);
    pair<int,int>ans=make_pair(0,0);
    int sum=33;
    duplet(root,&root,sum,ans);

    if(ans.first==0 && ans.second==0)
    	cout<<"Not found\n";

    else
    	cout<<ans.first<<" "<<ans.second;






}