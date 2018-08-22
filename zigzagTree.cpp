#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int height(Node* root)
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

Node* newNode(int data)
{
	Node* treeNode=(Node*)malloc(sizeof(Node));

	treeNode->data=data;
	treeNode->left=NULL;
	treeNode->right=NULL;

	return treeNode;
}

void printOddLevel(Node* root,int curH,int h)
{
    if(root==NULL)
    	return;

    if(curH==h)
    {
    	cout<<root->data<<" ";
    	return;
    }

    printOddLevel(root->left,curH+1,h);
    printOddLevel(root->right,curH+1,h);
    


}

void printEvenLevel(Node* root,int curH,int h)
{
    if(root==NULL)
    	return;

    if(curH==h)
    {
    	cout<<root->data<<" ";
    	return;
    }

    printEvenLevel(root->right,curH+1,h);
    printEvenLevel(root->left,curH+1,h);


    

    
}


void printZigzag(Node* root)
{
	int h=height(root);

	for(int i=1;i<=h;i++)
	{
		if(i%2==1)
			printOddLevel(root,1,i);
		else
			printEvenLevel(root,1,i);
	}
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

    printZigzag(root);

}

