class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>>result;
        map<int,int>mpp;
        for(int i =0;i<m;i++)
        {
            int id = nums1[i][0];
            mpp[id] = nums1[i][1];;
        }
        for(int j = 0;j<n;j++)
        {
            int id = nums2[j][0];
            if(mpp.find(id)!=mpp.end())
            {
                mpp[id] = (nums2[j][1]+mpp[id]);
            }
            else
            mpp[id]=nums2[j][1];
        }
        for(auto it:mpp)
        {
            result.push_back({it.first,it.second});
        }
        return result;
        
    }
};
