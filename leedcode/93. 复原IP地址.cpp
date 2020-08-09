/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

 

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void backtrace(string s,string &ip,int index,int count){
        if(count == 4){
            if(ip.length() -3 == s.length()){
                ans.push_back(ip);
            }
            return;
        }else{
            string temp;
            for (int i = 0; i < 3;i++){
                if(index + i >= s.length() ){
                    return;
                }else{
                    temp = s.substr(index,i+1);
                    if(i == 1 && temp[0] =='0'){
                        return;
                    }
                    if(i == 2 ){
                        int value = 0;
                        value = (temp[0] - '0') * 100 + (temp[1] - '0') * 10 + (temp[2] - '0');
                        if(value > 255||temp[0] == '0')
                            return;
                    }
                    int n = ip.length();
                    if(ip.length() == 0){
                        ip += temp;
                    }else{
                        ip += "." + temp;
                    }
                    backtrace(s, ip, index + i + 1, count + 1);
                    ip = ip.substr(0,n);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.empty())
            return {};
        string ip = "";
        backtrace(s,ip,0,0);
        return ans;
    }
};