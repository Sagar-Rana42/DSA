#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

bool know(vector<vector<int>>&arr , int a, int b , int size ){
    if(arr[a][b] == 1){
        return true;
    }
    else{
        return false;
    }


}

int main(){
    vector<vector<int>>arr{ {0,1,0} , {0,0,0} , {0,1,0}}; // these are already given 
   // int arr[3][3] = {};
    int n[3] = {0,1,2};  // this is already given
    int size = sizeof(n) / sizeof(int);
    stack<int>s;

    for(int i = 0; i<size; i++){
        int value = n[i];
        s.push(value);
    }

    while(s.size()>1){
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        if(know(arr,a,b,size)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int celebraity = s.top();
    bool rowcheck = false;      //  SOME CODE WILL GET REMOVE FOR BEST APPROACH 
    int zerocount = 0;

    for(int i=0;i<size;i++){
        if(arr[celebraity][i] == 0 ){
            zerocount++;
        }
    }
    if(zerocount == size){
        rowcheck = true;
    }
    // column check 

    bool colcheck = false;
    int onecount = 0;
    for(int i=0;i<size;i++){
        if(arr[i][celebraity] == 1 ){
            onecount++;
        }
    }
    if(onecount == size-1){
        colcheck = true;
    }
    if(rowcheck == true && colcheck == true){
        cout<<"Celebraity is "<<celebraity<<endl;
    }
    else{
        cout<<"There is no celebraity "<<celebraity<<endl;;
    }



    // single element in stack may be celebraity  then verify it 

    
    return 0;
}