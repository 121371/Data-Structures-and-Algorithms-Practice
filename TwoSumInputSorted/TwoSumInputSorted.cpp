class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, h = numbers.size() - 1;
        vector<int>result;
        while(l < h){
            if(numbers[l] + numbers[h] == target)
            {
                result.push_back(l+1);
                result.push_back(h+1);
                return result;
            } else if(numbers[l] + numbers[h] < target) {
                l++;
            } else {
                h--;
            }
        }
        return result;
    }
};
