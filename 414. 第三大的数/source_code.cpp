# 归并排序
class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        int left_len = mid - l + 1;
        vector<int> ans(left_len );
        int ans_index = 0;
        for (int i = l; i <= mid; i++) {
            ans[ans_index++] = nums[i];
        }
        //重新置为0
        ans_index = 0;
        int M = mid + 1;
        int L = l;

        while (ans_index < left_len && M <= r) {
            if (ans[ans_index] < nums[M]) {
                nums[L++] = nums[M++];
            }
            else {
                nums[L++] = ans[ans_index++];
            }
        }
        while (ans_index < left_len) {
            nums[L++] = ans[ans_index++];
        }
        while (M <= r) {
            nums[L++] = nums[M++];
        }
        return;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l == r) return;
        int mid = (r + l) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
        return;
    }

    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        if (n <= 2) return nums[0];
        else {
            int count = 1;
            int i;
            for (i = 1; i < n; i++) {
                if (nums[i] != nums[i - 1]) {
                    count++;
                }
                if (count == 3) break;
            }
            if (count == 3) return nums[i];
            else return nums[0];
        }
        return -1;
    }
};

// hash set, actually it is O(Nlg3) = O(N), auto filter duplication
class Solution3 {
public:
    int thirdMax(vector<int>& nums) {
        set<int> topThree;
        for (const auto& num : nums) {
            topThree.insert(num);
            if (topThree.size() > 3) {
                topThree.erase(topThree.begin());
            }
        }

        assert(!topThree.empty());
        return topThree.size() < 3 ? *topThree.rbegin() : *topThree.begin();
    }
};

// priority_queue, actually it is O(Nlg3) = O(N)
class Solution4 {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> visited;
        priority_queue<int, vector<int>, greater<int>> topThree;
        for (const auto& num : nums) {
            if (visited.count(num)) {
                continue;
            }
            visited.insert(num);
            topThree.push(num);
            if (topThree.size() > 3) {
                topThree.pop();
            }
        }

        assert(!topThree.empty());
        if (topThree.size() == 3) {
            return topThree.top();
        }

        int largest;
        while (!topThree.empty()) {
            largest = topThree.top();
            topThree.pop();
        }

        return largest;
    }
};

作者：jyj407
链接：https://leetcode-cn.com/problems/third-maximum-number/solution/zhong-gui-zhong-ju-qiu-di-san-da-de-shu-4chong-bu-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。