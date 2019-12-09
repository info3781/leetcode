//
//  main.cpp
//  最小栈
//
//  Created by Info on 2019/12/9.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>

//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) -- 将元素 x 推入栈中。
//pop() -- 删除栈顶的元素。
//top() -- 获取栈顶元素。
//getMin() -- 检索栈中的最小元素。
//示例:
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.

class MinStack {
    public:
    /** initialize your data structure here. */
    std::stack<int> stack;
    std::stack<int> minstack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        this->stack.push(x);
        int min = this->minstack.empty() ? x : std::min(x, this->minstack.top());
        this->minstack.push(min);
    }
    
    void pop() {
        this->minstack.pop();
        this->stack.pop();
    }
    
    int top() {
        return this->stack.top();
    }
    
    int getMin() {
        return this->minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, const char * argv[]) {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    int min = minStack->getMin();   // --> 返回 -3.
    std::cout << min << std::endl;
    minStack->pop();
    int top = minStack->top();      // --> 返回 0.
    std::cout << top << std::endl;
    min = minStack->getMin();   // --> 返回 -2.
    std::cout << min << std::endl;
    return 0;
}

