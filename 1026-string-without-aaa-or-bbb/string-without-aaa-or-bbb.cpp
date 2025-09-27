class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s="";
        while (a > 0 || b > 0) {
            while (a > b &&(a>0 || b>0)) {
                if (a >= 2) {
                    s.push_back('a');
                    s.push_back('a');
                    a=a-2;
                } else if(a>0) {
                    s.push_back('a');
                    a--;
                }
               if(b>0){
                    s.push_back('b');
                    b--;
                }
            }
            while (b > a && (a>0 || b>0)) {
                if (b >= 2) {
                    s.push_back('b');
                    s.push_back('b');
                    b=b-2;
                } else if(b>0) {
                    s.push_back('b');
                    b--;
                }
                if(a>0) {
                    s.push_back('a');
                    a--;
                }
            }
            while (a == b && a!=0) {
                if (a > 0){
                    s.push_back('a');
                    a--;
                }
                if (b > 0){
                    s.push_back('b');
                    b--;
                }
            }
        }
        return s;
    }
};