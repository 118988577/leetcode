/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 *
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (50.45%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 52.8K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * 给定一个二叉树
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 
 * 初始状态下，所有 next 指针都被设置为 NULL。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,7]
 * 输出：[1,#,2,3,#,4,5,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数小于 6000
 * -100 <= node.val <= 100
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include<queue>
using namespace std;
class Solution {
public:
    void bfs(Node* root){
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int len = nodeQueue.size();
            Node* preNode = nodeQueue.front();
            if(preNode->left != nullptr)
                nodeQueue.push(preNode->left);
            if(preNode->right!= nullptr)
                nodeQueue.push(preNode->right);    
            nodeQueue.pop();     
            int i = 1;      
            while(i < len){
                preNode->next = nodeQueue.front();
                preNode = nodeQueue.front();
                if(preNode->left != nullptr)
                    nodeQueue.push(preNode->left);
                if(preNode->right!= nullptr)
                    nodeQueue.push(preNode->right);  
                nodeQueue.pop();
                i++;
            }
        }
    }


    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        bfs(root);
        return root;
    }
};
// @lc code=end

