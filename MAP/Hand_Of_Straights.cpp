class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0){
            return false;
        };

        // create order map 
        map<int,int>m;

        for(int &num : hand){
            m[num]++;
        }

        while(!m.empty()){
            // here first element represent element and second element represent their frequency
            int curr = m.begin()->first; 

            for(int i =0;i<groupSize;i++){
                if(m[curr +i] == 0){
                    return false;
                }
                m[curr+i]--;
                if(m[curr+i] < 1){
                    m.erase(curr+i);
                }
            }
        }
        return true;
    }
};