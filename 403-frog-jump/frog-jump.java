class Solution {
    public boolean solve(ArrayList<Integer>arr,HashMap<Integer,Integer>mp,int i,int k,ArrayList<ArrayList<Integer>>dp){
        int n=arr.size();
        if(i>=n){
            return false;
        }
        if(i==n-1){
            return true;
        }
        if(dp.get(i).get(k)!=-1){
            return dp.get(i).get(k)==1;
        }
        boolean op1=false;
        boolean op2=false;
        boolean op3=false;
        if(k>0 && mp.containsKey(arr.get(i)+k)){
            op1=solve(arr,mp,mp.get(arr.get(i)+k),k,dp);
        }
        if(k-1>0 && mp.containsKey(arr.get(i)+k-1)){
            op2=solve(arr,mp,mp.get(arr.get(i)+k-1),k-1,dp);
        }
        if(k+1>0 && mp.containsKey(arr.get(i)+k+1)){
            op3=solve(arr,mp,mp.get(arr.get(i)+k+1),k+1,dp);
        }
        if(op1 || op2||op3){
        dp.get(i).set(k,1);
        return true;
        }
        else{
            dp.get(i).set(k,0);
            return false;
        }
    }
    public boolean canCross(int[] stones) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        int n=stones.length;
        ArrayList<Integer>arr=new ArrayList<>();

        for(int i=0;i<n;i++){
            mp.put(stones[i],i);
            arr.add(stones[i]);
        }
        ArrayList<ArrayList<Integer>>dp=new ArrayList<>();
        for(int i=0;i<n;i++){
            dp.add(new ArrayList<>(Collections.nCopies(n+1,-1)));
        }
        return solve(arr,mp,0,0,dp);
        
    }
}