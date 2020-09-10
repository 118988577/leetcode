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
    vector<int> diffWaysToCompute(string instr) {
        if (instr.length() == 0) {
            return  {};
        }
        vector<int> result ;
        int num = 0;
        //考虑是全数字的情况
        int index = 0;
        while (index < instr.length() && !isOperation(instr[index])) {
            num = num * 10 + instr[index] - '0';
            index++;
        }
        //将全数字的情况直接返回
        if (index == instr.length()) {
            result.push_back(num);
            return result;
        }
        int N = instr.length();
        for (int i = 0; i < instr.length(); i++) {
            //通过运算符将字符串分成两部分
            if (isOperation(instr[i])) {
                vector<int> result1 = diffWaysToCompute(instr.substr(0, i));
                vector<int> result2 = diffWaysToCompute(instr.substr(i + 1,N - i-1));
                //将两个结果依次运算
                for (int j = 0; j < result1.size(); j++) {
                    for (int k = 0; k < result2.size(); k++) {
                        char op = instr[i];
                        result.push_back(caculate(result1[j], op, result2[k]));
                    }
                }
            }
        }
        return result;
    }

    int caculate(int num1, char c, int num2) {
        switch (c) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
        }
        return -1;
    }

    bool isOperation(char c) {
        return c == '+' || c == '-' || c == '*';
    }
};
// @lc code=end

