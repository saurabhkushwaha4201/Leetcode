#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1); // sentinel head
        tail = new Node(-1, -1); // sentinel tail
        head->next = tail;
        tail->prev = head;
    }

    // ~LRUCache() {
    //     // free all nodes
    //     Node* cur = head;
    //     while (cur) {
    //         Node* nx = cur->next;
    //         delete cur;
    //         cur = nx;
    //     }
    // }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        Node* node = it->second;
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cap <= 0) return;

        auto it = mp.find(key);
        if (it != mp.end()) {
            // update existing node
            Node* node = it->second;
            node->value = value;
            moveToFront(node);
            return;
        }

        // key not present
        if ((int)mp.size() == cap) {
            // evict LRU
            Node* lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        // insert new node at front
        Node* node = new Node(key, value);
        addToFront(node);
        mp[key] = node;
    }

private:
    int cap;
    Node *head, *tail;
    unordered_map<int, Node*> mp;

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }
};

