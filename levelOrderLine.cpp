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


void printLevel(Node* root)
{
	if(root==NULL)
		return;


	queue<Node*>q;
	q.push(root);

	

	while(1)
	{
		int nodeCount=q.size();

		if(nodeCount==0)
			break;

		while(nodeCount>0)
		{
			Node* temp=q.front();

			q.pop();
            
            cout<<temp->data<<" ";
			if(temp->left!=NULL)
				q.push(temp->left);

			if(temp->right!=NULL)
				q.push(temp->right);

			nodeCount--;
		}

		cout<<"$"<<" ";

	}
}