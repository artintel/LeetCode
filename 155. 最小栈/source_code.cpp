/*
 * @Author: Mayc
 * @Date: 2021-01-23 14:00:46
 * @LastEditTime: 2021-01-23 14:01:17
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\155. 最小栈\source_code.cpp
 * @这是一个漂亮的注释头
 */
class MinStack {
private:
    vector<int> ans;
    vector<int> Min;
    int _size;
public:
    /** initialize your data structure here. */
    MinStack() {
        _size = 0;
    }
    
    void push(int x) {
        ans.push_back(x);
        if(Min.empty()){
            Min.push_back(x);
        }
        else{
            if(Min[_size - 1] <= x){
                Min.push_back(Min[_size - 1]);
            }
            else{
                Min.push_back(x);
            }
        }
        _size++;
    }
    
    void pop() {
        ans.pop_back();
        Min.pop_back();
        _size--;
    }
    
    int top() {
        return ans[_size - 1];
    }
    
    int getMin() {
        return Min[_size - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */