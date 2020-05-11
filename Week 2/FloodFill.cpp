class Solution {
public:
    void fill(int x, int y, vector<vector<int> >&image, vector<vector<bool> >&vis, int color, int newColor)
    {
        if(x < 0 || y < 0 || x >= image.size() || y >= image[0].size())
            return ;
        
        if(image[x][y] == color && !vis[x][y])
        {
            vis[x][y] = true;
            image[x][y] = newColor;
            fill(x-1, y, image, vis, color, newColor);  //up
            fill(x, y+1, image, vis, color, newColor);  //right
            fill(x+1, y, image, vis, color, newColor);  //down
            fill(x, y-1, image, vis, color, newColor);  //left
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int color = image[sr][sc];
        vector<vector<bool> >vis(image.size(), vector<bool>(image[0].size(), false));
        fill(sr, sc, image, vis, color, newColor);
        
        // for(auto e: image)
        // {
        //     for(auto x:e)
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        return image;
    }
};