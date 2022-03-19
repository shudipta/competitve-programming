class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        int offset = 2;
        for (int i = 1; i < n; i++, offset *= 2) {
            for (int j = res.size() - 1; j > -1; j--) {
                res.push_back(offset | res[j]);
            }
        }

        return res;
    }
};
