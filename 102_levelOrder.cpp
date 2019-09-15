#include <iostream>
#include <vector>
#include <map>
#include "treeNode.hpp"
#include "prettyprint.hpp"
using namespace std;

using VecArray=vector<vector<int>>;
VecArray vecs{};

void dfs(TreeNode *root, int level)
{
    if(root == NULL) 
        return;

    if(vecs.size() <= level) {
        vector<int> vec;
        vec.push_back(root->val);
        vecs.push_back(vec);
    }
    else
      vecs[level].push_back(root->val);

    dfs(root->left, level+1);
    dfs(root->right, level+1);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    dfs(root, 0);
    return vecs;
} 

int main()
{
    std::vector<int> vec1{3,9,20,0,0,15,7};
    TreeNode *root = loadTree(vec1);
    VecArray res = levelOrder(root);
    printTreeNode(root);
    std::cout << res << std::endl;
}
