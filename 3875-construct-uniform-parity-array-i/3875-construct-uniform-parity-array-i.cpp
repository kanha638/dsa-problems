class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0;
        int evenCount = 0;

        int n = nums1.size();

        for(int i = 0; i < n ; i++){
            if(nums1[i]&1){
                oddCount++;
            }else{
                evenCount++;
            }
        }

        if((oddCount & 1) == 0){
            return true;
        }
        return true;
        
    }
};