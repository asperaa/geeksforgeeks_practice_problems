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

void printRightView(Node* root)
{
	queue<Node*>q;

	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		//cout<<"yes\n";
		Node* temp=q.front();
		q.pop();

		
		if(temp!=NULL)
		{
			//cout<<"no\n";
			if(q.front()==NULL)
				cout<<temp->data<<" ";

			if(temp->left!=NULL)
				q.push(temp->left);

			if(temp->right!=NULL)
				q.push(temp->right);

		}


		else
		{

		    if(!q.empty())
				q.push(temp);
		}
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

	//root->right->left=newNode(12);
	//root->right->right=newNode(16);
     // root->left->right=newNode(7);   
     printRightView(root);

}