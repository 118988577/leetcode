/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母

*/
#include<vector>
#include<string>
using namespace std;

class Solution {
    vector<string> ans;
public:

    vector<string> digitHash = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void Combinations(string digits, string letter, int index, int len)
    {
        if(index  == len){
            ans.push_back(letter);
            return;
        }
        string temp = digitHash[digits[index] - '0'];
        for (int i = 0; i < temp.size();i++){
            Combinations(digits,letter + temp[i],index + 1,len);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()){
            return ans;
        }
        int L = digits.length();
        Combinations(digits,"",0,L);
        return ans;
    }
};
 int main(){
     Solution test;
     test.letterCombinations("23");
     return 0;
 }