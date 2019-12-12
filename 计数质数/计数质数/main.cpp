//
//  main.cpp
//  计数质数
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

//统计所有小于非负整数 n 的质数的数量。
//
//示例:
//
//输入: 10
//输出: 4
//解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

class Solution {
public:
    // TLE
//    int countPrimes(int n) {
//        int count = 0;
//        for (int i = 2; i < n / 2; i++) {
//            if (isPrime(i)) {
//                count++;
//            }
//        }
//        return count;
//    }
//    bool isPrime(int value) {
//        for (int i = 2; i <= sqrt(value); i++) {
//            if (value % i == 0) {
//                return false;
//            }
//        }
//        return true;
//    }
    
    int countPrimes(int n) {
        int flag[n + 5];
        for (int i = 2; i < n; i++) {
            flag[i] = true;
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (flag[i]) {
                for (int j = i + i; j < n; j += i) {
                    flag[j] = false;
                }
                count++;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    
    int countPrimes = solution->countPrimes(10);
    std::cout << countPrimes << std::endl;
    return 0;
}
