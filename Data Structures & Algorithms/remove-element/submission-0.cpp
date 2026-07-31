class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int a = 0;
        for(int b = 0 ; b<nums.size() ; b++){
            if(nums[b]!=val) nums[a++] = nums[b];
        }
        return a;
    }
};