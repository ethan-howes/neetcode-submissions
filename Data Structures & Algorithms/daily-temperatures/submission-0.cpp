class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(), 0);
        stack<pair<int,int>> stk;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[i] > stk.top().first) {
                int index = stk.top().second;
                int val = stk.top().first;
                stk.pop();

                out[index] = i - index;
            }
            stk.push({temperatures[i], i});
        }


        return out;
    }
};
