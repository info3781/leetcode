//
//  main.cpp
//  验证回文字符串
//
//  Created by Info on 2019/11/24.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//
//输入: "A man, a plan, a canal: Panama"
//输出: true
//示例 2:
//
//输入: "race a car"
//输出: false

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string::iterator iter = s.begin();
        for (; iter != s.end();) {
            if ((*iter >= 'A' && *iter <= 'Z') || (*iter >= 'a' && *iter <= 'z') || (*iter >= '0' && *iter <= '9')) {
                if (*iter >= 'A' && *iter <= 'Z') {
                    *iter += 32;
                }
                iter++;
            } else {
                s.erase(iter);
            }
        }
        
//        std::transform(s.begin(), s.end(), s.begin(), ::towlower);
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<char> s = {};
    Solution *solution = new Solution();
    bool isPalindrome = solution->isPalindrome("A man, a plan, a canal: Panama");
    printf("%d\n",isPalindrome);
    return 0;
}
