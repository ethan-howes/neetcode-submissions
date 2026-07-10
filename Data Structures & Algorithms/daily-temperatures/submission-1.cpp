class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(), 0);
        
        // first: val, second, index
        stack<pair<int,int>> stk;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[i] > stk.top().first) {
                int index = stk.top().second;
                stk.pop();
                out[index] = i - index;
            }
            stk.push({temperatures[i], i});
        }
        return out;
    }
};
