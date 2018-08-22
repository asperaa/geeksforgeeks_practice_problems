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


void maxBendsUtil(Node* root,char dir,int bend,int* maxbends)
{
	if(root==NULL)
		return;

	if(root->left==NULL && root->right==NULL)
	{
		if(bend>*maxbends)
			*maxbends=bend;
	}


	else if(root->left==NULL)
	{
		if(dir=='r')
			maxBendsUtil(root->right,'r',bend,maxbends);
		else
			maxBendsUtil(root->right,'r',bend+1,maxbends);
	}

	else if(root->right==NULL)
	{
		if(dir=='r')
			maxBendsUtil(root->left,'l',bend+1,maxbends);
		else
			maxBendsUtil(root->left,'l',bend,maxbends);
	}
    
    else
    {
       if(dir=='r')
       {
       	 	maxBendsUtil(root->left,'l',bend+1,maxbends);
       	 	maxBendsUtil(root->right,'r',bend,maxbends);
       }

       else
       {
       	   maxBendsUtil(root->right,'r',bend+1,maxbends);
       	   maxBendsUtil(root->left,'l',bend,maxbends);

       }
    }

}


int maxBends(Node* root)
{
	if(root==NULL)
		return 0;

	int maxbends=0;
    int bend=0;
	if(root->left)
		maxBendsUtil(root->left,'l',bend,&maxbends);

	if(root->right)
		maxBendsUtil(root->right,'r',bend,&maxbends);


	return maxbends;
}

int main()
{
	Node* root=NULL;

	root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right=newNode(7);

    root->right->right->left=newNode(9);

    root->right->right->left->left = newNode(12);
    root->right->right->left->right = newNode(10);

    root->right->right->left->right->right=newNode(11);
    root->right->right->left->right->right->left=newNode(45);




	cout<<maxBends(root);
}