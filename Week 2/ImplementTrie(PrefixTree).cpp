class Trie {
private:
    bool leaf;
    vector<Trie*>child;
public:
    /** Initialize your data structure here. */
    Trie() {
        
        leaf = false;
        child.resize(26, NULL);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Trie* root = this;
        for(char &c: word)
        {
            if(root->child[c-'a'] == NULL)
                root->child[c-'a'] = new Trie();
            
            root = root->child[c-'a'];
        }
        root->leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        Trie* root = this;
        for(char &c: word)
        {
            if(root->child[c-'a'] == NULL)  return false;
            root = root->child[c-'a'];
        }
        
        return root->leaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(char &c: prefix)
        {
            if(root->child[c-'a'] == NULL)  return false;
            root = root->child[c-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */