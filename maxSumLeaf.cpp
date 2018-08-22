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

void number(vector< vector<int> >&all,vector<int>cur,Node* root)
{
	if(root==NULL)
		return;

	if(root->left==NULL && root->right==NULL)
	{
		cur.push_back(root->data);

		all.push_back(cur);
		
		return;
	}

	cur.push_back(root->data);

	number(all,cur,root->left);
	number(all,cur,root->right);
}

void sumNum(Node* root)
{
	vector<vector<int> >all;
	vector<int>cur;

	number(all,cur,root);

	
    
    vector<int>sum;
	for(int i=0;i<all.size();i++)
		sum.push_back(accumulate(all[i].begin(),all[i].end(),0));
	
    int index=max_element(sum.begin(),sum.end())-sum.begin();
	int maxE=*max_element(sum.begin(),sum.end());

	for(int i=0;i<all[index].size();i++)
		cout<<all[index][i]<<" ";
	cout<<"\n";
	cout<<maxE;

}

int main()
{
	Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);

    root->left->right=newNode(-4);

    root->left->left=newNode(8);

    // root->left->right->right=newNode(4);
    // root->left->right->left=newNode(7);

    sumNum(root);



}