//
//  main.cpp
//  反转字符串
//
//  Created by Info on 2019/11/23.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//
//你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
//
//
//
//示例 1：
//
//输入：["h","e","l","l","o"]
//输出：["o","l","l","e","h"]
//示例 2：
//
//输入：["H","a","n","n","a","h"]
//输出：["h","a","n","n","a","H"]

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            int temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
    }
};

int main(int argc, const char * argv[]) {
    std::vector<char> s = {};
    Solution *solution = new Solution();
    solution->reverseString(s);
    return 0;
}
