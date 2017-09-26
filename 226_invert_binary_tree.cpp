//#define CATCH_CONFIG_MAIN
//#include <catch.hpp>
#include <iostream>
#include "treeNode.hpp"
using namespace std;

TreeNode *invertTree(TreeNode *root)
{
    if(root==NULL) return NULL;
    TreeNode *right = invertTree(root->right);
    TreeNode *left = invertTree(root->left);
    if(right==NULL && left==NULL) return root;

    root->left = right;
    root->right = left;
    return root;
}


int main()
{
    vector<int> vec1{4,2,7,1,3,6,9};
    TreeNode *t1 = loadTree(vec1);
    printTreeNode(t1);
    std::cout<<"\n";
    invertTree(t1);
    printTreeNode(t1);
    std::cout<<"\n";
}
