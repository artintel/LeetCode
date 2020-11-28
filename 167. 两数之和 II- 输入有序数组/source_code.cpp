class Solution {
public:
    int BinarySearch(const vector<int>& numbers, int l, int r, int target){
        if(r - l < 2) return l;
        int mid = (l + r) >> 1;
        if(target < numbers[mid]) return BinarySearch(numbers, l, mid, target);
        else return BinarySearch(numbers, mid, r, target);
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int mid_target = BinarySearch(numbers, 0, numbers.size(), target);
        int i = 0, j = mid_target;
        while(i >= 0 && j < numbers.size()){
            if(numbers[i] + numbers[j] == target){
                ans.emplace_back(min(i, j) + 1);
                ans.emplace_back(max(i, j) + 1);
                break;
            }
            else if (numbers[i] + numbers[j] > target){
                j--;
            }
            else i++;
        }
        return ans;
    }
};

#官方
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leet-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。