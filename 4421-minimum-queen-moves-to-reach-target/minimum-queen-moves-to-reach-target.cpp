class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int x=source[0];
        int y=source[1];
        if(x==target[0] && y==target[1]){
            return 0;
        }
        if(x==target[0] || y==target[1] || abs(x-target[0])==abs(y-target[1])){
            return 1;
        }
        return 2;
    }
};