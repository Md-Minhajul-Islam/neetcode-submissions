class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    int cap;
    unordered_map<int, Node*> cache;
    Node *left, *right;

    void remove(Node* node)
    {
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv;
    }

    void insert(Node* node)
    {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }


    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.count(key))
        {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) remove(cache[key]);
        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > cap)
        {
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
