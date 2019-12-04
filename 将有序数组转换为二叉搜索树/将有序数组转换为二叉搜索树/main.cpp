//
//  main.cpp
//  将有序数组转换为二叉搜索树
//
//  Created by Info on 2019/12/4.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
//示例:
//
//给定有序数组: [-10,-3,0,5,9],
//
//一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
//
//0
/// \
//-3   9
///   /
//-10  5

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void contactNode(TreeNode* node, TreeNode* leftNode, TreeNode* rightNode) {
    if (node != nullptr) {
        node->left = leftNode;
        node->right = rightNode;
    }
}

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBST(std::vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> vector = {-10,-3,0,5,9};
    Solution *solution = new Solution();
    TreeNode* node = solution->sortedArrayToBST(vector);
    return 0;
}
