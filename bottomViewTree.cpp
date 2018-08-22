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
	int lt=maxDis(root->right)+1;
	int rt=maxDis(root->left)-1;


	if(rt>lt)
		return rt;

	else
		return lt;
}


void bottom(Node* root,int curD,int D,map<int,int>& m)
{
	


	if(root==NULL)
		return;
	

	if(curD==D)
		m[curD]=root->data;
	
	if(root->left!=NULL)
		bottom(root->left,curD-1,D,m);

	if(root->right!=NULL)
		bottom(root->right,curD+1,D,m);
}


void bottomAll(Node* root)
{
    int minD=minDis(root)+1;
    int maxD=maxDis(root)-1;
    
     

    for(int i=minD;i<=maxD;i++)
    {
    	//cout<<"ok\n";
     
        map<int,int>m;
    	bottom(root,0,i,m);
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
	root->right->left=newNode(6);

	root->left->left->right=newNode(8);
	root->right->right=newNode(7);

	bottomAll(root);


}