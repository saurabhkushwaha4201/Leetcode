class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mpp;
        int count = 0;
        for(int i = 0;i<words.size();i++)
        {
            string temp = words[i];
            string temp2 = temp;
            reverse(temp2.begin(),temp2.end());
            if(mpp[temp2]>0)
            {
                count +=4;
                mpp[temp2]--;
            }
            else
            {
                mpp[temp]++;
            }
        }
        
        for(auto it:mpp)
        {
            string temp = it.first;
            int freq = it.second;
            if(temp[0]==temp[1] && freq>0)
            {
                count += 2;
                break;
            }
        }
        return count;
    }
};
