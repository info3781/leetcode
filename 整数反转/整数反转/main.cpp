//
//  main.cpp
//  整数反转
//
//  Created by Info on 2019/11/23.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>

//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//
//示例 1:
//
//输入: 123
//输出: 321
// 示例 2:
//
//输入: -123
//输出: -321
//示例 3:
//
//输入: 120
//输出: 21
//注意:
//
//假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

class Solution {
public:
    int reverse(int x) {
        int criticalValue = (int)(pow(2, 31) - 1); // 临界值
        bool isPositive = x >= 0 ? true : false;
        if (abs(x * -1.0) >= criticalValue) {
            return 0;
        }
        
        if (isPositive == false) {
            x = -x;
        }
                
        int res = 0;
        while (x) {
            if (res > criticalValue / 10) {
                return 0;
            }
            
            if (10.0 * res + x % 10 > criticalValue) {
                return 0;
            }
            
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return isPositive ? res : -res;
    }
};

int main(int argc, const char * argv[]) {
    Solution *solution = new Solution();
    int res = solution->reverse(1463847412);
    printf("%d\n", res);
    return 0;
}
