//
//  main.cpp
//  存在重复
//
//  Created by Info on 2019/11/19.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::vector<int> num;
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            std::vector<int>::iterator iter = std::find(num.begin(), num.end(), value); // 查找元素是否存在
            if (iter == num.end()) { // 没包含该元素
                num.push_back(value);
            } else { // 包含该元素
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // 1 2 3 1
    std::vector<int> nums{1,2,3,4};
    Solution *solution = new Solution();
    bool isContainsDuplicate = solution->containsDuplicate(nums);
    printf("%d\n", isContainsDuplicate);
    return 0;
}
