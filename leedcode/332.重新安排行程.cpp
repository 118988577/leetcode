/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 *
 * https://leetcode-cn.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (43.81%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    25.1K
 * Total Submissions: 57.3K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * 给定一个机票的字符串二维数组 [from,
 * to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从
 * JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 如果存在多种有效的行程，请你按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"]
 * 相比就更小，排序更靠前
 * 所有的机场都用三个大写字母表示（机场代码）。
 * 假定所有机票至少存在一种合理的行程。
 * 所有的机票必须都用一次 且 只能用一次。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * 输出：["JFK", "MUC", "LHR", "SFO", "SJC"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * 输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
 * 解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。
 * 
 */

// @lc code=start
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int N = 0;
    vector<string> ans;
    unordered_map<string, map<string,int>> Graph;
    // void dfs(const string& node){
    //     while(Graph.count(node)&& Graph[node].size()>0){
    //         string nextNode = Graph[node].top();
    //         Graph[node].pop();
    //         dfs(nextNode);
    //     }
    //     ans.push_back(node);
    // }
    bool dfs(int ticketNum, vector<string>& ans){
        if(ans.size()== ticketNum+1)
            return true;
        for (pair<const string, int>& target : Graph[ans[ans.size() - 1]]) {
            if (target.second > 0 ) { // 使用int字段来记录到达城市是否使用过了
                ans.push_back(target.first);
                target.second--;
                if (dfs(ticketNum,ans)) return true;
                ans.pop_back();
                target.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.empty())
            return {};
        for(const vector<string> & tic:tickets){
            Graph[tic[0]][tic[1]]++; // 记录映射关系
        }
        ans.push_back("JFK");
        dfs(tickets.size(),ans);
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

