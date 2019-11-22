//
//  main.cpp
//  两数之和
//
//  Created by Info on 2019/11/20.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
//示例:
//
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> index;
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            if (found == true) {
                break;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] + nums[i] == target) {
                    index.push_back(i);
                    index.push_back(j);
                    found = true;
                    break;
                }
            }
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> nums{3,2,4};
    Solution *solution = new Solution();
    std::vector<int> index = solution->twoSum(nums, 6);
    return 0;
}
