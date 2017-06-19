#define CATCH_CONFIG_MAIN
#include <catch.hpp>
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

/*
 * Algorithm: DFS ; for the element of rightest view, it will be traversed latest in the same layer. so just replace the old one in the same layer.
 * Data structure: array<> fill
 */
array<int, 1024> arr;
void insertNode(TreeNode *curNode, int d)
{
    if(curNode == NULL) return;
    arr[d] = curNode->val;

    insertNode(curNode->left, d+1);
    insertNode(curNode->right, d+1);
}

vector<int> rightSideView(TreeNode *root)
{
    arr.fill(-1);
    insertNode(root, 0);

    vector<int> resVec;
    for(auto a : arr) {
        if(a != -1) resVec.push_back(a);
        else break;
    }
    return resVec;
}

TEST_CASE("", "")
{
    vector<int> vec1{1, 2, 3, 0, 5, 0, 4};
    TreeNode *root1 = loadTree(vec1);
    printTreeNode(root1);
    vector<int> res1{1, 3, 4};
    REQUIRE(res1 == rightSideView(root1));
}
