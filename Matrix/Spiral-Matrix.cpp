class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int row = matrix.size();
            int col = matrix[0].size();
    
            int top = 0;
            int down = row-1;
            int left = 0;
            int right = col-1;
    
            vector<int>ans;
            int dir = 0;
    
            while(ans.size() < row*col){
                if(dir == 0){
                    for(int i=top;i<= right;i++){
                        ans.push_back(matrix[top][i]);
                    }
                    top++;
                }
               
                else if(dir == 1){
                    for(int i=top;i<=down;i++){
                        ans.push_back(matrix[i][right]);
                    }
                    right--;
                } 
                else if(dir == 2){
                    for(int i=right;i>=left;i--){
                        ans.push_back(matrix[down][i]);
                    }
                    down--;
                }
                else if(dir == 3){
                    for(int i=down;i>=top;i--){
                        ans.push_back(matrix[i][left]);
                    }
                    left++;
                }
                dir = (dir + 1) % 4;
               
               
                
            }
            return ans;
        }
    };