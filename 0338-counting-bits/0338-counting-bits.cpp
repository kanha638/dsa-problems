class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        ans[0] = 0;
        if(n==0) return ans;
        ans[1] = 1;

        int curr = 2;

        while(curr<=n){

            for(int i = curr;i<=curr*2;i++){
                if(i==n+1){
                    return ans;
                }
                ans[i] = ans[i-curr] + 1;
            }
            curr = curr*2;
        }
        return ans;
      

        return ans;

    }
};