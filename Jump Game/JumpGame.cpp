class Solution {
public:
    bool canJump(vector<int>& nums) {
        int table[2][nums.size()];
        for(int i=0; i<nums.size(); i++){
            table[0][i] = nums[i];
        }
        
        table[1][nums.size() -1] = 0;
        
        for(int i=nums.size() -2; i>= 0; i--){
            int temp = nums[i];
            int min = table[1][i+1];
            int j = i;
            
            if(temp == 0){
               table[1][i] = -1;
                continue;
            }
            while(temp-- && j<nums.size()-1){
                if(table[1][j+1] < min && table[1][j+1]  != -1){
                    min = table[1][j+1];
                }
                if(table[1][j+1] >= 0 && min == -1) {
                    min = 0;
                }
                if(table[1][j+1] == 0 && j+1 == nums.size() -1){
                    min = 0;
                    break;
                }
                j++;
                
            }
            
            if(min == -1){
                table[1][i] = -1;
            } else {
                table[1][i] = min + 1;
            }
        }
        
       
        
        if(table[1][0] >= 0)
            return true;
        else return false;
    }
};
