/*
 * @Author: Mayc
 * @Date: 2021-01-24 17:07:57
 * @LastEditTime: 2021-01-24 17:23:47
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 40. 最小的k个数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    int partition( vector<int>& arr, int start, int end, int k ){
        int i = start, j = end;
        int temp = arr[start];
        while( i < j ){
            while( i < j && arr[j] >= temp){
                j--;
            }
            if( i < j ){
                arr[i] = arr[j];
                i++;
            }
            while( i < j && arr[i] < temp ){
                i++;
            }
            if( i < j ){
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = temp;
        if(i == k - 1) return i;
        else {
            if( i < k - 1 ) return partition(arr, i + 1, end, k);
            else return partition( arr, start, i - 1, k );
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        if( arr.size() <= 0 || k <= 0 || k > arr.size()) return ans;
        int start = 0, end = arr.size() - 1;
        partition( arr, 0, end, k );
        for(int i = 0; i < k; i++){
            ans.emplace_back(arr[i]);
        }
        return ans;
    }
};

// 大顶堆

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

class Solution {
public:

    void GetLeastNumbers(const vector<int>& arr, intSet& temp, const int& k){
        temp.clear();
        vector<int>::const_iterator it = arr.begin();
        for(; it != arr.end(); it++){
            if(temp.size() < k){
                temp.insert(*it);
            }
            else{
                setIterator iter = temp.begin();
                if(*it < *iter){
                    temp.erase(temp.begin());
                    temp.insert(*it);
                }
            }
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        intSet temp;
        if( arr.size() <= 0 || k <= 0 || k > arr.size() ) return ans;
        GetLeastNumbers(arr, temp, k);
        for(int elem : temp){
            ans.emplace_back(elem);
        }
        return ans;
    }
};