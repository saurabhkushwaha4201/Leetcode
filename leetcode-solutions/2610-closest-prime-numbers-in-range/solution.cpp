class Solution {
public:
    vector<int>prime(int left,int limit)
    {
        vector<bool>isPrime(limit+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= limit; i++) 
        {
            if (isPrime[i]) 
            {
                for (int j = i * i; j <= limit; j += i) 
                {
                    isPrime[j] = false;
                }
            }
        }
        vector<int>primes;
        for(int i =left;i<=limit;i++)
        {
            if(isPrime[i])
            primes.push_back(i);
        }
        return primes;
    }
    vector<int> closestPrimes(int left, int right) 
    {
        vector<int>isPrime = prime(left,right);
        if(isPrime.size()<2)
        return {-1,-1};
        int mini = INT_MAX;
        int a = -1;
        int b = -1;
        for(int i =1;i<isPrime.size();i++)
        {
            int difference = isPrime[i] - isPrime[i-1];
            if(mini > difference)
            {
                mini = difference;
                a = isPrime[i-1];
                b = isPrime[i];
            }
        }
        return {a,b};
    
        
    }
};
