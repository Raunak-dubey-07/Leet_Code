class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        int n=wordList.size();
        unordered_map<string,bool>visited;
        for(int i=0;i<n;i++){
            st.insert(wordList[i]);
        }
        if(st.find(endWord)==st.end()){
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int step=1;
        visited[beginWord]=true;
        while(!q.empty()){
            int x=q.size();
            while(x--){
                string front=q.front();
                q.pop();
                if(front==endWord){
                    return step;
                }
                for(int i=0;i<front.size();i++){
                    string ch=front;
                    for(int k=0;k<26;k++){
                        ch[i]='a'+k;
                        if(!visited[ch] && st.find(ch)!=st.end()){
                            q.push(ch);
                            visited[ch]=true;
                        }
                    }
                }
            }
            step++;
        }
        return 0;



        
    }
};