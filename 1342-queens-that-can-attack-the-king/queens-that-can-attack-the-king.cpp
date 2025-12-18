class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                            vector<int>& king) {
        int x = king[0];
        int y = king[1];
        vector<vector<int>>ans;
        vector<vector<bool>> attack(8, vector<bool>(8, false));
        for (int i = 0; i < queens.size(); i++) {
            attack[queens[i][0]][queens[i][1]] = true;
        }
        for (int i = x; i < 8; i++) {
            if (attack[i][y]) {
                cout<<1<<" "<< i<<" "<<y<<endl;
                ans.push_back({i,y});
                break;
            }
        }
        for (int i = x; i >= 0; i--) {
            if (attack[i][y]) {
                cout<<2<<" "<< i<<" "<<y<<endl;
                ans.push_back({i,y});
                break;
            }
        }
        for (int i = y; i < 8; i++) {
            if (attack[x][i]) {
                cout<<3<<" "<< x<<" "<<i<<endl;
               ans.push_back({x,i});
                break;
            }
        }
        for (int i = y; i >= 0; i--) {
            if (attack[x][i]) {
                cout<<4<<" "<< x<<" "<<i<<endl;
                ans.push_back({x,i});
                break;
            }
        }
        int i = x;
        int j = y;
        while (i < 8 && j < 8) {
            if (attack[i][j]) {
                cout<<5<<" "<< i<<" "<<j<<endl;
                ans.push_back({i,j});
                break;
            }
            i++;
            j++;
        }
        i = x;
        j = y;
        while (i >= 0 && j >= 0) {
            if (attack[i][j]) {
                cout<<6<<" "<< i<<" "<<j<<endl;
              ans.push_back({i,j});
                break;
            }
            i--;
            j--;
        }
         i = x;
        j = y;
        while (i >= 0 && j < 8) {
            if (attack[i][j]) {
                cout<<7<<" "<< i<<" "<<j<<endl;
              ans.push_back({i,j});
                break;
            }
            i--;
            j++;
        }
         i = x;
        j = y;
        while (i < 8 && j >=0) {
            if (attack[i][j]) {
                cout<<8<<" "<< i<<" "<<j<<endl;
              ans.push_back({i,j});
                break;
            }
            i++;
            j--;
        }
        return ans;
    }
};