class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            if(n == 1){
                return ;
            }
            /*
                vector<vector<int>>ans(n,vector<int>(n,0));
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        ans[j][n-1-i]= matrix[i][j];
                    }
                }
    
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        matrix[i][j]= ans[i][j];
                    }
                }
            */
    
            // transpose the matrix 
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    swap(matrix[i][j] , matrix[j][i]);
                }
                
            }
            // revers the each row
    
            for(int i=0;i<n;i++){
                reverse(matrix[i].begin() , matrix[i].end());
            }
    
    
    
    
    
            
        }
    };