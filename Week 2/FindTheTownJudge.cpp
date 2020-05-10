class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int indeg[N+1];
        int outdeg[N+1];
        memset(indeg, 0, sizeof(indeg));
        memset(outdeg, 0, sizeof(outdeg));
        for(auto &trusts: trust)
        {
            outdeg[trusts[0]]++;
            indeg[trusts[1]]++;
        }
        
        for(int i=1;i<=N;i++)
        {
            if(!outdeg[i] && indeg[i]==N-1) return i;
        }
        
        return -1;
    }
};