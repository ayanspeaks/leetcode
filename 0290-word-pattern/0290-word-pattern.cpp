class Solution {
public:
    bool wordPattern(string p, string s) 
    {
        vector<string> v; // Vector to store words from string s
        string a; 
        stringstream ss(s); // String stream to break string s into words
        
        // Split string s into words and store them in vector v
        while(ss >> a) v.push_back(a);

        // If the number of pattern characters is not equal to the number of words, return false
        if(p.size() != v.size()) return false;

        map<char, string> mp; // Map to store the pattern character to word mapping
        map<string, char> mp2; // Map to store the word to pattern character mapping
        int i = 0, n = p.size();
        
        while(i < n)
        {
            // If the pattern character is not mapped to any word yet
            if(mp[p[i]].empty()) 
            {
                // If the word is already mapped to another pattern character, return false
                if(mp2[v[i]] != NULL) return false;

                // Map the pattern character to the word and vice versa
                mp[p[i]] = v[i];
                mp2[v[i]] = p[i];
            }
            // If the pattern character is already mapped but does not match the current word, return false
            else if(mp[p[i]] != v[i]) return false;
            i++;
        }
        return true; // If all pattern characters and words match correctly, return true
    }
};
