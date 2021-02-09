/*
 * @Author: Mayc
 * @Date: 2021-02-09 11:45:18
 * @LastEditTime: 2021-02-09 11:45:28
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\207. 课程表\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool flag = true;
public:

    void dfs(int i){
        visited[i] = 1;
        for( int v : edges[i] ){
            if( visited[v] == 0 ){
                dfs(v);
                if( !flag ) return;
            }
            else if( visited[v] == 1 ){
                flag = false;
                return;;
            }
        }
        visited[i] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& edge : prerequisites){
            edges[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < numCourses && flag; i++){
            dfs(i);
        }
        return flag;
    }
};