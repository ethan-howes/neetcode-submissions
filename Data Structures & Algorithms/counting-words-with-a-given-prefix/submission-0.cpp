class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len = pref.size();
        int out = 0;

        for (auto elem : words) {
            if (elem.substr(0, len) == pref) out ++;
        }
        return out;
    }
};