class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> q;
            int len = nums.size();
            for(int i=0;i<len;i++){
                if(nums[i] != 0){
                    q.push(nums[i]);
                }
            }
            while(q.size()<len){
                q.push(0);
            }
            for(int i=0;i<len;i++){
                nums[i] = q.front();
                q.pop();
            }
    }
};

作者：chen-532
链接：https://leetcode-cn.com/problems/move-zeroes/solution/yong-dui-kuai-su-jie-jue-by-chen-532/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};