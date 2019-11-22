//
//  main.cpp
//  只出现一次的数字
//
//  Created by Info on 2019/11/19.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
     int singleNumber(std::vector<int>& nums) {
         int result = nums[0];
         for (int i = 1; i < nums.size(); i++) {
             result = nums[i] ^ result;
         }
         return result;
     }
};

int main(int argc, const char * argv[]) {
    //4,1,2,1,2
    std::vector<int> nums{4,1,2,1,2};
    Solution *solution = new Solution();
    int singleNumber = solution->singleNumber(nums);
    printf("%d\n", singleNumber);
    return 0;
}
