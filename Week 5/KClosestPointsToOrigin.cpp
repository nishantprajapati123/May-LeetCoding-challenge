class Solution {
public:
    float dist(vector<int>&p)
    {
        return sqrt((p[0]*p[0]) + (p[1]*p[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<vector<int> >ans;
        if(points.size() == 0)
            return ans;
        
        vector<pair<float, int> >distance;
        for(int i=0;i<points.size();i++)
        {
            distance.push_back({dist(points[i]), i});
        }
        
        sort(distance.begin(), distance.end());
        for(int i=0;i<K;i++)
        {
            ans.push_back(points[distance[i].second]);
        }
        return ans;
    }
};