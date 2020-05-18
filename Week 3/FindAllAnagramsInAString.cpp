class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(p.length() > s.length()) return {};
        
        vector<int>ans;
        int freq_p[26] = {0};
        int freq_s[26] = {0};
        
        for(char &c: p)
            freq_p[c-'a']++;
        
        int i;
        for(i=0;i<p.length();i++)
            freq_s[s[i] - 'a']++;
        bool valid = true;
        
        for(int j=0;j<26;j++)
        {
            if(freq_s[j] != freq_p[j])
            {
                valid = false;
                break;
            }
        }
        if(valid)   ans.push_back(0);
        
        while(i < s.length())
        {
            valid = true;
            freq_s[s[i] - 'a']++;
            freq_s[s[i - p.length()] - 'a']--;
            
            for(int j=0;j<26;j++)
            {
                if(freq_p[j] != freq_s[j])
                {
                    valid = false;
                    break;
                }
            }
            
            if(valid) ans.push_back(i - p.length() + 1);
            i++;
        }
        return ans;
    }
};