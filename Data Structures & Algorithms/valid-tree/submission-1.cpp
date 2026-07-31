class Solution {
public:
    bool dfs(int i,int parent, vector<bool>& visited,vector<vector<int>>& adj){
        visited[i] = true;
        for(int ne: adj[i]){
            if(!visited[ne]){if(dfs(ne,i,visited,adj)) return true;}
            else if(parent!=ne) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        for(int i = 0; i<n ; i++){
            if(!visited[i]){
                if(edges.size()!=n-1 || dfs(i,-1,visited,adj)) return false;
            }
        }
        return true;
    }
};
