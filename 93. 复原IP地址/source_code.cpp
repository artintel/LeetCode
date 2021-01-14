/*
 * @Author: Mayc
 * @Date: 2021-01-14 11:12:40
 * @LastEditTime: 2021-01-14 11:12:48
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\93. 复原IP地址\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
private:
    static constexpr int group = 4;

private:
    vector<int> Group;
    vector<string> ans;
public:

    void dfs(const string& s, int GroupId, int group_index, int& length){
        if( GroupId == group ){
            if( group_index == length ){
                string temp;
                int count = 0;
                for(auto elem : Group){
                    temp += to_string(elem);
                    if(count < group - 1) {
                        count++;
                        temp += ".";
                    }
                }
                ans.push_back(temp);
            }
            return;
        }
        if( group_index == length ) return;
        if( s[group_index] == '0' ) {
            Group[GroupId] = 0;
            dfs(s, GroupId + 1, group_index + 1, length);
        }
        int addr = 0;
        for(int i = group_index; i < length; i++){
            addr = addr * 10 + ( s[i] - '0' );
            if(addr > 0 && addr <= 255){
                Group[GroupId] = addr;
                dfs(s, GroupId + 1, i + 1, length);
            }
            else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        Group.resize(group);
        dfs(s, 0, 0, n);
        return ans;
    }
};