/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (68.03%)
 * Likes:    377
 * Dislikes: 0
 * Total Accepted:    50.2K
 * Total Submissions: 73.4K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

// @lc code=start
//三项单词查找树
#include<string>
using namespace std;
struct Node
{
    char c;
    bool val;
    Node *left;
    Node *mid;
    Node *right;
    Node() : val(false),left(nullptr),mid(nullptr),right(nullptr){}

};

class Trie {
public:
    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        root = insert(root,word,0);
    }
    Node* insert(Node* node,string word,int d){
        char c = word[d];
        if(node == nullptr){
            node = new Node();
            node->c = c;
        }
        if(c < node->c){
            node->left = insert(node->left, word, d);
        }else if (c  > node->c){
            node->right = insert(node->right,word,d);
        }else if(d < word.length() - 1){
            node->mid = insert(node->mid,word,d+1);
        }else{
            node->val = true;
        }
        return node;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *x = search(root,word,0);
        if(x == nullptr)
            return false;
        return x->val;
    }
    
    Node* search(Node* node,string word,int d){
        if(node == nullptr)
            return nullptr;
        char c = word[d];
        if(c < node->c){
            return search(node->left,word,d);
        }else if(c > node->c){
            return search(node->right,word,d);
        }else if( d < word.length()-1){
            return search(node->mid,word,d+1);
        }else{
            return node;
        }
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *result = search(root, prefix, 0);
        return result != nullptr;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

