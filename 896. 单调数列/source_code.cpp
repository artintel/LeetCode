class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n == 0 || n == 1) return true;
        int i = 1;
        if(A[0] == A[n - 1]){
            while(i < n){
                if(A[i] != A[0]) return false;
                i++;
            }
        }
        else if(A[0] < A[n - 1]){
            i = 1;
            while(i < n){
                if(A[i] < A[i - 1]) return false;
                i++;
            }
        }
        else if(A[0] > A[n - 1]){
            i = 1;
            while(i < n){
                if(A[i] > A[i - 1]) return false;
                i++;
            }
        }
        return true;
    }
};