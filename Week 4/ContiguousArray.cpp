class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int>mp;
        
        int ans = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i] == 0?-1:1;
            if(sum == 0)
            {
                ans = max(ans, i+1);
                continue;
            }
            if(mp.find(sum) != mp.end())
                ans = max(ans, i - mp[sum]);
            else
                mp[sum] = i;
            
        }
        
        return ans;
    }
};