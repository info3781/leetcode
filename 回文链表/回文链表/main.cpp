//
//  main.cpp
//  回文链表
//
//  Created by Info on 2019/12/2.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//请判断一个链表是否为回文链表。
//
//示例 1:
//
//输入: 1->2
//输出: false
//示例 2:
//
//输入: 1->2->2->1
//输出: true
//进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

struct ListNode {
    int val;
    ListNode *next;
};

ListNode* constructNode(int val) {
    ListNode* node = new ListNode();
    node->next = nullptr;
    node->val = val;
    return node;
}

void contactNode(ListNode* node, ListNode* nextNode) {
    if (node != nullptr) {
        node->next = nextNode;
    }
}

bool compareFunc (ListNode* l1, ListNode* l2) {
    return l1->val < l2->val;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        
        std::vector<ListNode*> vector;
        ListNode* node = head;
        while (node != nullptr) {
            vector.push_back(node);
            node = node->next;
        }
        
        for (int i = 0; i < vector.size() / 2; i++) {
            if (vector[i]->val != vector[vector.size() - i - 1]->val) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* node1 = constructNode(1);
    ListNode* node2 = constructNode(2);
    ListNode* node3 = constructNode(2);
    
    ListNode* node4 = constructNode(1);
   
    
    contactNode(node1, node2);
    contactNode(node2, node3);
    contactNode(node3, node4);
//    contactNode(node5, node6);

    Solution *solution = new Solution();
    bool isPalindrome = solution->isPalindrome(node1);
    return 0;
}
