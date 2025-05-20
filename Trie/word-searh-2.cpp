class Solution {
public:
    vector<string>ans;
    int N,M;
    vector<vector<int>>dir = {{1,0},{-1,0} , {0,1} , {0,-1}};
    struct TrieNode{
        bool isTerminal;
        string word;
        TrieNode* child[26];
    };

    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode->isTerminal = false;
        newNode->word = "";
        for(int i=0;i<26;i++){
            newNode->child[i] = NULL;
        }

        return newNode;
    }

    

    void insert(string word,TrieNode* &root){
        TrieNode* start = root;
        for(auto ch : word){
            if(start->child[ch-'a'] == NULL){
                start->child[ch-'a'] = getNode();
            }
            start = start->child[ch-'a'];
        }
        start->word = word;
        start->isTerminal = true;
    }

    void searchWord(vector<vector<char>>& board , int i, int j, TrieNode* start ){
        if(i < 0 || i >= N || j < 0 || j >= M){
            return ;
        } 
        char ch = board[i][j];
        if(ch == '@' || start->child[ch-'a'] == NULL){
            return;
        }

        start = start->child[ch-'a'];
        if(start->isTerminal == true){
            ans.push_back(start->word);
            start->isTerminal = false;
        }

        board[i][j]   = '@';

        for(int k=0;k<4;k++){
            int newI = i+dir[k][0];
            int newJ = j+dir[k][1];
            searchWord(board,newI ,newJ, start);
        }
        board[i][j]   = ch;  
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       N = board.size();
       M = board[0].size();

       TrieNode* root = new TrieNode();
       for(auto const &word : words){
            insert(word,root);
        }
        TrieNode* start = root;

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(start->child[board[i][j] - 'a'] != NULL){
                    searchWord(board, i, j,start);
                }
            }
        }
        return ans;
        
    }
};