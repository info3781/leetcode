//
//  main.cpp
//  环形链表
//
//  Created by Info on 2019/12/2.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//给定一个链表，判断链表中是否有环。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
//
//
//
//示例 1：
//
//输入：head = [3,2,0,-4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//
//示例 2：
//
//输入：head = [1,2], pos = 0
//输出：true
//解释：链表中有一个环，其尾部连接到第一个节点。
//
//
//示例 3：
//
//输入：head = [1], pos = -1
//输出：false
//解释：链表中没有环。
//
//
//
//
//进阶：
//
//你能用 O(1)（即，常量）内存解决此问题吗？

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        ListNode* node1 = head;
        ListNode* node2 = nullptr;
        if (head->next != nullptr) {
            node2 = head->next->next;
        }

        while (node1 != nullptr && node2 != nullptr) {
            if (node1 == node2) {
                return true;
            }
                
            node1 = node1->next;
            if (node2->next != nullptr) {
                node2 = node2->next->next;
            } else {
                return false;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* node1 = constructNode(1);
//    ListNode* node2 = constructNode(2);
//    ListNode* node3 = constructNode(0);
//    ListNode* node4 = constructNode(-4);
   
    
    contactNode(node1, node1);
//    contactNode(node2, node1);
//    contactNode(node3, node4);
//    contactNode(node4, node2);

    Solution *solution = new Solution();
    bool hasCycle = solution->hasCycle(nullptr);
    return 0;
}
