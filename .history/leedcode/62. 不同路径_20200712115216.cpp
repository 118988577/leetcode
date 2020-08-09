/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

*/
#include<vector>
using namespace std;
class Solution {
public:
    int ans = 0;
    void search( vector<int> location,int m,int n){
        if(location[0] == m -1 && location[1] == n -1){
            ans++;
            return;
        }
        if(location[0] < m-1 && location[1] == n-1){
            location[0]++;
            search(location, m, n);
        }
    }
    int uniquePaths(int m, int n) {
        
    }
};