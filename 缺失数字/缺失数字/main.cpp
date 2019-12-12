//
//  main.cpp
//  缺失数字
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

//给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
//
//示例 1:
//
//输入: [3,0,1]
//输出: 2
//示例 2:
//
//输入: [9,6,4,2,3,5,7,0,1]
//输出: 8
//说明:
//你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int flag[nums.size() + 5];
        memset(flag, 0, sizeof(flag));
        
        for (int i = 0; i < nums.size(); i++) {
            flag[nums[i]] = 1;
        }
        int num = 1;
        for (int i = 0; i <= nums.size(); i++) {
            if (flag[i] == 0) {
                num = i;
                break;
            }
        }
        return num;
    }
};

int main(int argc, const char * argv[]) {
    Solution* solution = new Solution();
    
    std::vector<int> nums = {0, 1};
    int missingNumber = solution->missingNumber(nums);
    std::cout << missingNumber << std::endl;
    return 0;
}
