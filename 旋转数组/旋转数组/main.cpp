//
//  main.cpp
//  旋转数组
//
//  Created by Info on 2019/11/20.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入: [1,2,3,4,5,6,7] 和 k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右旋转 1 步: [7,1,2,3,4,5,6]
//向右旋转 2 步: [6,7,1,2,3,4,5]
//向右旋转 3 步: [5,6,7,1,2,3,4]
//示例 2:
//
//输入: [-1,-100,3,99] 和 k = 2
//输出: [3,99,-1,-100]
//解释:
//向右旋转 1 步: [99,-1,-100,3]
//向右旋转 2 步: [3,99,-1,-100]
//说明:
//
//尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//要求使用空间复杂度为 O(1) 的 原地 算法。

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
               
        k = nums.size() > k ? k : k % nums.size();
            std::reverse(nums.begin(), nums.end());
            
            std::vector<int> temp1;
            for (int i = 0; i < k; i++) {
                temp1.push_back(nums[i]);
            }
            std::reverse(temp1.begin(), temp1.end());

            std::vector<int> temp2;
            for (int i = k; i < nums.size(); i++) {
                temp2.push_back(nums[i]);
            }
            std::reverse(temp2.begin(), temp2.end());

            for (int i = 0; i < temp2.size(); i++) {
                temp1.push_back(temp2[i]);
            }
            nums = temp1;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> nums{1};
    Solution *solution = new Solution();
    solution->rotate(nums, 0);
    return 0;
}
