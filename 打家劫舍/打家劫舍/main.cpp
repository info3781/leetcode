//
//  main.cpp
//  打家劫舍
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

//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
//
//示例 1:
//
//输入: [1,2,3,1]
//输出: 4
//解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//偷窃到的最高金额 = 1 + 3 = 4 。
//示例 2:
//
//输入: [2,7,9,3,1]
//输出: 12
//解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//偷窃到的最高金额 = 2 + 9 + 1 = 12 。

class Solution {
    public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }
        
        int dp[nums.size() + 10];
        memset(dp, 0, nums.size() + 10);
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        int max = 0;
        for (int i = 2; i < nums.size(); i++) {
            // [0,i - 2]中寻找最大的
            dp[i] = std::max(max_rob(0, i - 2, dp) + nums[i], dp[i - 1]);
            max = std::max(dp[i], max);
        }
        
        return max;
    }
    int max_rob(int start, int end, int dp[]) {
        int max = -1;
        for (int i = start; i <= end; i++) {
            max = std::max(dp[i], max);
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    // special case {2,1,1,2}
    std::vector<int> nums = {2,7,9,3,1};
    Solution* solution = new Solution();
    int rob = solution->rob(nums);
    std::cout << rob << "\n";
    return 0;
}
