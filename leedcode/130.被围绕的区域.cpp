/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (40.45%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    45.8K
 * Total Submissions: 113K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    //问题的关键之处在于寻找所有与边界的O相连的所有O；
    //采用BFS：从每个边界O出发，深度优先搜索与该位置相连的所有O
    int lenght, hight;
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i < 0||i >= hight || j < 0 || j >= lenght ||board[i][j] == 'X' || board[i][j] == '#'){
            return;
        }
        board[i][j] = '#';
        dfs(board,i-1,j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        //上边界
        lenght = board[0].size();
        hight = board.size();
         for (int i = 0; i < hight; i++) {
            for (int j = 0; j <lenght; j++) {
                // 从边缘o开始搜索
                bool isEdge = i == 0 || j == 0 || i == hight - 1 || j == lenght - 1;
                if (isEdge && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < hight; i++) {
            for (int j = 0; j < lenght; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// @lc code=end