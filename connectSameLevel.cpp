#include <bits/stdc++.h>
struct Node{
	int data;
	Node* left;
	Node* right;
	Node* nextRight;
};

void connect(Node* root)
{
	queue<Node*>q;

	q.push(root);
    q.push(NULL);

	while(!q.empty())
	{
		Node* temp=q.front();
		q.pop();

		if(temp!=NULL)
		{
			if(temp->left!=NULL)
				q.push(temp->left);

			if(temp->right!=NULL)
				q.push(temp->right);

			temp->nextRight=q.front();

		}


		else if(temp==NULL && !q.empty())
			q.push(temp);

		


	}

}