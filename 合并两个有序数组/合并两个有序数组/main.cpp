//
//  main.cpp
//  合并两个有序数组
//
//  Created by Info on 2019/12/4.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明:
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例:
//
//输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//输出: [1,2,2,3,5,6]

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int i = 0; i < nums1.size(); i++) {
            if (i >= m) {
                nums1.erase(nums1.begin() + i, nums1.end());
                break;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (i >= n) {
                nums2.erase(nums2.begin() + i, nums2.end());
                break;
            }
            nums1.push_back(nums2[i]);
        }
        
        std::sort(nums1.begin(), nums1.end());
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {2,5,6};
    
    Solution* solution = new Solution();
    solution->merge(nums1, 3, nums2, 3);
    return 0;
}
