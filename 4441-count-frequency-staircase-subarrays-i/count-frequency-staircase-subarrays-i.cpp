class Solution {
public:
    int countStaircase(vector<int>& nums) {

        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            unordered_map<int, int> dist;
            int count = 0;
            int bad=0;
            for (int j = i; j < n; j++) {
                if (dist.find(nums[j]) == dist.end()) {
                    dist[nums[j]] = count + 1;
                    count++;
                    bad++;
                }
                mp[nums[j]]++;
                if (mp[nums[j]] == dist[nums[j]]) {
                    bad--; 
                }
                if (mp[nums[j]] == dist[nums[j]] && bad==0) {
                    //cout<<i<<" "<<j<<" "<<bad<<endl;
                    ans++;
                    
                }

                else if(mp[nums[j]]>dist[nums[j]]){
                    break;
                }
            }
        }
    return ans;
}
}
;