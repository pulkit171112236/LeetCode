// MANACHER'S ALGORITHM
class Solution {
   public:
    string longestPalindrome(string s) {
        // max-length of palindromic string with center
        vector<int> memo;
        int len, L, R, C, mirr, p, q, max_center, max_len, org_pos;
        string ss;

        ss = "#";
        for (int i = 0; i < s.length(); i++) {
            ss.push_back(s[i]);
            ss.push_back('#');
        }
        len = ss.length();
        memo.resize(len);
        L = R = C = 0;
        for (int i = 0; i < len; i++) {
            mirr = 2 * C - i;
            // if i lies in current pal
            if (i <= R) {
                memo[i] = min(memo[mirr], R - i);
            }
            p = i - memo[i];
            q = i + memo[i];
            while (p - 1 >= 0 && q + 1 < len && ss[p - 1] == ss[q + 1]) {
                p--;
                q++;
                memo[i]++;
            }
            if (q > R) {
                L = p;
                R = q;
                C = i;
            }
        }
        max_center = -1;
        max_len = -1;
        for (int i = 0; i < memo.size(); i++) {
            if (memo[i] > max_len) {
                max_len = memo[i];
                max_center = i;
            }
        }
        org_pos = (max_center - max_len) / 2;
        return s.substr(org_pos, max_len);
    }
};
