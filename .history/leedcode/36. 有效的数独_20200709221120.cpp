/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

*/
#include<vector>
#include<map>
using namespace std;
class Solution {
public:


    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,int> rowMap;
        map<int, int> columnMap;
        map<int, int> subSuduMap;
        for (int i = 0; i < 9;i++){
            for (int j = 0; j < 9;j++){
                
            }
        }
    }
};