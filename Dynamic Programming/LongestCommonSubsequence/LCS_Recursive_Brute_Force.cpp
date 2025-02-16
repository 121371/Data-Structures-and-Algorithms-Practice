#include<bits/stdc++.h>
using namespace std;

class LongestCommonSubsequence {
    public:
    int t[100][100];
    LongestCommonSubsequence(){
        memset(t, -1, sizeof(t));
    }

    int findLCS(const string& s1, const string& s2, int n1, int n2){
       if(n1 == 0 || n2 == 0) return 0;

       if(s1[n1- 1] == s2[n2 -1])
       return 1 + findLCS(s1, s2, n1 -1, n2 - 1);
       
       else {
        return max(findLCS(s1, s2, n1 - 1, n2), findLCS(s1, s2, n1, n2 -1));
       }
    }
};

   int main(){
        string s1 = "aggtab";
        string s2 = "gxtxayb";
        // LongestCommonSubsequence* lcs = new LongestCommonSubsequence();
        // int n = lcs->findLCS(s1, s2, s1.length(), s2.length());

        //or
        LongestCommonSubsequence lcs;
        int n = lcs.findLCS(s1, s2, s1.length(), s2.length());
        cout<<n<<endl; // answer : 4
        // delete lcs;
        return 0;
    }