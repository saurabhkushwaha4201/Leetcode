class Solution {
public:
    int firstOccurence(vector<int>&nums,int start,int end,int target)
        {
            int ans=-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]==target)
                {
                    ans=mid;
                    end=mid-1;
                }
                else if(nums[mid]>target)
                {
                    end=mid-1;
                }
                else if(nums[mid]<target)
                {
                    start=mid+1;
                }
            }
            return ans;
        }
   int lastOccurence(vector<int>&nums,int start,int end,int target)
    {
        int ans=-1;
        while(start<=end)
        {
            
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
        }
        return ans;
    }    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int start=0;
        int end=nums.size()-1;
        
        pair<int,int>p;
        p.first=firstOccurence(nums,0,nums.size()-1,target);
        p.second=lastOccurence(nums,0,nums.size()-1,target);
        vector<int> ans;
        ans.push_back(p.first);
        ans.push_back(p.second);
        return ans;
    }
};
