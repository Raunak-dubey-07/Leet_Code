class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //sort(triplets.begin(), triplets.end());
        int n = triplets.size();
        bool a = false;
        bool b = false;
        bool c = false;
        for (int i = 0; i < n; i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] ||
                triplets[i][2] > target[2]) {
                   // cout<<triplets[i][2]<<endl;
                continue;

            } else {
                cout<<triplets[i][2]<<" "<<target[2]<<endl;
                if (triplets[i][0] == target[0]) {
                    //cout<<triplets[i][0]<<endl;
                    a = true;
                }if (triplets[i][1] == target[1]) {
                    //cout<<triplets[i][1]<<endl;
                    b = true;
                }if (triplets[i][2] == target[2]) {
                    //cout<<triplets[i][2]<<endl;
                    c = true;
                }
                cout<<a<<b<<c<<endl;
                if (a && b && c) {
                return true;
            }
            }
            
           
        }
         return false;
    }
};