class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st;
        for (int i = 0; i < wordList.size(); i++) {
            st.insert(wordList[i]);
        }
        if(st.find(endWord)==st.end()){
            return 0;
        }
        vector<char> alphabet;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            alphabet.push_back(ch);
        }
        queue<string> q;
        int step=1;
        q.push(beginWord);
        unordered_map<string, bool> visited;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string front = q.front();
                q.pop();
                if (front == endWord) {
                    return step;
                }
                for (int i = 0; i < front.size(); i++) {
                     string ori = front;
                    for(int j=0;j<26;j++){
                        ori[i]=alphabet[j];
                        if(!visited[ori]&&st.find(ori)!=st.end()){
                            q.push(ori);
                            visited[ori]=true;
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
};