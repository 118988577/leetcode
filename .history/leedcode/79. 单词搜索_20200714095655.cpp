/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
示例:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false

*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool backtrack(vector<vector<char>>& board,string word,int satrt,int row,int column){
        


    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()){
            return false;
        }
        for (int i = 0; i < board.size();i++){
            for (int j = 0; j < board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(backtrack(board,word,0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};