//
//  main.cpp
//  汉明距离
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
#include <stack>

//两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
//
//给出两个整数 x 和 y，计算它们之间的汉明距离。
//
//注意：
//0 ≤ x, y < 231.
//
//示例:
//
//输入: x = 1, y = 4
//
//输出: 2
//
//解释:
//1   (0 0 0 1)
//4   (0 1 0 0)
//       ↑   ↑
//
//上面的箭头指出了对应二进制位不同的位置。

class Solution {
public:
    int hammingDistance(int x, int y) {
        // 方案一 按照题面意思把相应的数字解析二进制，然后补充，再对比
//        std::string binaryX = "";
//        while (x) {
//            binaryX += std::to_string(x % 2);
//            x = x / 2;
//        }
//
//        std::string binaryY = "";
//        while (y) {
//            binaryY += std::to_string(y % 2);
//            y = y / 2;
//        }
//
//        if (binaryY.length() > binaryX.length()) {
//            int len = binaryY.length() - binaryX.length();
//            for (int i = 0; i < len; i++) {
//                binaryX.append("0");
//            }
//        } else {
//            int len = binaryX.length() - binaryY.length();
//            for (int i = 0; i < len; i++) {
//                binaryY.append("0");
//            }
//        }
//
//        int count = 0;
//        for (int i = 0; i < binaryY.length(); i++) {
//            if (binaryY.substr(i, 1) != binaryX.substr(i, 1)) {
//                count++;
//            }
//        }
        
        // 方案2.位运算 异或结果中的1的个数就是结果
        int count = 0;
        int value = x ^ y;
        while (value) {
            if (value % 2 == 1) {
                count++;
            }
            value = value >> 1;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    
    int hammingDistance = solution->hammingDistance(14,2);
    std::cout << hammingDistance << std::endl;
    return 0;
}
