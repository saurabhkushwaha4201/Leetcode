class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        // Get the sizes of the two vectors
        int m = nums1.size();
        int n = nums2.size();
        
        // Resize nums1 to hold all elements from both nums1 and nums2
        nums1.resize(m + n); // Ensure nums1 has enough space for the merged result

        // Initialize pointers
        int i = m - 1; // Pointer for the last valid element in the original nums1
        int j = n - 1; // Pointer for the last element in nums2
        int k = m + n - 1; // Pointer for the end of the merged nums1

        // Merge nums2 into nums1 from the end
        while (i >= 0 && j >= 0) 
        {
            // Compare elements from the end of nums1 and nums2
            if (nums1[i] > nums2[j]) 
            {
                // Place the larger element at the end of nums1
                nums1[k--] = nums1[i--];
            } 
            else 
            {
                // Place the larger element from nums2 at the end of nums1
                nums1[k--] = nums2[j--];
            }
        }
        
        // Copy any remaining elements from nums2 into nums1
        // (elements from nums1 are already in place if j < 0)
        while (j >= 0) 
        {
            nums1[k--] = nums2[j--];
        }

        // Calculate the median
        int totalSize = m + n; // Total number of elements in the merged array
        
        // Check if the total size is even or odd
        if (totalSize % 2 == 0) 
        {
            // If even, median is the average of the two middle elements
            int mid1 = totalSize / 2; // Index of the second middle element
            int mid2 = mid1 - 1;      // Index of the first middle element
            // Compute the median as the average of these two elements
            double ans = (nums1[mid1] + nums1[mid2]) / 2.0;
            return ans;
        } 
        else 
        {
            // If odd, median is the middle element
            int mid = totalSize / 2; // Index of the middle element
            return nums1[mid];
        }
    }
};
