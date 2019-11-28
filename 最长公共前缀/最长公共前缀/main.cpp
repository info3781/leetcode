//
//  main.cpp
//  最长公共前缀
//
//  Created by Info on 2019/11/28.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//示例 1:
//
//输入: ["flower","flow","flight"]
//输出: "fl"
//示例 2:
//
//输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
//说明:
//
//所有输入只包含小写字母 a-z 。

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string longestCommonPrefixString = "";
        if (strs.size() >= 1) {
            longestCommonPrefixString = strs[0];
        }
        for (int i = 1; i < strs.size(); i++) {
            this->longestCommonPrefixInTwoString(longestCommonPrefixString, strs[i]);
            if (longestCommonPrefixString == "") {
                return "";
            }
        }
        
        return longestCommonPrefixString;
    }
    
    void longestCommonPrefixInTwoString(std::string &str1, std::string str2) {
        std::string baseString = str1.length() < str2.length() ? str1 : str2;
        int num = 0;
        for (int i = 0; i < baseString.length(); i++) {
            if (str1[i] == str2[i]) {
                num++;
            } else {
                break;
            }
        }
        std::string longestCommonPrefix = num > 0 ? str1.substr(0, num) : "";
        str1 = longestCommonPrefix;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<std::string> strs = {"dog"};
    Solution *solution = new Solution();
    std::string longestCommonPrefix = solution->longestCommonPrefix(strs);
    std::cout << longestCommonPrefix + "\n";
    return 0;
}
