//
//  main.cpp
//  反转链表
//
//  Created by Info on 2019/12/1.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//反转一个单链表。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
//进阶:
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        std::vector<ListNode *> vector;
        ListNode* node = head;
        while (node != nullptr) {
            vector.push_back(node);
            node = node->next;
        }
        std::reverse(vector.begin(), vector.end());
        
        ListNode* lastNode = vector.size() > 0 ? vector[0] : nullptr;
        lastNode->next = nullptr;
        for (int i = 1; i < vector.size(); i++) {
            ListNode* node = vector[i];
            lastNode->next = node;
            lastNode = node;
        }
        lastNode->next = nullptr;
        
        return vector.size() > 0 ? vector[0] : nullptr;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* node1 = constructNode(1);
    ListNode* node2 = constructNode(2);
    ListNode* node3 = constructNode(3);
    ListNode* node4 = constructNode(4);
    ListNode* node5 = constructNode(5);

    contactNode(node1, node2);
    contactNode(node2, node3);
    contactNode(node3, node4);
    contactNode(node4, node5);

    Solution *solution = new Solution();
    solution->reverseList(nullptr);
    return 0;
}
