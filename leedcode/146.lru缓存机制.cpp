struct DLinkedNode {
    int value, key;
    DLinkedNode *pre;
    DLinkedNode *next;
    DLinkedNode() : value(-1),key(-1), pre(nullptr), next(nullptr){};
    DLinkedNode(int _key,int _val): value(_val),key(_key), pre(nullptr), next(nullptr){};
};
#include<map>
using namespace std;
class LRUCache {
public:
    int size, N;
    DLinkedNode *head;
    DLinkedNode *tail;
    map<int, DLinkedNode *> location;
    LRUCache(int capacity) {
        size = 0;
        N = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
    }
    //加入到链表头
    void addToHead(DLinkedNode* node){
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }
    void removeNode(DLinkedNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void moveTohead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail(){
        DLinkedNode *node = tail->pre;
        removeNode(node);
        return node;
    }
    int get(int key) {
        if(location.count(key) == 0){
            return -1;
        }
        DLinkedNode *node = location[key];
        moveTohead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(location.count(key) == 0 ){

            DLinkedNode *node = new DLinkedNode(key,value);
            addToHead(node);
            location[key] = node;
            ++size;
            if(size > N){
               DLinkedNode* node =  removeTail();
               location.erase(node->key);
               delete node;
               size--;
            }
        }else{
            location[key]->value = value;
            moveTohead(location[key]);
        }
    }
};
