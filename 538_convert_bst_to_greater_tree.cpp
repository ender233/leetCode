#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include "treeNode.hpp"
using namespace std;

TreeNode *getNewNode(TreeNode *root, int &num)
{
    if(root->right != NULL) getNewNode(root->right, num);
    num += root->val;
    root->val = num;

    if(root->left != NULL) getNewNode(root->left, num);
    return root;
}
TreeNode *convertBST(TreeNode *root)
{
    if(root == NULL) return NULL;
    int num(0);
    return getNewNode(root, num);
}

/*
 * not recommended
 */
TreeNode *convertBST2(TreeNode *root) {
    static int num = 0;
    if(root == NULL) return root;

    convertBST2(root->right);
    root->val += num;
    num = root->val;
    convertBST2(root->left);
}

TEST_CASE("1", "")
{
    vector<int> vec1{5, 2, 13};
    TreeNode *t1 = loadTree(vec1);
    printTreeNode(t1);

    std::cout<<"\n";
    convertBST(t1);
    printTreeNode(t1);
}

TEST_CASE("2", "")
{
    vector<int> vec2{2,1,3};
    TreeNode *t2 = loadTree(vec2);
    printTreeNode(t2);
    std::cout<<"\n";
    convertBST(t2);
    printTreeNode(t2);
}

/*
TEST_CASE("3", "")
{
    vector<int> vec1{5, 2, 13};
    TreeNode *t1 = loadTree(vec1);
    vector<int> vec2{2,1,3};
    TreeNode *t2 = loadTree(vec2);
    printTreeNode(t2);
    std::cout<<"\n";
    convertBST2(t1);
    convertBST2(t2);
    printTreeNode(t2);
}
*/
