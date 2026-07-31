class Solution {
public:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& adj){
        visited[i]=true;
        for(int ne: adj[i]){
            if(!visited[ne]){
                dfs(ne,visited,adj);
            }
            
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // unordered_map<pair<int,int>,bool> visited;
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};
