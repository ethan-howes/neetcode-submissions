class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> hsh;
        vector<int> out;

        for (auto &elem : arr1) {
            hsh[elem] ++;
        }

        for (int i = 0; i < arr2.size(); ++i) {
            if (hsh.count(arr2[i]) != 0) {
                for (int j = 0; j < hsh[arr2[i]]; j++) {
                    out.push_back(arr2[i]);
                }
                hsh[arr2[i]] = 0;
            }
        }

        for (auto &[key, value] : hsh) {
            if (value != 0) {
                for (int i = 0; i < value; ++ i) out.push_back(key);
            }
        }
        return out;
    }
};