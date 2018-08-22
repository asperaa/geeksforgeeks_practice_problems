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

	int lt=minDis(root->left)-1;
	int rt=minDis(root->right)+1;

	if(lt<rt)
		return lt;

	else
		return rt;


}


int maxDis(Node* root)
{
	if(root==NULL)
		return 0;


	int lt=maxDis(root->left)-1;
	int rt=maxDis(root->right)+1;

	if(lt>rt)
		return lt;

	else
		return rt;
}


void verSum(Node* root,map<int,int>& m,int curD,int D)
{
	if(root==NULL)
		return;

	if(curD==D)
		m[curD]=m[curD]+root->data;

	verSum(root->left,m,curD-1,D);
	verSum(root->right,m,curD+1,D);


}


void verSumALL(Node* root)
{
	int minD=minDis(root)+1;
	int maxD=maxDis(root)-1;
   
	for(int i=minD;i<=maxD;i++)
	{
		map<int,int>m;
        
		verSum(root,m,0,i);

		cout<<m[i]<<" ";
	}


}

int main()
{
	Node* root=NULL;

	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);

	root->left->left=newNode(4);
	root->left->right=newNode(5);

	root->right->left=newNode(6);
	root->right->right=newNode(7);

	verSumALL(root);
}