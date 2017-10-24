
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch.hpp>
#include <vector>
#include "../treeNode.hpp"

bool hasPathSum(TreeNode *root, int sum)
{
    if(root==NULL) return false;

    //if(root->val > sum) return false;
    if(root->val == sum && root->left==NULL && root->right==NULL) return true;

    return hasPathSum(root->left, sum-root->val)
            || hasPathSum(root->right, sum-root->val);
}

TEST_CASE("", "")
{
    //std::vector<int> vec1{5,4,8,11,0,13,4,7,2,0,0,0,1};
    std::vector<int> vec1{1,2};
    TreeNode *root = loadTree(vec1);
    REQUIRE(!hasPathSum(root, 1));

    std::vector<int> vec2{1};
    TreeNode *root2 = loadTree(vec2);
    REQUIRE(hasPathSum(root2, 1));
}
