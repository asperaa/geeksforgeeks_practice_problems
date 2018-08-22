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


Node* bstInsert(Node* root,int data)
{
	if(root==NULL)
		return newNode(data);

	if(data > root->data)
		root->right=bstInsert(root->right,data);
	if(data < root->data)
    	root->left=bstInsert(root->left,data);
   
    return root;

}

bool bstSearch(Node* root,int data)
{
	if(root==NULL)
		return false;

	if(root->data==data)
		return true;

	if(data>root->data)
		return bstSearch(root->right,data);

	if(data<root->data)
		return bstSearch(root->left,data);
}

void inOrder(Node* root)
{
	if(root==NULL)
		return;

	inOrder(root->left);
	
	cout<<root->data<<" ";
	
	inOrder(root->right);

}


void duplet(Node* root,int sum,set<int>& store,pair<int,int>& ans)
{
	if(root==NULL)
		return;

	store.insert(root->data);
    
    if(store.find(sum-root->data)!=store.end())
    {
    	ans=make_pair(root->data,sum-root->data);
    }
	duplet(root->right,sum,store,ans);
	duplet(root->left,sum,store,ans);


}


pair<int,int> dupletFinal(Node* root,int sum)
{
	pair<int,int>ans=make_pair(0,0);
    set<int>store;

    duplet(root,sum,store,ans);

    if(ans.first==0 && ans.second==0)
    {
    	cout<<"Not found\n";
    	return ans;
    }

    else
    {
    	return ans;
    }
}

int main()
{
	Node* root=NULL;

	root=bstInsert(root,15);
	root=bstInsert(root,10);
	root=bstInsert(root,20);
	root=bstInsert(root,8);
	root=bstInsert(root,12);
	root=bstInsert(root,16);
	root=bstInsert(root,25);

    //inOrder(root);
    
    
    
    pair<int,int>ans=dupletFinal(root,100);

    cout<<ans.first<<" "<<ans.second;






}