/*
 * @Author: Mayc
 * @Date: 2021-01-14 13:54:38
 * @LastEditTime: 2021-01-14 13:54:45
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 30. 包含min函数的栈\source_code.cpp
 * @这是一个漂亮的注释头
 */
class MinStack {
private:
    int size;
    vector<int> mainstack;
    vector<int> tempstack;
public:
    /** initialize your data structure here. */
    MinStack() {
        size = -1;
    }
    
    void push(int x) {
        if( size == -1 ){
            mainstack.push_back(x);
            tempstack.push_back(x);
            size++;
        }
        else{
            if( x < tempstack[size] ){
                tempstack.push_back(x);
            }
            else{
                tempstack.push_back(tempstack[size]);
            }
            mainstack.push_back(x);
            size++;
        }
    }
    
    void pop() {
        if(size == -1) return;
        mainstack.pop_back();
        tempstack.pop_back();
        size--;
    }
    
    int top() {
        return mainstack[size];
    }
    
    int min() {
        return tempstack[size];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */