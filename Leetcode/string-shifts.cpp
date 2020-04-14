class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total = 0;
        for (int i = 0; i < shift.size(); i++) {
            total += (shift[i][0] == 0) ? shift[i][1] : -shift[i][i];
            if (total > s.length() || -total > s.length())
                total = total % s.length();
            if (total < 0)
                total = s.length() + total;
            return s.substr(total) + s.substr(0, total);
        }
    }
};
