#include <bits/stdc++.h>
using namespace std;

class LCS__TopDownTabulation
{
    vector<vector<int>> t;

public:
    LCS__TopDownTabulation(int n1, int n2)
    {
        t.resize(n1 + 1, vector<int>(n2 + 1, 0));
    }

    int getLCS(const string &s1, const string &s2, int n1, int n2)
    {
        for (int i = 1; i < n1 + 1; i++)
        {
            for (int j = 1; j < n2 + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return t[n1][n2];
    }
    
    // Testing the program
    void testTheProgram()
    {
        struct TestCase
        {
            string s1, s2;
            int expected;
        };

        TestCase tests[] = {
            {"aabccc", "abcdc", 4},
            {"bvfreew", "vfrwe", 4},
            {"abcde", "ace", 3},
            {"abc", "def", 0},
            {"abcdef", "abcdef", 6},
            {"aggtab", "gxtxayb", 4},
            {"xyzabc", "abc", 3},
            {"abcdgh", "aedfhr", 3},
            {"abcdefghij", "cdgi", 4},
            {"", "", 0},
            {"abcdef", "", 0},
            {"abcd", "dcba", 1},
            {"aabccc", "abcdc", 4},
            {"bvfreew", "vfrwe", 4}};

        for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
        {
            LCS__TopDownTabulation lcs(tests[i].s1.length(), tests[i].s2.length());
            int value = lcs.getLCS(tests[i].s1, tests[i].s2, tests[i].s1.length(), tests[i].s2.length());
            if (value == tests[i].expected)
            {
                cout << "Passed" << endl;
            }
            else
                cout << "Failed, expected was " << tests[i].expected << " but got " << value << endl;
        }
    }
};

int main()
{
    // string s1 = "abcdr";
    // string s2 = "acrrr";
    // LCS__TopDownTabulation lcs(s1.length(), s2.length());
    // int result = lcs.getLCS(s1, s2, s1.length(), s2.length());
    // cout << result << endl;
    LCS__TopDownTabulation testRunner(1, 1);
    testRunner.testTheProgram();
    return 0;
}