class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        queue<string> q;
        q.push(startGene);
        int level = 0;
        unordered_set<string> visited;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if(curr==endGene){
                    return level;
                }
                for (char c : "ACGT") {
                    for (int i = 0; i < curr.size(); i++) {
                        string temp = curr;
                        temp[i] = c;
                        if (visited.find(temp) == visited.end() &&
                            st.find(temp) != st.end()) {
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};