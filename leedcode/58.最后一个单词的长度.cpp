/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ' ' && ans == 0){
                continue;
            }else if(s[i] == ' '){
                break;
            }else{
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

