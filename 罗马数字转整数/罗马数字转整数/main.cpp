//
//  main.cpp
//  罗马数字转整数
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

//罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
//
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
//
//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//
//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
//
//示例 1:
//
//输入: "III"
//输出: 3
//示例 2:
//
//输入: "IV"
//输出: 4
//示例 3:
//
//输入: "IX"
//输出: 9
//示例 4:
//
//输入: "LVIII"
//输出: 58
//解释: L = 50, V= 5, III = 3.
//示例 5:
//
//输入: "MCMXCIV"
//输出: 1994
//解释: M = 1000, CM = 900, XC = 90, IV = 4.

class Solution {
public:
    int specialCase(std::string s) {
        int special = -1; // 默认不是特殊案例
        if (s == "IV") {
            special = 4;
        } else if (s == "IX")  {
            special = 9;
        } else if (s == "XL")  {
            special = 40;
        } else if (s == "XC")  {
            special = 90;
        } else if (s == "CD")  {
            special = 400;
        } else if (s == "CM")  {
            special = 900;
        }
        return special;
    }
    int valueMap(std::string s) {
        std::map<std::string, int> map = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
        };
        return map[s];
    }
    int romanToInt(std::string s) {
        int res = 0;
        for (int start = 0; start < s.size(); start++) {
            int end = start + 1 < s.size() ? (start + 1) : start;
            std::string substring = s.substr(start, end - start + 1);
            int tempValue = specialCase(substring);
            if (tempValue == -1) { // 默认处理，单个
                std::string string = substring.substr(0, 1);
                res += valueMap(string);
            } else {
                start += 1;
                res += tempValue;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    
    int romanToInt = solution->romanToInt("MCMXCIV");
    std::cout << romanToInt << std::endl;
    return 0;
}
