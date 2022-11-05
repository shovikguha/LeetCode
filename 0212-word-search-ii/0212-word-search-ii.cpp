struct TrieNode{
    TrieNode* children[26] = {};
    string* word;
    
    void addWord(string& w){
        TrieNode* curr = this;
        for(char c : w){
            if(curr -> children[c - 'a'] == NULL){
                curr -> children[c  - 'a'] = new TrieNode(); 
            }
            curr = curr -> children[c - 'a'];
        }
        curr -> word = &w;
    }
    
};

class Solution {
public:
    int m;
    int n;
    vector<string> ans;
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        TrieNode node;
        
        for(string& s : words){
            node.addWord(s);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(i,j,&node, board);
            }
        }
        
        return ans;
    }
    
    void dfs(int i, int j, TrieNode* curr, vector<vector<char>>& board){
        if( i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.' || curr -> children[board[i][j] - 'a'] == NULL){
            return;
        }
        else{
            curr = curr -> children[board[i][j] - 'a'];
            if(curr -> word != NULL){
                ans.push_back(*curr -> word);
                curr->word = NULL;
            }
            char og = board[i][j];
            board[i][j] = '.';
            int dx[4] = {-1,1,0,0};
            int dy[4] = {0,0,-1,1};
            
            for(int k = 0; k < 4; k++){
                dfs(i + dx[k], j + dy[k], curr, board);
            }
            
            board[i][j] = og;
        }
    }
};