//
//  main.cpp
//  最大子序和
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

//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//示例:
//
//输入: [-2,1,-3,4,-1,2,1,-5,4],
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
//进阶:
//
//如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

class Solution {
    public:
    int maxSubArray(std::vector<int>& nums) {
        int dp[nums.size() + 5];
        memset(dp, 0, nums.size() + 5);
        
        if (nums.size() == 0) {
            return 0;
        }
        
        dp[0] = nums[0];
        // dp方程： dp[i] = max{dp[i-1]+nums[i], nums[i]}
        int max = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 1] + nums[i] , nums[i]);
            max = std::max(dp[i], max);
        }
        
        return max;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {-1,-2};
    Solution* solution = new Solution();
    int maxSubArray = solution->maxSubArray(nums);
    std::cout << maxSubArray << "\n";
    return 0;
}
