/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (42.95%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    87.9K
 * Total Submissions: 204.3K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 
 * 
 * 示例 3：
 * 
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 * 
 */

// @lc code=start
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.length() == 0)
            return s;
        stack<string> words;
        string ans;
        string newword ="";
        for (int i = 0; i < s.length();i++){
            if(s[i] == ' '){
                if(newword.length()!=0){
                    words.push(newword);
                    newword.clear();
                }
            }else{
                newword += s[i];
            }
        }
        if(!newword.empty()){
            words.push(newword);
        }
        if(!words.empty()){
            ans += words.top();
            words.pop();
        }

        while(!words.empty()){
            ans += " " + words.top();
            words.pop();
        }
        return ans;
    }
};
// int main(){
//     Solution test;
//     test.reverseWords("the sky is blue");
//     return 0;
// }
// @lc code=end

