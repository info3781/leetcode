//
//  main.cpp
//  二叉树的层次遍历
//
//  Created by Info on 2019/12/3.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
//
//例如:
//给定二叉树: [3,9,20,null,null,15,7],
//
//3
/// \
//9  20
///  \
//15   7
//返回其层次遍历结果：
//
//[
// [3],
// [9,20],
// [15,7]
// ]

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        std::vector<TreeNode*> nodeVector;
        std::vector<TreeNode*> tempVector;
        std::vector<int> childVector;
        nodeVector.push_back(root);
        for (int i = 0; i < nodeVector.size(); i++) {
            TreeNode* node = nodeVector[i];
            childVector.push_back(node->val);
            if (node->left != nullptr) {
                tempVector.push_back(node->left);
            }
            if (node->right != nullptr) {
                tempVector.push_back(node->right);
            }
            
            if (i == nodeVector.size() - 1) { //last
                res.push_back(childVector);
                if (tempVector.size() == 0) {
                    break;
                }
                nodeVector = tempVector;
                tempVector.clear();
                childVector.clear();
                i = -1;
            }
        }
        return res;
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
    std::vector<std::vector<int>> res = solution->levelOrder(node1);
    return 0;
}
