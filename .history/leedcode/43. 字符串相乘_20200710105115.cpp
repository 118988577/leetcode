/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"

*/
#include<string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // if(num1 == "0" || num2 == "0"){
        //     return "0";
        // }
        // string ans;
        // int carry = 0;
        // int value = 0;
        // while(!num1.empty() && !num2.empty()){
        //     int product = (num1.back() - '0') * (num2.back() - '0') + carry;
        //     carry = product / 10;
        //     value = product % 10;
        //     ans += to_string('0' + value);
        //     num1.pop_back();
        //     num2.pop_back();
        // }
        // while(!num1.empty()){
        //     int product = num1.back() - '0' + carry;
        //     carry = product / 10;
        //     value = product % 10;
        //     ans += to_string('0' + value);
        //     num1.pop_back();
        // }
        // while(!num2.empty()){
        //     int product = num2.back() - '0' + carry;
        //     carry = product / 10;
        //     value = product % 10;
        //     ans += to_string('0' + value);
        //     num2.pop_back();
        // }
        // return ans;
    }
};