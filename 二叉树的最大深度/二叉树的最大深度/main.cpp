//
//  main.cpp
//  二叉树的最大深度
//
//  Created by Info on 2019/12/3.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//给定一个二叉树，找出其最大深度。
//
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例：
//给定二叉树 [3,9,20,null,null,15,7]，
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回它的最大深度 3 。

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode* node1 = constructNode(3);
    TreeNode* node2 = constructNode(9);
    TreeNode* node3 = constructNode(20);
    TreeNode* node4 = constructNode(15);
    TreeNode* node5 = constructNode(7);

    contactNode(node1, node2, node3);
    contactNode(node3, node4, node5);

    Solution *solution = new Solution();
    int maxDepth = solution->maxDepth(node1);
    std::cout << maxDepth << "\n";
    return 0;
}
