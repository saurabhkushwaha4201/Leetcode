class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>result(n);
        int maxEnergy = INT_MIN;
        for(int i = n-1;i>=0;i--){
            result[i] = (i+k<n? result[i+k] : 0) + energy[i];
        
        }
        for(int i = 0;i<n;i++){
            maxEnergy = max(maxEnergy,result[i]);
        }
        return maxEnergy;
    }
};
