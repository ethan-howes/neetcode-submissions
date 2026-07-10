class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> posspeed;
        // pos, speed

        for (int i = 0; i < position.size(); ++i) {
            posspeed.push_back({position[i], speed[i]});
        }

        sort(posspeed.rbegin(), posspeed.rend());



        vector<double> stk;
        for (auto elem : posspeed) {
            stk.push_back((double)(target - elem.first) / elem.second);

            if (stk.size() >= 2 && stk.back() <= stk[stk.size() - 2]) {
                stk.pop_back();
            }
        }
        return stk.size();
    }
};
