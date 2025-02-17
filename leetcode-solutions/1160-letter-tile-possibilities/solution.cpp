class Solution {
public:
    int count = 0;
    void solve(vector<int>&vec)
    {
        count++;

        for(int i =0;i<26;i++)
        {
            if(vec[i]==0)
            continue;

            vec[i]--;
            
            solve(vec);
            vec[i]++;
            
        }
    }
    int numTilePossibilities(string tiles) 
    {
        vector<int>vec(26,0);
        for(char ch : tiles)
        {
            vec[ch-'A']++;
        }
        solve(vec);

        return count - 1;
        
    }
};
