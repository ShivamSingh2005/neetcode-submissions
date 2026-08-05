class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1, right = 1;
        vector<int> res(nums.size(),1);
        for(int i = 0; i<nums.size() ; i++){
            res[i]*=left;
            left*=nums[i];
            res[nums.size()-1-i]*=right;
            right*=nums[nums.size()-1-i];
        }
        // for(int i = nums.size()-1; i>=0 ; i--){
        //     res[i]*=right;
        //     right*=nums[i];
        // }
        return res;
    }
};
