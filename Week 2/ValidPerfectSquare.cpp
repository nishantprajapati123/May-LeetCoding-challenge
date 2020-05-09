#define ll long long int
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num == 1)    return true;
        
        ll l = 1, r = num;
        while(l <= r)
        {
            ll mid = (l + r)/2;
            if(mid*mid == num)  return true;
            
            else if(mid*mid < num)
                l = mid+1;
            else
                r = mid-1;
        }
        return false;
    }
};