class Solution {
public:
    string frequencySort(string s) {
       
        vector<int>freq(256, 0);
        for(char c: s)
            freq[c]++;

        string res = "";
        while(1)
        {
            int max_freq = INT_MIN;
            char max_char;
            for(int i=0;i<256;i++)
            {
                if(max_freq < freq[i])
                {
                    max_freq = freq[i];
                    max_char = (char)i;
                }
            }
            if(max_freq == 0)   break;
            
            freq[max_char] = 0;
            
            while(max_freq--)
            {
                res += max_char;
            }
        }
        
        return res;
    }
};