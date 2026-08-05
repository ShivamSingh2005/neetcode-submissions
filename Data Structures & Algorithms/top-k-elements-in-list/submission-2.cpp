class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int num : nums) count[num]++;
        vector<vector<int>> freq(nums.size()+1);
        for(auto& data: count){
            freq[data.second].push_back(data.first);
        }
        vector<int> res;
        for(int i = freq.size()-1; i>=0 ; i--){
            for(int num: freq[i]){
                if(res.size()<k){
                    res.push_back(num);
                }
                else return res;
            }
        }
        return res;
    }
};
