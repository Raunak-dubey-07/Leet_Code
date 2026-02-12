class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int cnt = 0, f = 0;
                bool flag = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        if (f == 0)
                            f = freq[k];
                        else if (freq[k] != f) {
                            flag = false;
                            break;
                        }
                        cnt++;
                    }
                }
                if (flag)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};