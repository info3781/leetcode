//
//  main.cpp
//  删除链表中的节点
//
//  Created by Info on 2019/11/29.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
//
//现有一个链表 -- head = [4,5,1,9]，它可以表示为:
//
//
//
//
//
//示例 1:
//
//输入: head = [4,5,1,9], node = 5
//输出: [4,1,9]
//解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
//示例 2:
//
//输入: head = [4,5,1,9], node = 1
//输出: [4,5,9]
//解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
//
//
//说明:
//
//链表至少包含两个节点。
//链表中所有节点的值都是唯一的。
//给定的节点为非末尾节点并且一定是链表中的一个有效节点。
//不要从你的函数中返回任何结果。

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
    void deleteNode(ListNode* node) {
        ListNode* dnode = node->next;
        
        node->val = node->next->val;
        node->next = node->next->next;
        
        delete dnode;
        dnode = nullptr;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* node1 = constructNode(4);
    ListNode* node2 = constructNode(5);
    ListNode* node3 = constructNode(1);
    ListNode* node4 = constructNode(9);
    contactNode(node1, node2);
    contactNode(node2, node3);
    contactNode(node3, node4);
    
    Solution *solution = new Solution();
    solution->deleteNode(node2);
    return 0;
}
