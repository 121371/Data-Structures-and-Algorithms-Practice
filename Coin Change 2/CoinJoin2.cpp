class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int table[coins.size()+1][amount+1];
        
          for(int i = 0; i<coins.size()+1; i++){
            for(int j = 0; j <=amount; j++){
                if( i == 0 && j == 0){
                    table[i][j] = 1;
                } else if(i == 0 && j > 0) {
                    table[i][j] = 0;
                } else if(i > 0 && j == 0) {
                    table[i][j] = 1;
                }
            }
        }
        
        
        for(int i = 1; i<coins.size()+1; i++){
            for(int j = 1; j <=amount; j++){
                
                    if(j - coins[i-1] < 0){
                        table[i][j] = table[i - 1][j];
                    } else {
                        table[i][j] = table[i - 1][j] + table[i][j - coins[i-1]];
                    }
                
                
            }
        }
        return table[coins.size()][amount];
    }
};
