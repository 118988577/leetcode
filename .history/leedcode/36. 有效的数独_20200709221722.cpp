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
        map<int,int> rowMap[9];
        map<int, int> columnMap[9];
        map<int, int> subSuduMap[9];

        
        for (int i = 0; i < 9;i++){
            for (int j = 0; j < 9;j++){
                if(board[i][j] != '.'){
                    int value = board[i][j] - '0';
                    int subsuduIndex = (i / 3) * 3 + j / 3;
                    if(rowMap.find(value) == rowMap.end()){
                        rowMap[value] = 1;
                    }else{
                        rowMap[value]++;
                    }
                    if(columnMap.find(value) == columnMap.end()){
                        columnMap[value] = 1;
                    }else{
                        columnMap[value]++;
                    }
                    if(subSuduMap.find(subsuduIndex) == subSuduMap.end()){
                        subSuduMap[subsuduIndex] = 1;
                    }else{
                        subSuduMap[subsuduIndex]++;
                    }
                }

            }
        }
    }
};