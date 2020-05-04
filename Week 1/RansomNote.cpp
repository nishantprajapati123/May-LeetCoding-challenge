class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int m = ransomNote.length();
        int n = magazine.length();
        
        int freq[26];
        for(int i=0;i<26;i++)
            freq[i] = 0;
        
        
        for(char c: magazine)
            freq[c-'a']++;
        
        for(char c: ransomNote)
            freq[c-'a']--;
        
        for(int i=0;i<26;i++)
        {
            if(freq[i] < 0)
                return false;
        }
        return true;
    }
};