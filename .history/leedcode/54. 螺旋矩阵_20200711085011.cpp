/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

*/
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int upRow = 0, downRow = N - 1, leftColumn = 0, rightColumn = N - 1;
        while(upRow <= downRow && leftColumn <= rightColumn){
            //右
            
            //下
            //左
            //上
        }
    }
};