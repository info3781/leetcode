//
//  main.cpp
//  验证二叉搜索树
//
//  Created by Info on 2019/12/3.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//给定一个二叉树，判断其是否是一个有效的二叉搜索树。
//
//假设一个二叉搜索树具有如下特征：
//
//节点的左子树只包含小于当前节点的数。
//节点的右子树只包含大于当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。
//示例 1:
//
//输入:
//    2
//   / \
//  1   3
//输出: true
//示例 2:
//
//输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* constructNode(int val) {
    TreeNode* node = new TreeNode();
    node->left = nullptr;
    node->right = nullptr;
    node->val = val;
    return node;
}

void contactNode(TreeNode* node, TreeNode* leftNode, TreeNode* rightNode) {
    if (node != nullptr) {
        node->left = leftNode;
        node->right = rightNode;
    }
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
    // [2147483647] test case
    bool isValidBST(TreeNode* root, long max, long min) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) {
            return false;
        }
        return isValidBST(root->left, root->val, min) && isValidBST(root->right, max, root->val);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode* node1 = constructNode(5);
    TreeNode* node2 = constructNode(1);
    TreeNode* node3 = constructNode(8);
    TreeNode* node4 = constructNode(7);
    TreeNode* node5 = constructNode(9);

    contactNode(node1, node2, node3);
    contactNode(node3, node4, node5);

    Solution *solution = new Solution();
    bool isValidBST = solution->isValidBST(node1);
    std::cout << isValidBST << "\n";
    return 0;
}
