class LFUCache {
public:
    struct Node {
        int key;        // ← added, needed for eviction
        int val;
        int cnt;
        Node* prev;
        Node* next;
        Node(int k, int v, int c) {
            key = k;
            val = v;
            cnt = c;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap, minCnt;
    vector<pair<Node*, Node*>> freq;
    unordered_map<int, Node*> cache;

    LFUCache(int capacity) {
        cap = capacity;
        minCnt = 0;
        freq = vector<pair<Node*, Node*>>(200009);  // fix: mismatched parentheses
        for (int i = 0; i < 200009; i++) {
            Node* left  = new Node(-1, -1, -1);
            Node* right = new Node(-1, -1, -1);
            left->next  = right;
            right->prev = left;
            freq[i] = {left, right};
        }
    }

    // insert before the right sentinel → most recently used in this bucket
    void insert(Node* node) {
        int ind = node->cnt;
        Node* prev = freq[ind].second->prev;
        Node* next = freq[ind].second;
        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    bool isEmpty(int ind) {                         // fix: was void
        return freq[ind].first->next == freq[ind].second;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;

        Node* curr = cache[key];
        remove(curr);
        if (isEmpty(curr->cnt) && curr->cnt == minCnt)
            minCnt++;                               // fix: bump minCnt when bucket empties
        curr->cnt++;
        insert(curr);
        return curr->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (cache.count(key)) {
            Node* curr = cache[key];
            curr->val = value;
            remove(curr);
            if (isEmpty(curr->cnt) && curr->cnt == minCnt)
                minCnt++;                           // fix: same minCnt logic as get
            curr->cnt++;
            insert(curr);
        } else {
            if ((int)cache.size() == cap) {         // fix: eviction was missing entirely
                Node* lru = freq[minCnt].first->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value, 1);
            cache[key] = newNode;
            insert(newNode);
            minCnt = 1;                             // fix: new node always has cnt=1
        }
    }
};