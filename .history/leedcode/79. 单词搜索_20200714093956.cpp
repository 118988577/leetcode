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
    bool backtrace(vector<vector<char>>& board,int row,int column,string word,int start){
        if(start == word.size()){
            return true;
        }
        //左
        if(row > 0 && board[row - 1][column] != '-'&& board[row - 1][column] == word[start]){

            board[row - 1][column] = '-';
            bool ans = backtrace(board,row - 1,column,word,start +1);
            if(ans == true){
                return true;
            }
            board[row - 1][column] = word[start];
        }
        if(row < board[0].size() -1 && board[row + 1][column] != '-'&& board[row + 1][column] == word[start]){

            board[row + 1][column] = '-';
            bool ans = backtrace(board,row + 1,column,word,start +1);
            if(ans == true){
                return true;
            }
            board[row + 1][column] = word[start];
        }
        if(column > 0 && board[row][column - 1] != '-'&& board[row][column - 1] == word[start]){

            board[row][column - 1] = '-';
            bool ans = backtrace(board,row,column - 1,word,start +1);
            if(ans == true){
                return true;
            }
            board[row][column - 1] = word[start];
        }
        if(column < board.size() - 1 && board[row][column + 1] != '-'&& board[row][column + 1] == word[start]){

            board[row][column + 1] = '-';
            bool ans = backtrace(board,row,column + 1,word,start +1);
            if(ans == true){
                return true;
            }
            board[row][column +- 1] = word[start];
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()){
            return false;
        }
        
    }
};