#include <bits/stdc++.h>

 struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
       };
 
 
vector<int> printGivenLevel(TreeNode* root, int level,vector<int>v)
{
    if (root == NULL)
        return v;
    if (level == 1)
    {
        v.push_back(root->val);
        return v;
    }
    
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1,v);
        printGivenLevel(root->right, level-1,v);
    }
}

int height(TreeNode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

vector<vector<int>> printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    
    vector<vector<int>>v;
    vector<int>t;
    for (i=1; i<=h; i++)
    {
        
        t.clear();
        v.push_back(printGivenLevel(root, i,t));
        
    }   
        return v;
}


vector<vector<int> > Solution::levelOrder(TreeNode* A) {

  printLevelOrder(A);

}

int main()
{
    struct node* root=NULL;

    root=newNode(10);
    root->left=newNode(8);
    root->right=newNode(14);

    root->left->left=newNode(6);
    //root->left->right=newNode(9);

    root->left->left->left=newNode(4);
    root->left->left->right=newNode(5);

    root->right->left=newNode(12);
    root->right->right=newNode(16);

}
