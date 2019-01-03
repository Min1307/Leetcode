//30. Substring with Concatenation of All Words
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> retVal;
        if (words.size()<1 || s.size()<1) return retVal;
        // Hash all the words seperately then add them together to get a magic number
        std::hash<std::string> hash_fn;
        size_t magicNumber = 0;
        for (int i=0; i<words.size(); i++) {
            magicNumber += hash_fn(words[i]);
        }
        int wordLength = words[0].size();
        // Concatenated substring will be a given length
        int minimumSize = words.size()*wordLength;
        // We do a sliding window calculation for each 'offset' a pattern might have
        // This is faster than re-hashing the entire window because we can just drop the least recently hashed value
        for (int startOffset=0; startOffset<wordLength; startOffset++) {
            int i;
            size_t hashSum = 0;
            int minimum = 0LL-minimumSize-startOffset+s.size();
            // This means that the requested offset does not leave us with enough characters in the string!
            if (minimum < 0) return retVal;
            for (i=s.size()-startOffset-wordLength; i>=minimum; i-=wordLength) {
                hashSum+=hash_fn(s.substr(i,wordLength));
            }
            if (hashSum==magicNumber) retVal.push_back(i+wordLength);
            for (;i>=0; i-=wordLength) {
                hashSum-=hash_fn(s.substr(i+minimumSize,wordLength));
                hashSum+=hash_fn(s.substr(i,wordLength));
                if (hashSum==magicNumber) retVal.push_back(i);
            }
        }        
        return retVal;
    }
};