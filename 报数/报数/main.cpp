//
//  main.cpp
//  报数
//
//  Created by Info on 2019/11/27.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 被读作  "one 1"  ("一个一") , 即 11。
//11 被读作 "two 1s" ("两个一"）, 即 21。
//21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
//
//给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
//
//注意：整数顺序将表示为一个字符串。
//
//
//
//示例 1:
//
//输入: 1
//输出: "1"
//示例 2:
//
//输入: 4
//输出: "1211"

class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        std::string result = "";
        std::string input = "1";
        bool isFirst = false;
        for (int i = 2; i <= n; i++) {
            if (i > 2) {
                input = result;
            }
            isFirst = false;
            for (int j = 0, k = 0; j < input.length(); j++) {
                if (input[j] == input[j + 1]) {
                    k++;
                } else {
                    if (isFirst == false) {
                        isFirst = true;
                        result = "";
                    }
                    
                    if (k > 0) {
                        char kchar = k + 1 + '0';
                        result = result + kchar + input[j];
                    } else {
                        k = 1;
                        char kchar = k + '0';
                        result = result + kchar + input[j];
                        
                    }
                    k = 0;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution *solution = new Solution();
    std::string countAndSay = solution->countAndSay(5);
    return 0;
}
