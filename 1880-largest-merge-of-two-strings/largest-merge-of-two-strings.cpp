class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i=0;int j=0;
        int n=word1.size();
        int m=word2.size();
        string merge="";
        while(i<n && j<m){
            if(word1[i]<word2[j]){
                merge.push_back(word2[j]);
                j++;
            }
            else if(word1[i]>word2[j]){
                merge.push_back(word1[i]);
                i++;
            }
            else{
                string s1=word1.substr(i);
                string s2=word2.substr(j);
                if(s1>s2){
                    merge.push_back(word1[i]);
                    i++;
                }
                else{
                    merge.push_back(word2[j]);
                    j++;
                }
            }
        }
        while(i<n){
           
                merge.push_back(word1[i]);
                i++;
            
        }
        while(j<m){
            merge.push_back(word2[j]);
            j++;
        }
        return merge;  
    }
};