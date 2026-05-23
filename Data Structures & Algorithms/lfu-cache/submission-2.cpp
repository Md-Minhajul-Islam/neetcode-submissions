class LFUCache {
public:
    struct Node {
        int key;
        int val;
        int cnt;
        Node *prev;
        Node *next;
        Node(int k, int v, int c)
        {
            key = k;
            val = v;
            cnt = c;
            prev = nullptr;
            next = nullptr;
        }
    };
    int cap, mnCnt;
    vector<pair<Node*, Node*>> freq;
    unordered_map<int, Node*> cache;


    LFUCache(int capacity) {
        cap = capacity;
        mnCnt = 0;
        freq = vector<pair<Node*, Node*>>(200009);
        for(int i = 0; i < 200009; i++)
        {
            Node* left = new Node(-1, -1, -1);
            Node* right = new Node(-1, -1, -1);
            left->next = right;
            right->prev = left;
            freq[i] = {left, right};
        }
    }

    void insert(Node* node)
    {
        int ind = node->cnt;

        Node* prev = freq[ind].second->prev;
        Node* next = freq[ind].second;

        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
    }

    void remove(Node* node)
    {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    bool isEmpty(int ind)
    {
        return freq[ind].first->next == freq[ind].second;
    }
   
    int get(int key) {
        if(cache.count(key))
        {
            Node* curr = cache[key];
            remove(curr);
            if(isEmpty(curr->cnt) && curr->cnt == mnCnt) mnCnt++;
            curr->cnt += 1;
            insert(curr);
            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key))
        {
            Node* curr = cache[key];
            curr->val = value;
            remove(curr);
            if(isEmpty(curr->cnt) && curr->cnt == mnCnt) mnCnt++;
            curr->cnt += 1;
            insert(curr);
        }
        else
        {
            if(cap == cache.size())
            {
                Node* node = freq[mnCnt].first->next;
                remove(node);
                cache.erase(node->key);
                delete(node);
            }

            Node* newNode = new Node(key, value, 1);
            insert(newNode);
            cache[key] = newNode;
            mnCnt = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */