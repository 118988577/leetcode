/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string LSP(vector<string>& strs,int low,int hig){
        if(low == hig){
            return strs[low];
        }else{
            int mid = (low + hig) / 2;
            string left = LSP(strs,low, mid);
            string right = LSP(strs,mid +1,hig);
            return commonStrPrefix(left,right);
        }
    }
    string commonStrPrefix(string s1,string s2){
        int minlen = min(s1.size(),s2.size());
        for (int i = 0; i < minlen;i++){
            if(s1[i]!=s2[i]){
                return s1.substr(0,i);
            }
        }
        return s1.substr(0,minlen);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }
        return LSP(strs,0,strs.size() - 1);
    }
};
// @lc code=end

