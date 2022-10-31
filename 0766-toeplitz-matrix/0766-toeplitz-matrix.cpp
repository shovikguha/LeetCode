class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            int tempi = i;
            int j = 0;
            int prev =matrix[tempi][j];
            
            while(tempi < m && j < n){
                if(matrix[tempi][j] != prev){
                    return false;
                }
                prev = matrix[tempi][j];
                tempi++;
                j++;
            }
        }
        
        for(int j = 1; j < n; j++){
            int tempj = j;
            int i = 0;
            int prev =matrix[i][tempj];
            
            while(i < m && tempj < n){
                if(matrix[i][tempj] != prev){
                    return false;
                }
                prev = matrix[i][tempj];
                tempj++;
                i++;
            }
        }
        
        return true;
    }
};