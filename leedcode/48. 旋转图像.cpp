/*
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //先转置，后镜像
    void rotate(vector<vector<int>>& matrix) {
        //转置
        int N = matrix.size();
        for (int row = 0; row < N;row++){
            for (int column = 0; column < row;column++){
                int temp = matrix[row][column];
                matrix[row][column] = matrix[column][row];
                matrix[column][row] = temp;
            }
        }
        //镜像

        for (int column = 0; column < N/2;column++){
            for (int row = 0; row < N;row++){
                swap(matrix[row][column],matrix[row][N - 1 - column]);
            }
        }

    }
};