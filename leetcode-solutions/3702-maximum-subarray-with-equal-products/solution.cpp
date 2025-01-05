class Solution {
public:
// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate LCM of two numbers
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Function to calculate the product of elements in a vector
int product(const vector<int>& arr) {
    return accumulate(arr.begin(), arr.end(), 1, multiplies<int>());
}
    int maxLength(vector<int>& nums) 
{
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
        int currentGCD = nums[i];
        int currentLCM = nums[i];
        int currentProduct = nums[i];

        for (int j = i; j < n; ++j) {
            if (j > i) {
                currentGCD = gcd(currentGCD, nums[j]);
                currentLCM = lcm(currentLCM, nums[j]);
                currentProduct *= static_cast<long long>(nums[j]);
            }

            if (currentProduct == currentLCM * currentGCD) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
        
    }
};
