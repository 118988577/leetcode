/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (68.35%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    40.7K
 * Total Submissions: 59.4K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> ans;
    bool isplalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& ans,vector<string>& cur,string s,int index){
        if(index >= s.length()){
            ans.push_back(cur);
            return;
        }
        int len = 1;
        for (int i = index; i < s.length();i++){
            string temp = s.substr(index,len++);
            if(isplalindrome(temp)){
                cur.push_back(temp);
                backtrack(ans, cur, s, index + len);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.length() == 0)
            return ans;
        vector<string> current;
        backtrack(ans,current,s,0);
        return ans;
    }
};
// @lc code=end

