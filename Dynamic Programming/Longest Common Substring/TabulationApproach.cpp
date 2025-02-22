#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>>t;
    int maxLength;
  public:
    int LCS(string& s1, string& s2, int m, int n, vector<vector<int>>&t){
        if(m == 0 || n == 0){
            return 0;
        }
        
       for(int i=1; i<m+1; i++){
           for(int j=1; j<n+1; j++){
               if(s1[i-1] == s2[j-1]){
                   t[i][j] = 1 + t[i-1][j-1];
                   maxLength = max(maxLength, t[i][j]);
               } else {
                   t[i][j] = 0;
               }
           }
       }
       return maxLength;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        maxLength = 0;
        int m = s1.length();
        int n = s2.length();
        t.resize(m+1, vector<int>(n+1, 0));
        maxLength = LCS(s1, s2, s1.length(), s2.length(), t);
        return maxLength;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
