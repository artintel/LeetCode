/*
 * @Author: Mayc
 * @Date: 2021-01-25 15:30:03
 * @LastEditTime: 2021-01-25 15:30:12
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 41. 数据流中的中位数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if( ( ( min.size() + max.size() ) & 1 ) == 0 ){
            if( max.size() > 0 && max[0] > num ){
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else{
            if( min.size() > 0 && min[0] < num ){
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }
    
    double findMedian() {
        for( auto elem : max ){
            cout << elem << " ";
        }
        cout << endl;
        int _size = min.size() + max.size();
        if(_size == 0) return 0.0;
        double median = 0.0;
        if( ( _size & 1 ) == 1 ){
            median = min[0];
        }
        else median = double(min[0] + max[0]) / 2;
        return median;
    }
private:
    vector<int> max;
    vector<int> min;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */