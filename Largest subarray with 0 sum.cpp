class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int,int>sumMap;
        int ans = 0;
        int sum = 0;
        
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum == 0){
                ans = i+1;
            }
            
            if(sumMap.find(sum) != sumMap.end()){
                ans = max(ans,i-sumMap[sum]);
            }
            else{
                sumMap[sum] = i;
            }
        }
        return ans;
    }
};
