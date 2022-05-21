class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int len = height.size();
        int left_lar[len];
        int right_lar[len];
        int ll = height[0];
        int rl = height[len-1];
        
        for(int i = 0; i<len -1; i++){
            if(ll < height[i]){
                ll = height[i];
            }
            left_lar[i+1] = ll;
        }
        
         for(int i = len - 1; i > 0; i--){
            if(rl < height[i]){
                rl = height[i];
            }
             right_lar[i-1] = rl;
        }
        for(int i = 1; i< len - 1; i++){
            if(left_lar[i] > height[i] && right_lar[i] > height[i]) {
                 result += min(left_lar[i], right_lar[i]) - height[i];
            }
        }
        
        
        return result;
    }
};
