//
//  main.cpp
//  有效的括号
//
//  Created by Info on 2019/12/12.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <stack>

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//
//示例 1:
//
//输入: "()"
//输出: true
//示例 2:
//
//输入: "()[]{}"
//输出: true
//示例 3:
//
//输入: "(]"
//输出: false
//示例 4:
//
//输入: "([)]"
//输出: false
//示例 5:
//
//输入: "{[]}"
//输出: true

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<std::string> stack;
        for (int i = 0; i < s.size(); i++) {
            std::string bracket = s.substr(i, 1);
            if (bracket == "]" || bracket == "}" || bracket == ")") {
                if (stack.size() == 0) { // "]"
                    return false;
                }
                std::string string = stack.top();
                if (bracket == "]") {
                    if (string != "[") {
                        return false;
                    } else {
                        stack.pop();
                    }
                } else if (bracket == "}") {
                    if (string != "{") {
                        return false;
                    } else {
                        stack.pop();
                    }
                } else if (bracket == ")") {
                    if (string != "(") {
                        return false;
                    } else {
                        stack.pop();
                    }
                }
            } else {
                stack.push(bracket);
            }
        }
        // 特判：单边
        if (stack.size() > 0) {
            return false;
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    
    bool isValid = solution->isValid("]");
    std::cout << isValid << std::endl;
    return 0;
}
