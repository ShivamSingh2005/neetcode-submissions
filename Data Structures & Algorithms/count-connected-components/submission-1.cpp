class Solution {
public:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& edges){
        visited[i]=true;
        for(auto& edge: edges){
            if(edge[0]==i && !visited[edge[1]]){
                dfs(edge[1],visited,edges);
            }
            else if(edge[1]==i && !visited[edge[0]]){
                dfs(edge[0],visited,edges);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // unordered_map<pair<int,int>,bool> visited;
        vector<bool> visited(n,false);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i,visited,edges);
                count++;
            }
        }
        return count;
    }
};
