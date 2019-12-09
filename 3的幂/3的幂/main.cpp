//
//  main.cpp
//  3的幂
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
#include <math.h>

//给定一个整数，写一个函数来判断它是否是 3 的幂次方。
//
//示例 1:
//
//输入: 27
//输出: true
//示例 2:
//
//输入: 0
//输出: false
//示例 3:
//
//输入: 9
//输出: true
//示例 4:
//
//输入: 45
//输出: false
//进阶：
//你能不使用循环或者递归来完成本题吗？


class Solution {
    public:
    bool isPowerOfThree(int n) {
       
        bool isPowerOfThree = false;
        for (int i = 0; ; i++) {
            double value = pow(3, i);
            if (value > n) {
                break;
            } else if ((int)value == n) {
                isPowerOfThree = true;
                break;
            }
        }
        return isPowerOfThree;
    }
};

int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    
    bool isPowerOfThree = solution->isPowerOfThree(0);
    
    return 0;
}
