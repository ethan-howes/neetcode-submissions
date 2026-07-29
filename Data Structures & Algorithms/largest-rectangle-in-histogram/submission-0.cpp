class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        int currheight = 0;
        int currmax = 0;
        int width = 0;
        for (int i = 0; i < heights.size(); ++i) {
            currheight = heights[i];
            currmax = 0;
            width = 0;
            for (int j = i+1; j < heights.size(); ++j) {
                if (heights[j] < currheight) {
                    currheight = heights[j];
                } else if (heights[j] == 0) {
                    currmax = currheight * (j - i);
                    break;
                }
                currmax = currheight * (j - i +1);
            }
            if (currmax > max) {
                max = currmax;
            }
            if (currheight > max) max = currheight;

        }
        return max;
    }
};
