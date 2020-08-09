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
                    if(rowMap[i].find(value) == rowMap[i].end()){
                        rowMap[i][value] = 1;
                    }else{
                        rowMap[i][value]++;
                    }
                    if(columnMap[j].find(value) == columnMap[j].end()){
                        columnMap[j][value] = 1;
                    }else{
                        columnMap[j][value]++;
                    }
                    if(subSuduMap[subsuduIndex].find(value) == subSuduMap[value].end()){
                        subSuduMap[subsuduIndex][value] = 1;
                    }else{
                        subSuduMap[subsuduIndex][value]++;
                    }
                    if (rowMap[i][value] > 1 || columnMap[j][value] > 1||subSuduMap[subsuduIndex][value]){
                        return false;
                    }
                }

            }
        }
        return true;
    }
};