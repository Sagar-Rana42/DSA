
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == -1){
                    mat[i][j] = 10000000;  
                }
            }
        } // disturbing the flow 
        
        for(int via =0; via < n ; via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    mat[i][j] = min(mat[i][j] , mat[i][via] + mat[via][j]);
                }
            }
        }

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 10000000){
                    mat[i][j] = -1;  
                }
            }
        } 
        
        return;
        
    }
};
