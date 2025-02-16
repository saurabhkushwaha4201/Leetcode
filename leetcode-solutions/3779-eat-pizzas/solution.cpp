class Solution {
public:
    long long maxWeight(vector<int>& pizzas) 
{
    sort(pizzas.begin(), pizzas.end());
    int n = pizzas.size();
    int days = n/4;
    int oddDays  = (days+1)/2;
    int evenDays = days - oddDays;
    long long totalWeight = 0;
    int left = n-1;
    int right = 0;
    for(int i =0;i<oddDays;i++)
        {
            totalWeight += pizzas[left];
            left--;
            right += 3;
        }

    for(int i = 0;i<evenDays;i++)
        {
            int num = pizzas[left];
            left--;
            int num2 = pizzas[left];
            left--;
            right +=2;
            totalWeight += num2;
        }
    
    return totalWeight;
    
    
        
    }
};
