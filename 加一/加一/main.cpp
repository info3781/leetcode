//
//  main.cpp
//  加一
//
//  Created by Info on 2019/11/20.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//示例 1:
//
//输入: [1,2,3]
//输出: [1,2,4]
//解释: 输入数组表示数字 123。
//示例 2:
//
//输入: [4,3,2,1]
//输出: [4,3,2,2]
//解释: 输入数组表示数字 4321。

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::reverse(digits.begin(), digits.end());
        
        int reminderValue = 1;
        for (int i = 0; i < digits.size(); i++) {
            int sum = digits[i] + reminderValue;
            
            if (sum < 10) {
                reminderValue = 0;
                digits[i] = sum;
                break;
            } else {
                digits[i] = sum % 10;
                reminderValue = 1;
            }
        }
        if (reminderValue == 1) { // 补位1
            digits.push_back(1);
        }
        
        std::vector<int> res;
        std::vector<int>::reverse_iterator iter = digits.rbegin();
        for (; iter != digits.rend(); iter++) {
            res.push_back(*iter);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> digits{1,9};
    Solution *solution = new Solution();
    std::vector<int> res = solution->plusOne(digits);
    return 0;
}
