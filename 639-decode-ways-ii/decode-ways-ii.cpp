class Solution {
public:
    const long long MOD = 1000000007;
    vector<long long> memo;
    long long singleWays(char c) {
        if (c == '*')
            return 9;
        if (c == '0')
            return 0;
        return 1;
    }
    long long doubleWays(char a, char b) {
        if (a == '*' && b == '*') {
            return 15;
        }
        if (a == '*') {
            if (b >= '0' && b <= '6')
                return 2;
            return 1;
        }
        if (b == '*') {
            if (a == '1')
                return 9;
            if (a == '2')
                return 6;
            return 0;
        }
        int num = (a - '0') * 10 + (b - '0');
        if (num >= 10 && num <= 26)
            return 1;
        return 0;
    }
    long long solve(string& s, int i) {
        if (i == s.size()) {
            return 1;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        long long ways = singleWays(s[i]) * solve(s, i + 1);
        ways %= MOD;
        if (i + 1 < s.size()) {
            long long count = doubleWays(s[i], s[i + 1]);
             ways =(ways + count * solve(s, i + 2)) % MOD;
        }
        return memo[i] = ways;
    }
    int numDecodings(string s) {
        memo.assign(s.size(), -1);
        return solve(s, 0);
    }
};