/*
 * @Author: Mayc
 * @Date: 2021-02-08 10:21:07
 * @LastEditTime: 2021-02-08 10:21:16
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\208. 实现 Trie (前缀树)\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Trie {
private:
    bool flag;
    Trie* next[26] = { nullptr };
public:
    /** Initialize your data structure here. */
    Trie() {
        flag = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(const auto& elem : word){
            if( root->next[elem - 'a'] == nullptr ){
                root->next[elem - 'a'] = new Trie();
            }
            root = root->next[elem - 'a'];
        }
        root->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(auto elem : word){
            if( root->next[elem - 'a'] == nullptr ){
                return false;
            }
            root = root->next[elem - 'a'];
        }
        if( root->flag == true ) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(auto elem : prefix){
            if( root->next[elem - 'a'] == nullptr ){
                return false;
            }
            root = root->next[elem - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */