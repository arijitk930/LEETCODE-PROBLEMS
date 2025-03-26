class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int j=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+j-nums[i];
            j++;
        }
        return sum;
    }
};