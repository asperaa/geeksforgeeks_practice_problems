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


void printLeftView(Node* root)
{
	queue<Node*>q;

	q.push(root);
	q.push(NULL);
	cout<<q.front()->data<<" ";

	while(!q.empty())
	{
		//cout<<"yes\n";
		Node* temp=q.front();
		q.pop();

		
		if(temp!=NULL)
		{
			//cout<<"no\n";
			

			if(temp->left!=NULL)
				q.push(temp->left);

			if(temp->right!=NULL)
				q.push(temp->right);

		}


		else
		{

		    if(!q.empty())
		    {
		    	cout<<q.front()->data<<" ";
				q.push(temp);
		    }
		}
	}
}


int main()
{
	Node* root=NULL;

	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);

	//root->left->left=newNode(6);
	root->left->right=newNode(4);

//	root->left->left->left=newNode(4);
	root->left->right->right=newNode(5);

	//root->right->left=newNode(12);
	//root->right->right=newNode(16);
     root->left->right->right->right=newNode(6);   
     printLeftView(root);

}