/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string pre = countAndSay(n - 1);
        string ans = "";
        for (int i = 0,count = 1; i < pre.length();i++){
            if(pre[i] == pre[i + 1]){
                count++;
            }else{
                ans += to_string(count) + pre[i];
                count = 1;
            }
        }
        return ans;
    }
};
// @lc code=end

