/*
 * @Author: Mayc
 * @Date: 2021-02-18 14:21:24
 * @LastEditTime: 2021-02-18 14:33:49
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 57 - II. 和为 s 的连续正数序列\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    void trace_back( vector<vector<int>>& ans, vector<int>& temp, int start, int& count, const int& target ){
        if( count == target ){
            ans.push_back( temp );
            temp.resize(0);
            count = 0;
            return;
        }
        if( count > target ) {
            temp.resize(0);
            count = 0;
            return;
        }
        temp.push_back( start );
        count += start;
        trace_back( ans, temp, start + 1, count, target );
    }

    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int count = 0;
        for(int i = 1; i <= target / 2; i++ ){
            trace_back( ans, temp, i, count, target );
        }
        return ans;
    }
};

//剑指 Offer
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        if( target <= 2 ) {
            temp.push_back( 1 );
            ans.push_back( temp );
            return ans;
        }
        int mid = (target + 1) / 2;
        int little = 1;
        int big = 2;
        int count = little + big;
        while( little < mid ){
            if(count == target){
                for( int i = little; i <= big; i++ ){
                    temp.push_back( i );
                }
                ans.push_back( temp );
                temp.resize( 0 );
            }
            while( count > target && little < mid ){
                count -= little;
                little++;
                if( count == target ){
                    for(int i = little; i <= big; i++ ){
                        temp.push_back( i );
                    }
                    ans.push_back( temp );
                    temp.resize( 0 );
                }
            }
            big++;
            count += big;
        }
        return ans;
    }
};class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        if( target <= 2 ) {
            temp.push_back( 1 );
            ans.push_back( temp );
            return ans;
        }
        int mid = (target + 1) / 2;
        int little = 1;
        int big = 2;
        int count = little + big;
        while( little < mid ){
            if(count == target){
                for( int i = little; i <= big; i++ ){
                    temp.push_back( i );
                }
                ans.push_back( temp );
                temp.resize( 0 );
            }
            while( count > target && little < mid ){
                count -= little;
                little++;
                if( count == target ){
                    for(int i = little; i <= big; i++ ){
                        temp.push_back( i );
                    }
                    ans.push_back( temp );
                    temp.resize( 0 );
                }
            }
            big++;
            count += big;
        }
        return ans;
    }
};