class Solution {
public:
    bool dfs(int u, int c, vector<int>&color, vector<int>g[])
    {
        if(color[u] == 0)
            color[u] = c;
        else
            return color[u] == c;
        
        for(int child: g[u])
        {
            if(!dfs(child, -c, color, g))
                return false;
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        int n = 2005;
        vector<int>color(n,0);
        vector<int>g[n];
        
        for(int i=0;i<dislikes.size();i++)
        {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        for(int i=1;i<=N;i++)
        {
            if(color[i] == 0 && !dfs(i,1,color, g))
            {
                return false;
            }
        }
        return true;
    }
};