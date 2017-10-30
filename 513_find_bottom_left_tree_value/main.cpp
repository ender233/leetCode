#include <iostream>
#include "../treeNode.hpp"
#include <cassert>

int maxLevel = 0;
int maxValue = 0;

void findLeftValue(TreeNode *root, int curLevel);
int findBottomLeftValue(TreeNode *root)
{
    findLeftValue(root, 1);
    return maxValue;
}

void findLeftValue(TreeNode *root, int curLevel)
{
    if(root == NULL) return ;
    int curValue = root->val;
    if(curLevel > maxLevel) {
        maxLevel = curLevel;
        maxValue = curValue;
    }

    findLeftValue(root->left, curLevel+1);
    findLeftValue(root->right, curLevel+1);
}

int main() {
    std::vector<int> vec1{1,2,3,4,0,5,6,0,0,0,0,7,0,0,0};
    TreeNode *t = loadTree(vec1);
    //printTreeNode(t);
    assert(findBottomLeftValue(t) == 7);
    return 0;
}