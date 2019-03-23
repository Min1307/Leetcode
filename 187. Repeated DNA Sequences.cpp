//187. Repeated DNA Sequences
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int32_t fingerprint = 0;
        std::unordered_map<char, int8_t> nuc_vals = {
            {'A', 0}, 
            {'C', 1}, 
            {'G', 2}, 
            {'T', 3}};
    for (int i = 0; i < 9; ++i) {
        fingerprint = fingerprint * 4 + nuc_vals[s[i]];
    }
    std::vector<std::string> ret;
    std::unordered_map<int32_t, int32_t> freq;
    for (int i = 9; i < s.size(); ++i) {
        fingerprint = (fingerprint * 4 + nuc_vals[s[i]]) & ((1 << 20) - 1);
        if (2 == ++freq[fingerprint]) {
            ret.emplace_back(s.begin() + i - 9, s.begin() + i + 1);
        }
    }
    return ret;
    }
};