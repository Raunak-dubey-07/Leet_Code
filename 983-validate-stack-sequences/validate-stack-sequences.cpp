class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        while (i < (int)pushed.size()) {

            if (i < 0) {
                i++;
            } else if (pushed[i] == popped[j]) {
                cout << pushed[i] << endl;
                pushed.erase(pushed.begin() + i);
                j++;
                i--;
            } else {
                i++;
            }
        }
        if (pushed.size() == 0) {
            return true;
        }
        return false;
    }
};