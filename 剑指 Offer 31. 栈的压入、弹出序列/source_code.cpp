/*
 * @Author: Mayc
 * @Date: 2021-01-14 14:55:23
 * @LastEditTime: 2021-01-14 14:55:33
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 31. 栈的压入、弹出序列\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> ans;
        int index = 0;
        int i = 0;
        while(i < pushed.size()){
            if(!ans.empty()){
                if(ans.top() == popped[index]){
                    index++;
                    ans.pop();
                    continue;
                }
            }
            if(pushed[i] != popped[index]){
                ans.push(pushed[i++]);
            }
            else if(pushed[i] == popped[index]){
                i++;
                index++;
            }
        }
        while(!ans.empty()){
            if(ans.top() == popped[index]){
                ans.pop();
                index++;
            }
            else return false;
        }
        return true;
    }
};