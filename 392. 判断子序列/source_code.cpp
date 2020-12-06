class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        stack<char> S;
        for(char elem : s){
            S.push(elem);
        }
        for(int i = t.length() - 1; i >= 0; i--){
            if(t[i] == S.top()){
                S.pop();
                if(S.size() == 0) break;
            }
        }
        return S.size() == 0;
    }
};