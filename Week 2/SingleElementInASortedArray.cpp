// Time complexity :- O(log(n))
// Space complexity :- O(1)
#define ll long long int
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        ll l = 0, r = nums.size();
        ll id = 0;
        while(l <= r)
        {
            ll mid = (l+r)/2;
            int len = r-l+1;
            if(l == r)
            {
                id = l;
                break;
            }
            if(nums[mid-1] == nums[mid])
            {
                ll left = mid - l + 1;
                ll right = r - mid;
                if(left&1)
                    r = mid - 2;
                else
                    l = mid + 1;
            }
            else if(nums[mid+1] == nums[mid])
            {
                ll left = mid - l;
                ll right = r - mid + 1;
                if(left&1)
                    r = mid - 1;
                else
                    l = mid + 2;
            }
            else
            {
                id = mid;
                break;
            }
        }
        
        return nums[id];
    }
};