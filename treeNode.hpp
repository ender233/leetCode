#include <iostream>
#include <vector>
#include <array>
#include <prettyprint.hpp>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * help function
 */
void generateTree(TreeNode *root, int curNum, const vector<int> &initVec)
{
    int maxNum = initVec.size();
    int left = curNum * 2 + 1;
    int right = curNum *2 + 2;

    if(left < maxNum && initVec[left]!=0) {
        root->left = new TreeNode(initVec[left]);
        generateTree(root->left, left, initVec);
    }
    if(right < maxNum && initVec[right]!=0) {
        root->right = new TreeNode(initVec[right]);
        generateTree(root->right, right, initVec);
    }
}

TreeNode *loadTree(const vector<int> &initVec)
{
    if(initVec.empty()) return NULL;
    TreeNode *root = new TreeNode(initVec[0]);

    generateTree(root, 0, initVec);
    return root;
}

void printTreeNode(TreeNode *root)
{
    if(root == NULL) return;
    std::cout<<root->val<<" ";

    printTreeNode(root->left);
    printTreeNode(root->right);
}
