/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool palindrome(string s){
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(s[left] != s[right])
                return false;
            else{
                left++;
                right++;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(s[left]!= s[right])
                return palindrome(s.substr(left,right - left )) || palindrome(s.substr(left + 1,right - left));
            else{
                left++;
                right++;
            }
        }
        return true;
    }
};
// @lc code=end

