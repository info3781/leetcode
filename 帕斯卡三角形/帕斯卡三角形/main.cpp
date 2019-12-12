//
//  main.cpp
//  帕斯卡三角形
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

//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
//
//
//
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//
//示例:
//
//输入: 5
//输出:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res;
        for (int i = 1; i <= numRows; i++) {
            std::vector<int> sub;
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) {
                    sub.push_back(1);
                } else {
                    std::vector<int> lastSub = res[i - 2];
                    int value = lastSub[j] + lastSub[j - 1];
                    sub.push_back(value);
                }
            }
            res.push_back(sub);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    
    std::vector<std::vector<int>> generate = solution->generate(1);
    return 0;
}
