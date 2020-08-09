/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
*/
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        set<int> rowSet;
        set<int> columnSet;
        int M = matrix.size(), N = matrix[0].size();
        int i, j;
        for (i = 0; i < M;i++){
            for (j = 0; j < N;j++){
                if(matrix[i][j] == 0){
                    rowSet.insert(i);
                    columnSet.insert(j);
                }
            }
        }
        for (set<int>::iterator it = rowSet.begin(); it != rowSet.end();it++){
            for (int k = 0; k < N;k++)
                matrix[*it][k] = 0;
        }
        for (set<int>::iterator it = columnSet.begin(); it != columnSet.end();it++){
            for (int k = 0; k < M;k++)
                matrix[k][*it] = 0;
        }
            return;
    }
};