class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n);
        for(int i = 0; i < leftChild.size(); i++){
            if(leftChild[i] != -1){
                indegree[leftChild[i]]++;
                if(indegree[leftChild[i]] > 1){
                    return false;
                }
            }
            if(rightChild[i] != -1){
                indegree[rightChild[i]]++;
                if(indegree[rightChild[i]] > 1){
                    return false;
                }  
            }
        }
        
        
        int root = -1;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                if(root != -1){
                    return false;
                }
                root = i;
            }
        }
        if(root == -1){
            return false;
        }
        
        vector<int> visited(n);
        dfs(root, leftChild, rightChild, visited);
        for(int i: visited){
            if(i == 0){
                return false;
            }
        }
        return true;
    }
    
    void dfs(int i, vector<int>& leftChild, vector<int>& rightChild, vector<int>& visited){
        if(i == -1 || visited[i] == 1){
            return;
        }
        else{
            visited[i] = 1;
            dfs(leftChild[i], leftChild, rightChild, visited);
            dfs(rightChild[i], leftChild, rightChild, visited);
        }
    }
    
};