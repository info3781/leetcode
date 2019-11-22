//
//  main.cpp
//  旋转图像
//
//  Created by Info on 2019/11/21.
//  Copyright © 2019 Info. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

//给定一个 n × n 的二维矩阵表示一个图像。
//
//将图像顺时针旋转 90 度。
//
//说明：
//
//你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
//
//示例 1:
//
//给定 matrix =
//[
//  [1,2,3],
//  [4,5,6],
//  [7,8,9]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
//给定 matrix =
//[
//  [ 5, 1, 9,11],
//  [ 2, 4, 8,10],
//  [13, 3, 6, 7],
//  [15,14,12,16]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//  [15,13, 2, 5],
//  [14, 3, 4, 1],
//  [12, 6, 8, 9],
//  [16, 7,10,11]
//]

// [start][start->end]，[start->end][end]，[end][end->start]，[end->start][start]。

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = (int)matrix.size();
        for (int i = 0; i < n / 2; i++) {
            int start = i;
            int end = n - start - 1;
            for (int j = 0; j < end - start; j++) {
                int temp = matrix[start][start + j];
                
                matrix[start][start + j] = matrix[end - j][start];
                matrix[end - j][start] = matrix[end][end - j];
                matrix[end][end - j] = matrix[start + j][end];
                matrix[start + j][end] = temp;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    Solution *solution = new Solution();
    solution->rotate(matrix);
    return 0;
}
