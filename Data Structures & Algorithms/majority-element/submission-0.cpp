class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;
        for(auto& data:mp){
            if(data.second>nums.size()/2) return data.first;
        }
        return 0;
    }
};