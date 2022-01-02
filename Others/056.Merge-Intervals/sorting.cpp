class Solution {
    bool isOverlap(vector<int> a, vector<int> b) {
        if (a[1] < b[0] || b[1] < a[0]) return false;
        else return true;
    }
    vector<int> merge(vector<int> a, vector<int> b) {
        return vector<int>({min(a[0], b[0]), max(a[1], b[1])});
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto it : intervals) {
            while (!res.empty() && isOverlap(res.back(), it)) {
                it = merge(res.back(), it);
                res.pop_back();
            }
            res.push_back(it);
        }
        return res;
    }
};
