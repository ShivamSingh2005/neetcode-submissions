class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> sol;
        for(int i =0 ; i<nums.size();i++){
           sol[nums[i]]=i;
        }
        for(int i = 0 ; i<nums.size();i++){
            int diff = target-nums[i];
            if(sol.count(diff) && i!=sol[diff]){
                return {min(i,sol[diff]),max(i,sol[diff])};
            }
        }
    }
};
