class Solution {
public:
    int getLucky(string s, int k) 
    {
        // Step 1: Convert the string to a string of digit positions
        string digits = "";
        for(char c : s)
        {
            int position_number = c - 'a' + 1;
            digits += to_string(position_number);
        }
        
        // Step 2: Apply the transformation k times
        int sum = 0;
        while(k > 0)
        {
            sum = 0;
            for(char digit : digits)
            {
                sum += digit - '0';  // Convert character to integer and add to sum
            }
            digits = to_string(sum);  // Update digits with the new sum as a string
            k--;
        }
        
        return sum;
    }
};

