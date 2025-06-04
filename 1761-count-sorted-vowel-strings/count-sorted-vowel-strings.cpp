class Solution {
public:
    int solve(int i,int n,string &s){
      if(n==0) return 1; // if a string of length n is formed

   		if(i>=5) return 0; 
   		int pick= solve(i, n-1, s);
   		int notPick= solve(i+1, n, s);

   		return pick + notPick;

    }
    int countVowelStrings(int n) {
        string v="aeiou";
        return solve(0,n,v);
    }
};