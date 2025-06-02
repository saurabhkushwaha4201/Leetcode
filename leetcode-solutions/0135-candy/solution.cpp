class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int count = n;
        int i = 1;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                i++;
                continue;
            }

            // increasing slope
            int peak = 0;
            while(ratings[i] > ratings[i-1])
            {
                peak++;
                i++;
                count += peak;
                if(i==n)
                return count;
            }

            // decreasing slope
            int dip = 0;
            while(i<n && ratings[i]<ratings[i-1])
            {
                dip++;
                i++;
                count += dip;
            }
            count -= min(peak,dip);
        }
        return count;
    }
};
