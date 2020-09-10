/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 *
 * https://leetcode-cn.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (34.62%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 30.8K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * 
 * 对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。
 * 
 * 格式
 * 
 * 该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。
 * 
 * 你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。
 * 
 * 示例 1:
 * 
 * 输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 * 
 * ⁠       0
 * ⁠       |
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3 
 * 
 * 输出: [1]
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 * 
 * ⁠    0  1  2
 * ⁠     \ | /
 * ⁠       3
 * ⁠       |
 * ⁠       4
 * ⁠       |
 * ⁠       5 
 * 
 * 输出: [3, 4]
 * 
 * 说明:
 * 
 * 
 * 根据树的定义，树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
 * 树的高度是指根节点和叶子节点之间最长向下路径上边的数量。
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    // vector<vector<int>> graph;
    // int N;
    // int bfs(int x){
    //     queue<int> nodes;
    //     bool visited[N];
    //     for (int i = 0; i < N;i++)
    //         visited[i] = false;
    //     nodes.push(x);
    //     visited[x] = true;
    //     int hight = 0;
    //     while (!nodes.empty()){
    //         int count = nodes.size();
    //         for (int i = 0; i < count;i++){
    //             int node = nodes.front();
    //             nodes.pop();
    //             visited[node] = true;
    //             for(int y : graph[node]){
    //                 if(visited[y] == false){
    //                     nodes.push(y);
    //                 }
    //             }
    //         }
    //         hight++;
    //     }
    //     return hight;
    // }
    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     if(n == 0)
    //         return {};
    //     N = n;
    //     graph.resize(n);
    //     for(const vector<int> &edge:edges){
    //         graph[edge[0]].push_back(edge[1]);
    //         graph[edge[1]].push_back(edge[0]);
    //     }
    //    map<int,vector<int>> ans;
       
    //     for (int i = 0;i < n;i++){
    //         int hight = bfs(i);
    //         if(ans.count(hight) == 0){
    //             vector<int> temp;
    //             temp.push_back(i);
    //             ans[hight] = temp;
    //         }else{
    //             ans[hight].push_back(i);
    //         }
    //     }
    //     return ans.begin()->second;
    // }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) { 
        if(n == 1)
            return {0};
        vector<int> indegree;
        vector<vector<int>> graph;
        queue<int> Q;
        for (int i = 0; i < n;i++){
            indegree.push_back(0);
        }
        graph.resize(n);
        for( vector<int> edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        for (int i = 0; i < n;i++){
            if(indegree[i] == 1)
                Q.push(i);
        }
        while(n > 2){
            int count = Q.size();
            n -= count;
            for (int i = 0; i < count;i++){
                int x = Q.front();
                Q.pop();
                for(int y:graph[x]){
                    if(indegree[y] > 0)
                        indegree[y]--;
                    if(indegree[y] == 1)
                        Q.push(y);
                }
            }
        }
        vector<int> ans;
        while(!Q.empty()){
            ans.push_back(Q.front());
            Q.pop();
        }
        return ans;
    }

};
// @lc code=end

