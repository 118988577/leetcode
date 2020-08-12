/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (47.02%)
 * Likes:    616
 * Dislikes: 0
 * Total Accepted:    82.6K
 * Total Submissions: 174.9K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start
#include<set>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet;
        for(string word:wordDict){
            wordSet.insert(word);
        }
        int N = s.length();
        bool dp[N - 1];
        wordSet.find(s.substr(0, 1)) != wordSet.end() ? dp[0] = true : dp[0] = false;
        for (int i = 1; i < N;i++){
            dp[i] = false;
            for (int j = 0; j < i;j++){
                if(dp[j] && wordSet.find(s.substr(j+1,i-j))!= wordSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N - 1];
    }
};
// @lc code=end

