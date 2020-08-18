/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode-cn.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (36.57%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 59.1K
 * Testcase Example:  '"3+2*2"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 
 * 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
 * 
 * 示例 1:
 * 
 * 输入: "3+2*2"
 * 输出: 7
 * 
 * 
 * 示例 2:
 * 
 * 输入: " 3/2 "
 * 输出: 1
 * 
 * 示例 3:
 * 
 * 输入: " 3+5 / 2 "
 * 输出: 5
 * 
 * 
 * 说明：
 * 
 * 
 * 你可以假设所给定的表达式都是有效的。
 * 请不要使用内置的库函数 eval。
 * 
 * 
 */

// @lc code=start
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    long long strToInt(string s){
        long long ans = 0;
        int index = 0;
        for (; index < s.length();index++){
            ans *= 10;
            ans += s[index] - '0';
        }
        return ans;
    }
    int calculate(string s) {
        if(s.empty())
            return 0;
        //中缀转后缀
        vector<string> suffix;
        stack<string> opera;
        for (int i = 0; i < s.size();i++){
            //跳过空格
            while(s[i] == ' ')
                i++;
            if(s[i] >= '0'&&s[i] <= '9'){
                string num = "";
                num += s[i++];
                while(i < s.size()&&s[i] >= '0'&&s[i] <= '9'){
                    num += s[i++];
                }
                suffix.push_back(num);
                i--;
            }    
            if(s[i] == '/'||s[i] == '*'){
                while(!opera.empty()&&(opera.top() == "*"||opera.top()=="/")){
                    suffix.push_back(opera.top());
                    opera.pop();
                }
                string temp = "";
                opera.push(temp + s[i]);
            }
            if(s[i] == '+'||s[i] == '-'){
                while(!opera.empty()){
                    suffix.push_back(opera.top());
                    opera.pop();
                }
                string temp = "";
                opera.push(temp + s[i]);
            }
        }
        while(!opera.empty()){
            suffix.push_back(opera.top());
            opera.pop();
        }
        //计算后缀表达式
        for(string str : suffix){
            if(str == "+"|| str=="-"||str=="*"||str =="/"){
                long long  x = strToInt(opera.top());
                opera.pop();
                long long y = strToInt(opera.top());
                opera.pop();
                if(str == "+"){
                    opera.push(to_string(x+y));
                }else if(str == "-"){
                    opera.push(to_string(y-x));
                }else if(str=="*"){
                    opera.push(to_string(x*y));
                }else{
                    opera.push(to_string(y/x));
                }
            }else{
                opera.push(str);
            }
        }
        return strToInt(opera.top());
    }
};
// @lc code=end

