//
//  main.cpp
//  Fizz Buzz
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

//写一个程序，输出从 1 到 n 数字的字符串表示。
//
//1. 如果 n 是3的倍数，输出“Fizz”；
//
//2. 如果 n 是5的倍数，输出“Buzz”；
//
//3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
//
//示例：
//
//n = 15,
//
//返回:
//[
//    "1",
//    "2",
//    "Fizz",
//    "4",
//    "Buzz",
//    "Fizz",
//    "7",
//    "8",
//    "Fizz",
//    "Buzz",
//    "11",
//    "Fizz",
//    "13",
//    "14",
//    "FizzBuzz"
//]

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> vector;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                vector.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                vector.push_back("Fizz");
            } else if (i % 5 == 0) {
                vector.push_back("Buzz");
            } else {
                vector.push_back(std::to_string(i));
            }
        }
        return vector;
    }
};

int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    
    std::vector<std::string> fizzBuzz = solution->fizzBuzz(15);
    
    return 0;
}
