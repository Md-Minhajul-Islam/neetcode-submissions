class MyCircularQueue {
public:
    vector<int> queue;
    int front, rear, sz;
    MyCircularQueue(int k) {
        queue = vector<int>(k, -1);
        sz = k;
        front = rear = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        queue[rear] = value;
        rear = (rear+1)%sz;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        queue[front] = -1;
        front = (front+1)%sz;
        return true;
    }
    
    int Front() {
        return queue[front];
    }
    
    int Rear() {
        return queue[(rear-1+sz)%sz];
    }
    
    bool isEmpty() {
        return queue[front] == -1;
    }
    
    bool isFull() {
        return queue[rear] != -1;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */