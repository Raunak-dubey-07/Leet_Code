class Solution {
public:
    long long power(long long p, long long q, long long mod) {
    long long ans = 1;
    p %= mod;

    while (q > 0) {
        if (q % 2 == 1) {
            ans = (ans * p) % mod;
        }

        p = (p * p) % mod;
        q = q / 2;
    }

    return ans;
}
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long ans=0;
        int mod=1000000007;
        for(int i=0;i<nums.size();i++){
            long long w=nums[i]%10;
            long long d=floor(nums[i]/10);
            string s=to_string(d);
            string p=s.substr(0,w);
            string q=s.substr(w);
            cout<<stoll(q)<<endl;
            cout<<stoll(p)<<endl;
            ans =(ans+ power(stoll(p),stoll(q),mod) % mod)%mod;
        }
        return ans;
        
    }
};