class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0, right = height.size() - 1;
        while(left < right){
            max_area = max(max_area, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
    }
};