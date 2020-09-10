/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (64.60%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 15.1K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给定一个字符串数组 words，找到 length(word[i]) * length(word[j])
 * 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
 * 
 * 示例 1:
 * 
 * 输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出: 16 
 * 解释: 这两个单词为 "abcw", "xtfn"。
 * 
 * 示例 2:
 * 
 * 输入: ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出: 4 
 * 解释: 这两个单词为 "ab", "cd"。
 * 
 * 示例 3:
 * 
 * 输入: ["a","aa","aaa","aaaa"]
 * 输出: 0 
 * 解释: 不存在这样的两个单词。
 * 
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int N = words.size();
        vector<int> mask;
        vector<int> len;
        mask.resize(N);
        len.resize(N);
            int bitMask = 0;
        for (int i = 0; i < N;i++){
            bitMask = 0;
            for(char ch:words[i]){
                bitMask |= 1 <<(int)((int)ch - (int)'a');
            }
            mask[i] = bitMask;
            len[i] = words[i].size();
        }
        int maxLen = 0;
        for (int i = 0; i < N;i++){
            for (int j = i + 1; j < N;j++){
                if((mask[i]&mask[j]) == 0){
                    maxLen = max(maxLen,len[i] * len[j]);
                }
            }
        }
        return maxLen;
    }
};
// int main(){
//     Solution test;
//     vector<string> example = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
//     int ans = test.maxProduct(example);
//     return ans;
// }
// @lc code=end

