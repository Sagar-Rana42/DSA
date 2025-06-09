#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr{1,2,4,5,8,6,4,3,2,3,4,0,0,0,0,0};

    int n = arr.size();

    for(int i=0;i<n;i++){
        int minValue = i;
        for(int j=i+1;j<n;j++){
            if(arr[minValue] > arr[j]){
                minValue = j;
            }
        }
        if(i != minValue){
            swap(arr[minValue] , arr[i]);
        }
    }
    cout<<"printing value after sorting "<<endl;
    for(auto num : arr){
        cout<<num<<" ";
    }

    return 0;
}