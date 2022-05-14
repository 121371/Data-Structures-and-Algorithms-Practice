class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
             vector<vector<int>>result;
        if(nums.size() <3)
            return {};
    
        sort(nums.begin(), nums.end());
        for(int i=0;i <nums.size() -2; i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                 int a = i;
            int low = i + 1;
            int high = nums.size() - 1;
            
            while( low < high){
                vector<int>temp;
               
                if((nums[low] + nums[high]) == -nums[a]){
                    temp.push_back(nums[a]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    result.push_back(temp);
                     while(low<high && nums[low] == nums[low+1]){
                    low++;
                }
                  while(low<high && nums[high] == nums[high-1]){
                    high--;
                }
                    low++;
                    high--;
                } else if((nums[low] + nums[high]) < -nums[a]){
                    low++;
                } else if((nums[low] + nums[high]) > -nums[a]){
                    high--;
                }
            }
            }
           
        
        }
        return result;
    }
};
