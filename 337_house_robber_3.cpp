#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "listNode.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <set>
#include <unordered_map>
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
 * Algorithm: DP
 */

int rob(TreeNode *root)
{
    if(root == NULL) return 0;
    TreeNode *lef = root->left;
    TreeNode *rig = root->right;
    
    // calc root
    int lefNum =  (lef != NULL) ? (rob(lef->left) + rob(lef->right)) : 0;
    int rightNum = (rig != NULL) ? (rob(rig->left) + rob(rig->right)) : 0;
    int total1 = root->val + lefNum + rightNum;

    // non-calc root
    int total2 =  rob(lef) + rob(rig);

    return std::max(total1, total2);
}

TEST_CASE("", "")
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    int r1 = rob(root);
    REQUIRE(7 == r1);
}


