/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (26.96%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 52.1K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 示例 1:
 * 
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 * 
 * 
 * 示例 2:
 * 
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 * 
 * 示例 3:
 * 
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 * 
 * 
 */

// @lc code=start
#include<string>
#include<map>
#include<cstdlib>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //判断被除数为零
        if(numerator == 0)
            return "0";
        //除数为零
        if(denominator == 0)
            return "";
        string ans = "";
        //记录结果符号
        if(numerator > 0 ^ denominator > 0)
            ans += "-";
        //把操作数化为正数
        long long num = (long long)numerator;
        long long denum = (long long)denominator;

        num = llabs(num);
        denum = llabs(denum);

        //计算整数部分
        ans += to_string(num/denum);
        //计算余数
        num = num % denum;
        //余数为0,没有小数部分
        if(num == 0)
            return ans;
        ans += ".";
        map<long long, int> appear;
        int index = ans.size() - 1;
        while(num!=0 && appear.count(num) == 0){
            appear[num] = ++index;
            num *= 10;
            ans += to_string(num / denum) ;
            num %= denum;
        }
        if(appear.count(num)!=0){
            ans.insert(appear[num], "(");
            ans += ")";
        }
        return ans;
    }
};
// @lc code=end

