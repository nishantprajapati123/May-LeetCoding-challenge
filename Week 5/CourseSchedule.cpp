// Find cycle in DAG
class Solution {
public:
    bool isCycle(vector<int>g[], vector<bool>&vis, vector<bool>&currStack, int node)
    {
        vis[node] = true;
        currStack[node] = true;
        
        for(int child: g[node])
        {
            if(!vis[child] && isCycle(g,vis,currStack,child))
                return true;
            else if(currStack[child])
                return true;
        }
        
        currStack[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>g[numCourses];
        
        for(int i=0;i<prerequisites.size();i++)
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<bool>currStack(numCourses,false);
        vector<bool>vis(numCourses, false);
        
        for(int i=0;i<numCourses;i++)
            if(isCycle(g,vis,currStack,i))
                return false;
        
        return true;
    }
};