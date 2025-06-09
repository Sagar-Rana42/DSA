#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr{1,2,4,5,8,6,4,3,2,3,4,0,0,0,0,0};

    int n = arr.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
       
    }
    // for some optimisation 
    for(int i=0;i<n;i++){
        bool isSorted = true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                isSorted = false;
                swap(arr[j], arr[j+1]);
            }
        }
        // it means all element are sorted 
        if(isSorted){
            break;
        }
       
    }

    cout<<"printing value after sorting "<<endl;
    for(auto num : arr){
        cout<<num<<" ";
    }

    return 0;
}