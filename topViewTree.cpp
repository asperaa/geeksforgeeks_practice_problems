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


int minDis(Node* root)
{
	if(root==NULL)
		return 0;

	int disL=minDis(root->left)-1;
	int disR=minDis(root->right)+1;

	if(disL < disR)
		return disL;

	else
		return disR; 



}


int maxDis(Node* root)
{
	if(root==NULL)
		return 0;

	int disL=maxDis(root->left)-1;
	int disR=maxDis(root->right)+1;

	if(disL > disR)
		return disL;

	else
		return disR; 



}


void printDis(Node* root,int curDis,int Dis)
{
	if(root==NULL)
		return;
    


    if(curDis==Dis)
    {
    	cout<<root->data<<" ";
    	return;
    }

    printDis(root->left,curDis-1,Dis);
    printDis(root->right,curDis+1,Dis);


}


void printVertical(Node* root)
{
	int minn=minDis(root)+1;
	int maxx=maxDis(root)-1;
   
	for(int i=minn;i<=maxx;i++)
	{

		printDis(root,0,i);
		
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
    
    printVertical(root);

}