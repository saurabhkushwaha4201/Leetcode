class Solution {
public:
    void helper(vector<int>&temp,int curr,int direction)
    {
        int n=temp.size();
        while(curr>=0 && curr<n)
        {
            if(temp[curr]==0)
                curr+=direction;
            else if(temp[curr]>0)
            {
                temp[curr]--;
                direction = - direction;
                curr += direction;
            }
        }
    }
    bool allZero(vector<int>&temp)
    {
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]!=0)
                return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                vector<int>temp=nums;
                helper(temp,i,1);
                if(allZero(temp))
                    count++;
                temp=nums;
                helper(temp,i,-1);
                if(allZero(temp))
                    count++;
            }
        }
        return count;
        
        
    }
};
