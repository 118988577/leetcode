/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。
*/
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()){
            return 0;
        }
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        int dp[M][N];
        //边界
        if(obstacleGrid[0][0] == 1)
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        for (int i = 1; i < N;i++){
            if(obstacleGrid[0][i] == 1){
                dp[0][i] = 0;
            }else{
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i < M;i++){
            if(obstacleGrid[0][i] == 1){
                dp[0][i] = 0;
            }else {
                dp[0][i] = dp[0][i - 1];
            }
 
        }
        for (int i = 1; i < M;i++){
            for (int j = 1; j < N;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i -1][j] + dp[i][j-1];
                }
            }
        }
        return dp[M-1][N-1];
    }
};