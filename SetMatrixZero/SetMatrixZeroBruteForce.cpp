#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    int m = matrix.size();
      for(int i=0; i<m; i++){
          int n = matrix[i].size();
          for(int j=0; j<n; j++){
              if(matrix[i][j] == 0){  
                  for(int k=0;k<n;k++){
                      if(matrix[i][k] != 0)
                      matrix[i][k] = -1;
                  }
                  for(int l = 0; l< m; l++){ 
                      if(matrix[l][j] != 0)
                      matrix[l][j] = -1;
                  }
              }
          }
      }
      for(int i=0; i<m; i++){
        int n = matrix[i].size();
        for(int j=0; j<n; j++){  
          if(matrix[i][j] == -1){ 
            matrix[i][j] = 0; 
          }
        }
      }
}
