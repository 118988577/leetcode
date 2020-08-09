/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0){
            return {};
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n;i++){
            vector<int> temp;
            for (int j = 0; j < n;j++){
                temp.push_back(0);
            }
            ans.push_back(temp);
        }
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int value = 1;
        while(left <= right && top <= bottom){
            for (int column = left; column <= right;column++){
                ans[top][column] = value++;
            }
            for (int row = top + 1; row <= bottom;row++){
                ans[row][right] = value++;
            }
            if(left < right && top < bottom){
                for (int column = right - 1; column >= left;column--){
                    ans[bottom][column] = value++;
                }
                for (int row = bottom-1; row > top;row--){
                    ans[row][left] = value++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return ans;
    }
};