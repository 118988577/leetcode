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
    bool isValid(vector<char>& board){
        vector<int> dightsHash = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < board.size();i++){
            if(board[i] == '.'){
                continue;
            }else{
                dightsHash[board[i] - '0']++;
            }
            if(dightsHash[board[i] - '0'] > 1){
                return false;
            }
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
    }
};