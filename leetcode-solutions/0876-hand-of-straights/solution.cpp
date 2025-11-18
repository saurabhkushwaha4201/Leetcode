class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>mpp;
        int n = hand.size();
        if(n % groupSize!=0){
            return false;
        }
        for(int i = 0;i<n;i++){
            mpp[hand[i]]++;
        }
        while(!mpp.empty()){
            int el = mpp.begin()->first;
            for(int i = 0;i<groupSize;i++){
                int curr = el + i;
                if (!mpp.count(curr)) return false;

                mpp[curr]--;
                if (mpp[curr] == 0) {
                    mpp.erase(curr);
                }
            }
        }
        return true;
    }
};
