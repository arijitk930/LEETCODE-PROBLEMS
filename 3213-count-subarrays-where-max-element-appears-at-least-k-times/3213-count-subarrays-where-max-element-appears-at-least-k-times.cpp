class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        
        long long count = 0;
        int left = 0;
        int maxCount = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxVal) {
                maxCount++;
            }

            // shrink the window until maxCount < k
            while (maxCount >= k) {
                if (nums[left] == maxVal) {
                    maxCount--;
                }
                left++;
            }

            // all subarrays ending at right and starting from 0 to left-1 are valid
            count += left;
        }

        return count;
    }
};