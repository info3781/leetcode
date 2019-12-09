//
//  main.cpp
//  Shuffle an Array
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

//打乱一个没有重复元素的数组。
//
//示例:
//
//// 以数字集合 1, 2 和 3 初始化数组。
//int[] nums = {1,2,3};
//Solution solution = new Solution(nums);
//
//// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
//solution.shuffle();
//
//// 重设数组到它的初始状态[1,2,3]。
//solution.reset();
//
//// 随机返回数组[1,2,3]打乱后的结果。
//solution.shuffle();


class Solution {
    public:
    std::vector<int> nums;
    Solution(std::vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return this->nums;
    }
    
    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {
        std::vector<int> nums = this->nums;
        std::random_shuffle(nums.begin(), nums.end());
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2,3,4,5,6};
    Solution* solution = new Solution(nums);

    std::vector<int> shuffle = solution->shuffle();
    std::vector<int> reset = solution->reset();

    return 0;
}
