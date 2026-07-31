class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i =  1 ; i<strs.size() ; i++ ){
            int j =0;
            for(j = 0 ; j<min(strs[i].length(),prefix.length()) ; j++){
                if(prefix[j]!=strs[i][j]) break;
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};