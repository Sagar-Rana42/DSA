class Solution {
    public:
        void replaceX(int i , int j , vector<vector<bool>>&visited,vector<vector<char>>& board){
            queue<pair<int,int>>q;
            queue<pair<int,int>>q1;
            q.push({i,j});
            q1.push({i,j});
            visited[i][j] = true;
            bool isBoundry = false;
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
    
               
                if(x == 0 || x == board.size()-1 || y==0 || y== board[0].size()-1){
                    isBoundry = true;
                }
                int dx[4] = {-1,0,1,0} ;
                int dy[4] = {0,1,0,-1};
    
                for(int k=0;k<4;k++){
                    int newX = x + dx[k];
                    int newY = y + dy[k];
    
                    if((newX >=0 && newX < board.size()) &&  (newY>=0 && newY < board[0].size())  && board[newX][newY] == 'O' && !visited[newX][newY]){
                        q.push({newX,newY});
                        visited[newX][newY] = true;
                        q1.push({newX,newY});  
                        
                    }
                }
                
            }
            if(!isBoundry){
                while(!q1.empty()){
                    auto front = q1.front();
                    q1.pop();
    
                    board[front.first][front.second] =  'X';
                }
               
            }
    
        }
        void solve(vector<vector<char>>& board) {
            vector<vector<bool>>visited(board.size() , vector<bool>(board[0].size() , false));
    
            for(int i=1;i<board.size()-1;i++){
                for(int j=1;j<board[0].size();j++){
                    if(!visited[i][j] && board[i][j] == 'O'){
                        replaceX(i,j,visited,board);
                    }
                }
            }
        }
    };