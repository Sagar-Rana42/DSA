class Solution {
    public:
    int first_occurence(vector<int>arr , int target){
        int s =0;
        int e = arr.size()-1;
        int mid = s+(e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                e = mid-1;
            }
            if(target>arr[mid]){
               s = mid+1;
            }
            else if(target<arr[mid]){
              //  SEARCH IN MID 
                e = mid-1;
             }
            mid = s+(e-s)/2;
        }
        return ans;
    }
    int last_occurence(vector<int>arr , int target){
        int s =0;
        int e = arr.size()-1;
        int mid = s+(e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                s = mid+1;
            }
            if(arr[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int occurence1 = first_occurence(nums,target);
        int occurence2 = last_occurence(nums, target);

        // we can use stl ( lower bound and upper bound)
        return {occurence1,occurence2};
        
    }
};