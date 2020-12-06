class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum = new int[nums.size() + 1];
        sum[0] = 0;
        for(int i = 0; i < n; i++){
            sum.emplace_back(sum[i] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return (this->sum[j + 1] - this->sum[i]);
    }
private:
    int* sum;
};



class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum = new int[nums.size() + 1];
        sum[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            sum[i + 1] = sum[i] + nums[i];
        }
    }
    ~NumArray(){
        delete[] sum;
    }
    
    int sumRange(int i, int j) {
        return (sum[j + 1] - sum[i]);
    }
private:
    int* sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


