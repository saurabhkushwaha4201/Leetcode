class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        map<char,int>mpp;
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]]++;
        }
        priority_queue<char> pq;
        for (auto& [ch, count] : mpp) {
            pq.push(ch);
        }
        string result;
        while(!pq.empty())
        {
            char ch = pq.top();
            int charLength = mpp[ch];
            pq.pop();
            int toAppend = min(charLength,repeatLimit);
            result.append(toAppend,ch);
            mpp[ch] -= toAppend;
            
            if(mpp[ch] > 0 && !pq.empty())
            {
                char nextCh = pq.top();
                pq.pop();
                result.push_back(nextCh);
                mpp[nextCh]--;
                if(mpp[nextCh]>0)
                {
                    pq.push(nextCh);
                }
                pq.push(ch);
            }
           
        }
        return result;
        
    }
};
