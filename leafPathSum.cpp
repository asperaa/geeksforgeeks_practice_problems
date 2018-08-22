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


void pathSumUtil(Node* root,int curSum,int sum,bool* value)
{
	if(root==NULL)
		return;
    
    curSum=curSum+root->data;

    if(root->left==NULL && root->right==NULL && curSum==sum)
    	*value=true;
    
    	pathSumUtil(root->left,curSum,sum,value);
    
    	pathSumUtil(root->right,curSum,sum,value);
}


bool pathSum(Node* root,int sum)
{
	
	bool value=false;

	pathSumUtil(root,0,sum,&value);

	if(value==true)
		return true;
	else
		return false;
}

int main()
{
    Node* root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(5);

    root->right->right=newNode(4);
    root->left->right=newNode(5);

    root->left->left=newNode(2);

    root->left->right->right=newNode(4);
    root->left->right->left=newNode(7);
   

 
    cout<<pathSum(root,2);
 
    return 0;
}