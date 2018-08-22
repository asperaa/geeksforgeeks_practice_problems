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


long long ans(vector<int> a,int n)
{
	long long num=1;
	long long ten=1;
	long long final=0;

	for(int i=n-1;i>=0;i--)
	{
		num=a[i]*ten;
		final=final+num;
		ten=ten*10;
	}

	return final;
}



long long sumNum(Node* root)
{
	vector<vector<int> >all;
	vector<int>cur;

	number(all,cur,root);

	
    
    long long sum=0;
	for(long long i=0;i<all.size();i++)
		sum+=ans(all[i],all[i].size());
	

	return sum;

}


int main()
{
	Node* root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(5);

    root->right->right=newNode(4);
    root->left->right=newNode(5);

    root->left->left=newNode(2);

    root->left->right->right=newNode(4);
    root->left->right->left=newNode(7);

    cout<<sumNum(root);



}