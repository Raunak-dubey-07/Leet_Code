class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int a = 0, b = 0, c = 0;
        int i = 0;
        int j = i;
        while (j <= n && i<n) {
         //   cout << j << endl;
          if (a > 0 && b > 0 && c > 0) {
                ans = ans + (n - j +1);
                if (s[i] == 'a') {
                    cout<<"hii"<<endl;
                    a--;
                } else if (s[i] == 'b') {
                    b--;
                } else {
                    c--;
                }
                i++;
            }
            else{
                if(j>=n)break;
            if (s[j] == 'a') {
                a++;
            } else if (s[j] == 'b') {
                b++;
            } else {
                c++;
            }
            j++;
            }
        }
        if(a>0&&b>0&&c>0){
            ans++;
        }
        return ans;
    }
};