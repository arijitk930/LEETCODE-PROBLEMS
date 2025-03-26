class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxCnt = 0; // Add maxCnt to keep track of the maximum count of 1s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                maxCnt = max(maxCnt, cnt); // Update maxCnt with the highest count found so far
                cnt = 0; // Reset cnt when a 0 is found
            } else {
                cnt++; // Increment cnt if the element is 1
            }
        }
        maxCnt = max(maxCnt, cnt); // Ensure to update maxCnt after the loop
        return maxCnt;
    }
};
