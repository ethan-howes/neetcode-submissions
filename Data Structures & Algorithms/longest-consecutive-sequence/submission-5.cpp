class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> fmap;
        for (int i = 0; i <nums.size(); ++i) {
            fmap[nums[i]]++;
        }

        int longest = 0;

        for (int i = 0; i <nums.size(); ++i) {
            int currlen =0;
            int curval = nums[i];
            while (fmap.count(curval + 1) != 0) {
                curval ++;
                currlen ++;
            }

            if (currlen > longest) longest = currlen;
        }

        return longest +1;
    }
};