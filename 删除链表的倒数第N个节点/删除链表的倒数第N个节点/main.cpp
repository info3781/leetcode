//
//  main.cpp
//  删除链表的倒数第N个节点
//
//  Created by Info on 2019/11/30.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//
//示例：
//
//给定一个链表: 1->2->3->4->5, 和 n = 2.
//
//当删除了倒数第二个节点后，链表变为 1->2->3->5.
//说明：
//
//给定的 n 保证是有效的。
//
//进阶：
//
//你能尝试使用一趟扫描实现吗？

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        std::vector<ListNode *> vector;
        while (node != nullptr) {
            vector.push_back(node);
            node = node->next;
        }
        n = (int)vector.size() - n;
        ListNode* dnode = vector[n];
        if (n == 0) { // 删除的是head，那么之前head的next成为head
            head = dnode->next;
        } else {
            ListNode* lastNode = vector[n - 1];
            lastNode->next = dnode->next;
        }
        
        delete dnode;
        dnode = nullptr;
        
        return head;
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
    solution->removeNthFromEnd(node1, 5);
    return 0;
}
