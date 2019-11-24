//
//  main.cpp
//  字符串中的第一个唯一字符
//
//  Created by Info on 2019/11/24.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
//
//案例:
//
//s = "leetcode"
//返回 0.
//
//s = "loveleetcode",
//返回 2.
//
//
//注意事项：您可以假定该字符串只包含小写字母。

class Solution {
public:
    int firstUniqChar(std::string s) {
        int firstUniqChar = -1;
        std::map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] == 1) {
                firstUniqChar = i;
                break;
            }
        }
        return firstUniqChar;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<char> s = {};
    Solution *solution = new Solution();
    int firstUniqChar = solution->firstUniqChar("leetcode");
    printf("%d\n",firstUniqChar);
    return 0;
}
