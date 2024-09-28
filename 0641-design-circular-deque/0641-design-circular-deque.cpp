class MyCircularDeque {
public:
    const int k;
    vector<int> q;
    int size = 0;
    int front = 0;
    int rear;
    MyCircularDeque(int k): k(k), q(k), rear(k - 1){
        
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front = (--front + k) % k;
        q[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = ++rear % k;
        q[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front = ++front % k;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (--rear + k)%k;
        size--;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : q[front];
    }
    
    int getRear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */