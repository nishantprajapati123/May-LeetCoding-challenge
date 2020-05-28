class Solution {
public:
    bool checkInt(float x)
    {
        return floor(x) == ceil(x);
    }
    vector<int> countBits(int num) {
        
        //we know answer for num = 0, 1, 2;
        if(num == 0)    return {0};
        if(num == 1)    return {0,1};
        
        vector<int>ans(num+1);
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 1;
        
        for(int n=3; n<=num; n++)
        {
            if(checkInt(n/2.0))
                ans[n] = ans[n/2];
            else
                ans[n] = ans[n/2] + 1;
        }
        
        return ans;
    }
};