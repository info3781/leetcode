//
//  main.cpp
//  从排序数组中删除重复项
//
//  Created by Info on 2019/11/19.
//  Copyright © 2019 Info. All rights reserved.
//

//c.erase(p); // 删除迭代器p所指定的元素，返回一个指向被删除元素之后的迭代器。
//c.erase(begin,end); // 删除b,e所指定范围内的元素，返回一个指向被删除元素之后的迭代器。
//c.clear(); // 删除所有元素

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return (int)nums.size();
        }
        
        std::vector<int>::iterator iter = nums.begin();
        int last = *iter;
        iter++;
        
        for (; iter < nums.end(); ) {
            int value = *iter;
            if (value == last) {
                nums.erase(iter);
            } else {
                last = value;
                iter++;
            }
        }
        return (int)nums.size();
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);

    Solution *solution = new Solution();
    int num = solution->removeDuplicates(nums);
    printf("%d\n", num);
    return 0;
}
