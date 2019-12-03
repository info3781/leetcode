//
//  main.cpp
//  对称二叉树
//
//  Created by Info on 2019/12/3.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//给定一个二叉树，检查它是否是镜像对称的。
//
//例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//
//1
/// \
//2   2
//\   \
//3    3
//说明:
//
//如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root != nullptr && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }
        if ((node1 == nullptr && node2 != nullptr) || (node1 != nullptr && node2 == nullptr)) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode* node1 = constructNode(1);
    TreeNode* node2 = constructNode(2);
    TreeNode* node3 = constructNode(2);
    TreeNode* node4 = constructNode(3);
    TreeNode* node5 = constructNode(3);
    
    contactNode(node1, node2, node3);
    contactNode(node2, nullptr, node4);
    contactNode(node3, nullptr, node5);
    
    Solution *solution = new Solution();
    bool isSymmetric = solution->isSymmetric(node1);
    std::cout << isSymmetric << "\n";
    return 0;
}
