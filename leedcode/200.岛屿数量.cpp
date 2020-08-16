/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (49.86%)
 * Likes:    706
 * Dislikes: 0
 * Total Accepted:    142K
 * Total Submissions: 283.8K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ['1','1','1','1','0'],
 * ['1','1','0','1','0'],
 * ['1','1','0','0','0'],
 * ['0','0','0','0','0']
 * ]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ['1','1','0','0','0'],
 * ['1','1','0','0','0'],
 * ['0','0','1','0','0'],
 * ['0','0','0','1','1']
 * ]
 * 输出: 3
 * 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int L, N;
    void dfs(vector<vector<char>>& grid,int x,int y){
        grid[x][y] = '0';
        if(x -1 >= 0 &&  grid[x-1][y] == '1')
            dfs(grid, x - 1, y);
        if(x+1 < L&&  grid[x+1][y] == '1')
            dfs(grid,x+1,y);
        if( y-1 >=0&&grid[x][y-1] == '1')
            dfs(grid, x, y - 1);
        if( y+1 < N&& grid[x][y + 1] == '1')
            dfs(grid,x,y + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int ans = 0;
        L = grid.size();
        N = grid[0].size();
        for (int i = 0; i < L;i++)
            for (int j = 0; j < N;j++){
                if(grid[i][j] == '1'){
                    ans++;
                     dfs(grid, i, j);
                }
               
            }
        return ans;
    }
};
// @lc code=end

