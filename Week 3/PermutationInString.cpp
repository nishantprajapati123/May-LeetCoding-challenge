class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        
        
        int freq_s1[26] = {0};
        int freq_s2[26] = {0};
        
        for(char &c: s1)
            freq_s1[c-'a']++;
        
        int i;
        for(i=0;i<s1.length();i++)
            freq_s2[s2[i] - 'a']++;
        bool valid = true;
        
        for(int j=0;j<26;j++)
        {
            if(freq_s2[j] != freq_s1[j])
            {
                valid = false;
                break;
            }
        }
        if(valid)   return true;
        
        while(i < s2.length())
        {
            valid = true;
            freq_s2[s2[i] - 'a']++;
            freq_s2[s2[i - s1.length()] - 'a']--;
            
            for(int j=0;j<26;j++)
            {
                if(freq_s1[j] != freq_s2[j])
                {
                    valid = false;
                    break;
                }
            }
            
            if(valid) return true;
            i++;
        }
        return false;
    }
};