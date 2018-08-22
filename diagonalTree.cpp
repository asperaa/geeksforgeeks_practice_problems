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

void diagonalUtil(Node* root,int d,map<int,vector<int> >& m)
{
	if(root==NULL)
		return;

	m[d].push_back(root->data);

	diagonalUtil(root->left,d+1,m);
	diagonalUtil(root->right,d,m);



}


void diagonal(Node* root)
{
	map<int,vector<int> >m;

	diagonalUtil(root,0,m);

	for(map<int,vector<int> >:: iterator it=m.begin();it!=m.end();++it)
	{
		// for(vector<int>:: iterator itr=it->second.begin();itr!=it->second.end();++itr)
		// 	cout<<*itr<<" ";

		for(int i=0;i<it->second.size();i++)
			cout<<it->second[i]<<" ";
		cout<<endl;
	}
}

int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 

 
    diagonal(root);
 
    return 0;
}