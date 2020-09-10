/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 *
 * https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (45.41%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 18.1K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * 序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
 * 
 * ⁠    _9_
 * ⁠   /   \
 * ⁠  3     2
 * ⁠ / \   / \
 * ⁠4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * 
 * 例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。
 * 
 * 给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。
 * 
 * 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。
 * 
 * 你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。
 * 
 * 示例 1:
 * 
 * 输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: "1,#"
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入: "9,#,#,1"
 * 输出: false
 * 
 */

// @lc code=start
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return false;
        stack<string> nodeStack;
        int N = preorder.length();
        string stackTop = " ";
        int index = 0;
        while(index < N){
            //找到一个字符值
            string curStr = "";
            if(preorder[index]==',')
                index++;
            while(index < N && preorder[index]!=','){
                curStr += preorder[index++];
            }
            if(nodeStack.empty()){
                nodeStack.push(curStr);
            }else{
                stackTop = nodeStack.top();
                nodeStack.push(curStr);
            }
            while(nodeStack.size() >= 3&& nodeStack.top() == "#"&& stackTop == "#"){
                nodeStack.pop();
                nodeStack.pop();
                if(nodeStack.top() == "#")
                    return false;
                nodeStack.pop();

                if(!nodeStack.empty()){
                    stackTop = nodeStack.top();
                }
                nodeStack.push("#");
            }

        }
            return nodeStack.size() == 1 && nodeStack.top() == "#";
        // }
        // if(nodeStack.empty())
        //     return true;
        // else{
        //     return false;
        // }
        // int count = 1;
        // int index = 0;
        // int N = preorder.length();
        // while(index < N){
        //     //找到一个字符值
        //     string curStr = "";
        //     if(preorder[index]==',')
        //         index++;
        //     while(index < N && preorder[index]!=','){
        //         curStr += preorder[index++];
        //     }

        //     count--;
        //     if(count<0)
        //         return false;
        //     if(curStr!="#")
        //         count += 2;
        // }   
        // if(count == 0)
        //     return true;
        // else
        //     return false;
    }
};
// @lc code=end

