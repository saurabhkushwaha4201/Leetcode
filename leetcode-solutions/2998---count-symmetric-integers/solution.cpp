class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low;i<=high;i++)
        {
            string temp = to_string(i);
            int length = temp.length();
            if(length&1)
            {
                continue;
            }
            int firstSum = 0;
            int secondSum = 0;
            int left = 0;
            int right = length-1;
            while(left<(length/2))
            {
                firstSum += ('0'+temp[left]);
                secondSum += ('0'+temp[right]);
                left++;
                right--;
            }
            if(firstSum==secondSum)
            count++;
        }
        return count;
    }
};
