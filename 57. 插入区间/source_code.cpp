class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>> ans){
        
        vector<vector<int>> temp;
        int n = ans.size();
        for(int i = 0; i < n - 1; i++){
            
            if(ans[i][1] < ans[i + 1][0]){
                temp.push_back({ans[i][0], ans[i][1]});
            }
            else{
                ans[i + 1][0] = ans[i][0];
                ans[i + 1][1] = max(ans[i][1], ans[i + 1][1]);
            }
        }
        temp.push_back({ans[n - 1][0], ans[n - 1][1]});

        return temp;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end());

        intervals = merge(intervals);
        return intervals;
    }
};


# 官方
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};