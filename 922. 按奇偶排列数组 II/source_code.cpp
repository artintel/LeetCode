class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int i = 0, j = n - 1;
        while(i < n && j >= 1){
            if(A[i] % 2 != 0 && A[j] % 2 != 1){
                swap(A[i], A[j]);
                i += 2;
                j -= 2;
                continue;
            }
            if(A[i] % 2 == 0){
                i += 2;
            }
            if(A[j] % 2 == 1){
                j -= 2;
            }
        }
        return A;
    }
};