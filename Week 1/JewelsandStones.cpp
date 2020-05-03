class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        unordered_set<char>store;
        for(auto c: J)
            store.insert(c);
        
        int count = 0;
        for(char &c: S)
        {
            if(store.find(c)!=store.end())
                count++;
        }
        return count;
    }
};