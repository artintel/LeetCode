class MaxQueue {
private:
    int _size;
    deque<int> temp;
    queue<int> Q;
public:
    MaxQueue() {
        _size = 0;
    }
    
    int max_value() {
        if( _size == 0 ) return -1;
        return temp.front();
    }
    
    void push_back(int value) {
        while( !temp.empty() && value > temp.back() ){
            temp.pop_back();
        }
        temp.push_back(value);
        Q.push(value);
        _size++;
    }
    
    int pop_front() {
        if( _size == 0 ) return -1;
        int num = Q.front();
        if( num == temp.front() ) temp.pop_front();
        Q.pop();
        _size--;
        return num;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */