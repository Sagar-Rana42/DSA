/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isValid(vector<vector<int>>& grid , int x , int y , int n){
        int val = grid[x][y];

        for(int i = x;i<x+n;i++){
            for(int j=y;j<y+n;j++){
                if(val != grid[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    Node* constr(vector<vector<int>>& grid , int x , int y , int n){
        if(isValid(grid,x,y,n)){
            return new Node(grid[x][y],true);
        }
        else{
            Node* root = new Node(1,false);
            root->topLeft = constr(grid,x,y,n/2);
            root->topRight = constr(grid,x,y+n/2,n/2);
            root->bottomLeft = constr(grid,x+n/2,y,n/2);
            root->bottomRight = constr(grid,x+n/2,y+n/2,n/2);
            return root;
        }


    }
   
    Node* construct(vector<vector<int>>& grid) {
        return constr(grid,0,0,grid.size());
    }
};