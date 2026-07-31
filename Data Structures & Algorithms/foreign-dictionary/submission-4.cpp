class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26,-1);
        int n=0;
        // First pass - mark all unique chars
        for (auto& word : words) for (char c : word) if (indegree[c-'a'] == -1) {indegree[c-'a'] = 0; n++; }
        for(int i = 0 ; i<words.size()-1 ; i++){
            int l = 0;
            bool found = false;
            while(l<words[i].length() && l<words[i+1].length()){
                
                if(words[i][l]!=words[i+1][l]){
                    auto& neighbors = adj[words[i][l]-'a'];
                    int to = words[i+1][l]-'a';
                    if (find(neighbors.begin(), neighbors.end(), to) == neighbors.end()) {
                        neighbors.push_back(to);
                        indegree[to]++;
                    }
                    found = true;
                    break;
                }
                l++;
            }
            if (!found && words[i].length() > words[i+1].length()) return "";
        }
        queue<int> q;
        string result;
        for(int i = 0  ; i<26; i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result+= (char) 'a'+node;
            for(int ne: adj[node]){
                indegree[ne]--;
                if(indegree[ne]==0) q.push(ne);
            }
        }

        if (result.size() == n) return result;
        else return "";

    }
};
