class Solution {
    public:
        int findZinda(int i , int j , vector<vector<int>>& board){
    
            int ans = 0;
            int dx[8] = {-1,1,0,0,-1,-1,1,1};
            int dy[8] = {0,0,-1,1,-1,1,-1,1};
    
            for(int dir=0;dir<8;dir++){
                int newX = i + dx[dir];
                int newY = j + dy[dir];
    
                if((newX >= 0 && newX < board.size()) &&( newY >= 0 && newY < board[0].size())){
                    if(board[newX][newY] % 2== 1){
                        ans++;
                    }
                }
            }
            // cout<<"ans = "<<ans<<endl;
            return ans;
        }
        void gameOfLife(vector<vector<int>>& board) {
            
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){              
                    if(board[i][j] == 0){
                        int count = findZinda(i,j,board);
                        if(count == 3){
                            board[i][j] = 2;
                        }
                    }
                    else {
                        int count = findZinda(i,j,board);
                        if(count < 2){
                            board[i][j] = 3;
                        }
    
                        if(count > 3){
                            board[i][j] = 3;
                        }
                    }
    
      
                }
            }
    
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j] == 2){
                        board[i][j] = 1;
                    }
                    if(board[i][j] == 3){
                        board[i][j] = 0;
                    }
                }
            }
        }
    };