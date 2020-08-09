/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <map>
using namespace std;

//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> nodeCountMap;
        ListNode *node = head;
        if(head == nullptr)
            return head;
        while(node != nullptr){
            if(nodeCountMap.find(node->val) == nodeCountMap.end()){
                nodeCountMap[node->val] = 1;
            }else{
                nodeCountMap[node->val] = nodeCountMap[node->val] + 1;
            }
            node = node->next;
        }
        ListNode *front = nullptr;
        ListNode *current = nullptr;
        node = head;
        while(node!=nullptr){
            if (nodeCountMap[node->val] == 1){
                if(front == nullptr){
                    current = node;
                    front = current;
 
                }else{
                    current->next = node;
                    current = current->next;
                }
            }
            node = node->next;
        }
        if(current != nullptr)
            current->next = nullptr;
        return front;
    }
};
