class Solution {
public:
    string vts(vector<int> v){
        string ans="";
        for(int i:v){
            ans+=to_string(i)+' ';
            
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        vector<vector<string>> ans;
        for(auto& i:strs){
            vector<int> fit(26,0);
            for(char j:i){    
                fit[j-'a']++;
            }

            res[vts(fit)].push_back(i);            
        }
        for(auto& pair:res){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
