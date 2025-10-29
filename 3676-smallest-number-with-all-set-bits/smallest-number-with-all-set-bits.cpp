class Solution {
public:
    int smallestNumber(int n) {
        for (int i = n ; i; i++) {
            if (i + 1 > 0 && (i + 1 & i) == 0) {
                return i;
            }
        }
        return 0;
    }
};