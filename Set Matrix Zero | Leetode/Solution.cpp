class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        long long int rowSize = matrix.size();
        long long int colSize = matrix[0].size();
        long long int r[rowSize], c[colSize];
        
        for(int i=0; i<rowSize; i++){
            r[i] = 0;
        }
        
         for(int i=0; i<colSize; i++){
            c[i] = 0;
        }
        
        for(long long int i = 0; i<rowSize; i++){
            for(long long int j = 0; j < colSize; j++){
                if(matrix[i][j] == 0){
                    r[i] = -1;
                    c[j] = -1;
                }
            }
        }
        
        for(long long int i = 0; i<rowSize; i++){
            for(long long int j = 0; j < colSize; j++){
                if(r[i] == -1 || c[j] == -1){
                   matrix[i][j]  = 0;
                }
            }
        }
        
    }
};
