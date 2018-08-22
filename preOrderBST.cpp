#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* treeNode=(struct node*)malloc(sizeof(struct node));
	treeNode->data=data;
	treeNode->left=NULL;
	treeNode->right=NULL;

	return treeNode;
}

struct node* constructTreeUtil(int pre[],int* preIndex,int key,int min,int max,int size)
{
	if(*preIndex > size)
		return NULL;

	struct node* root=NULL;

	if(key>min && key<max)
	{
		root=newNode(key);
		
		*preIndex=*preIndex + 1;

		if(*preIndex<size)
		{
			root->left=constructTreeUtil(pre,preIndex,pre[*preIndex],min,key,size);

			root->right=constructTreeUtil(pre,preIndex,pre[*preIndex],key,max,size);
		}
        
	
	}


	return root;
}

struct node* constructTree(int pre[],int size)
{
	int preIndex=0;

	return constructTreeUtil(pre,&preIndex,pre[0],INT_MIN,INT_MAX,size);
}

void inOrder(struct node* root)
{
	if(root==NULL)
		return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


int main()
{
    int a[]={10,5,1,7,40,50};

    struct node* root=constructTree(a,6);

    inOrder(root);
}