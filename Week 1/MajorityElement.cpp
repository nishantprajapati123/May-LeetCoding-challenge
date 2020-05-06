class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        //find canditate
        int cand, count = 0;
        
        for(int i=0;i<n;i++)
        {
            if(count == 0)
            {
                cand = nums[i];
                count = 1;
            }
            else
            {
                if(cand == nums[i])
                    count++;
                else
                    count--;
            }
        }
        return cand;
    }
};