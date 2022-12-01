class Trie {
    
struct TrieNode{
    vector<TrieNode*> children = vector<TrieNode*>(26);
    bool end;
};
    
public:
    TrieNode* root = new TrieNode();
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        int n = word.length();
        for(int i = 0; i < n; i++){
            if(!curr -> children[word[i] - 'a']){
                curr -> children[word[i] - 'a'] = new TrieNode();
            }
            curr = curr -> children[word[i] - 'a'];
        }
        curr -> end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int n = word.length();
        for(int i = 0; i < n; i++){
            if(!curr -> children[word[i] - 'a']){
                return false;
            }
            curr = curr -> children[word[i] - 'a'];
        }
        return curr -> end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int n = prefix.length();
        for(int i = 0; i < n; i++){
            if(!curr -> children[prefix[i] - 'a']){
                return false;
            }
            curr = curr -> children[prefix[i] - 'a'];
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