class Solution {
public:
    double slope(vector<int>& point1, vector<int>&point2)
    {
        return ((double)(point2[1] - point1[1]))/((double)(point2[0] - point1[0]));
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int no_points = coordinates.size();
        //check for vertical lines
        bool vertical = true;
        
        int x = coordinates[0][0];
        for(auto &point: coordinates)
        {
            if(point[0] != x)
            {
                vertical = false;
                break;
            }
        }
        if(vertical)    return true;
        
        //check for horizontal line
        bool hori = true;
        int y = coordinates[0][1];
        for(auto &point: coordinates)
        {
            if(point[1] != y)
            {
                hori = false;
                break;
            }
        }
        if(hori)    return true;
        
        double s = slope(coordinates[0], coordinates[1]);
        for(int i=0;i<no_points-1;i++)
        {
            if(s != slope(coordinates[i], coordinates[i+1]))
                return false;
        }
        return true;
    }
};