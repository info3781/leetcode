//
//  main.cpp
//  合并两个有序链表
//
//  Created by Info on 2019/12/1.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        
        std::vector<ListNode*> vector;
        while (l1 != nullptr) {
            vector.push_back(l1);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            vector.push_back(l2);
            l2 = l2->next;
        }
        std::sort(vector.begin(), vector.end(), compareFunc);
        
        ListNode* head = vector.size() > 0 ? vector[0] : nullptr;
        ListNode* lastNode = head;
        for (int i = 1; i < vector.size(); i++) {
            lastNode->next = vector[i];
            lastNode = vector[i];
        }
        lastNode->next = nullptr;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* node1 = constructNode(1);
    ListNode* node2 = constructNode(2);
    ListNode* node3 = constructNode(4);
    
    ListNode* node4 = constructNode(1);
    ListNode* node5 = constructNode(3);
    ListNode* node6 = constructNode(4);
    
    contactNode(node1, node2);
    contactNode(node2, node3);
    
    contactNode(node4, node5);
    contactNode(node5, node6);

    Solution *solution = new Solution();
    ListNode* head = solution->mergeTwoLists(nullptr, nullptr);
    return 0;
}
