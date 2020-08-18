/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 *
 * https://leetcode-cn.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (71.96%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 19.4K
 * Testcase Example:  '"2-1-1"'
 *
 * 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及
 * * 。
 * 
 * 示例 1:
 * 
 * 输入: "2-1-1"
 * 输出: [0, 2]
 * 解释: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * 示例 2:
 * 
 * 输入: "2*3-4*5"
 * 输出: [-34, -14, -10, -10, 10]
 * 解释: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    //1.采用递归+分治算法
    long long strToInt(string s){
        long long ans = 0;
        int index = 0;
        for (; index < s.length();index++){
            ans *= 10;
            ans += s[index] - '0';
        }
        return ans;
    }
    vector<string> split(string input){
        int N = input.length();
        vector<string> res;
        for (int i = 0; i < N;i++){
            if(input[i] >= '0'&&input[i] <= '9'){
                string num = "";
                num += input[i++];
                while(input[i] >= '0'&&input[i] <= '9'){
                    num += input[i++];
                }
                res.push_back(num);
                i--;
            }
            if(input[i] == '+'||input[i] == '-'||input[i] == '*'||input[i] == '/'){
                string temp = "";
                temp += input[i];
                res.push_back(temp);
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string input) {
        //先对输入做处理，转换成字符串数组
        if(input.empty())
            return {};
        split(input);
        
    }
};
// @lc code=end

