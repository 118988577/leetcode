/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
*/
#include<vector>
#include<string>
using namespace std;

class Solution {
public:

    void bracket(vector<string> &ans,string &cur,int n,int left,int right){
        if(cur.length() == n*2){
            ans.push_back(cur);
            return;
        }
        if(left < n){
            cur.push_back('(');
            bracket(ans,cur,n,left + 1,right);
            cur.pop_back();
        }
        if(right < left){
            cur.push_back(')');
            bracket(ans,cur,n,left,right + 1);
            cur.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        bracket(ans,current,n,0,0);
        return ans;
    }
};