class Solution {
public:
    void remove(string str, int k, string &ans)
    {
        //nothing to remove
        if(k == 0)
        {
            ans += str;
            return;
        }
        
        if(str.length() <= k)
            return;
        
        //smallest among n+1 character
        int minId = 0;
        for(int i=1;i<=k;i++)
        {
            if(str[i] < str[minId])
                minId = i;
        }
        ans += str[minId];
        //new string
        string s = str.substr(minId+1, str.length()-minId);
        //remaining to remove
        int new_k = k - minId;
        remove(s, new_k, ans);
    }
    string removeKdigits(string num, int k) {
        
        string ans = "";
        remove(num, k, ans);
        if(ans == "")   return "0";
        // cout<<ans<<endl;
        int i = 0;
        while(ans[i++] == '0');
        
        --i;
        
        ans = ans.substr(i, ans.length()-i);
        if(ans == "")
            return "0";
        else
            return ans;
    }
};