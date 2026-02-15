class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int ans=0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            int vowel=0;
            int consonent=0;
            for (int j = i; j < n; j++) {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
                    word[j] == 'o' || word[j] == 'u') {
                    if (mp[word[j]] == 0) {
                        vowel++;
                    }
                    mp[word[j]]++;
                }
                else{
                    consonent++;
                }
                if(consonent==k && vowel==5){
                    ans++;
                }
            }
        }
        return ans;
    }
};
