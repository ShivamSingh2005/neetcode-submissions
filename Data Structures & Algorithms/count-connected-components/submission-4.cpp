class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a , int b){
        int bossA = find(a);
        int bossB = find(b);
        if(bossA!=bossB) parent[bossA] = bossB;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // int n = edges.size();
        parent.resize(n);
        for(int i = 0; i<n ; i++) parent[i]=i;
        for(auto& edge: edges){
            unite(edge[0],edge[1]);
        }
        int ans  = 0;
        for(int i = 0; i<n; i++){
            if(parent[i]==i) ans++;
        }
        return ans;
    }
};

