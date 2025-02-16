#include <bits/stdc++.h>
using namespace std;

class LCS_Recursive_Memoization
{
    vector<vector<int>> t;

public:
    LCS_Recursive_Memoization(int n1, int n2)
    {
        t.resize(n1 + 1, vector<int>(n2 + 1, -1));
    }

    int findLCS(const string &s1, const string &s2, int n1, int n2)
    {
        // base condition
        if (n1 == 0 || n2 == 0)
            return 0;

        if (t[n1][n2] != -1)
            return t[n1][n2];

        if (s1[n1 - 1] == s2[n2 - 1])
        {
            return t[n1][n2] = 1 + findLCS(s1, s2, n1 - 1, n2 - 1);
        }
        else
        {
            return t[n1][n2] = max(findLCS(s1, s2, n1 - 1, n2), findLCS(s1, s2, n1, n2 - 1));
        }
    }

    // This is just a test case method
    void runTestCases()
    {
        struct TestCase
        {
            string s1;
            string s2;
            int expected;
        };

        TestCase tests[] = {
            {"abcdef", "abcdef", 6},
            {"a", "a", 1},
            {"xyzabc", "abc", 3},
            {"abcdef", "abc", 3},
            {"aggtab", "gxtxayb", 4},
            {"abcdefghij", "cdgi", 4},
            {"", "", 0},
            {"abcdef", "", 0}};

        for (int i = 0; i < 8; i++)
        {
            LCS_Recursive_Memoization lcs(tests[i].s1.length(), tests[i].s2.length());
            int result = lcs.findLCS(tests[i].s1, tests[i].s2, tests[i].s1.length(), tests[i].s2.length());
            if (result == tests[i].expected)
            {
                cout << "✅ Passed\n";
            }
            else
            {
                cout << "❌ Failed (Expected: " << tests[i].expected << ", Got: " << result << ")\n";
            }
        }
    }
};

int main()
{
    LCS_Recursive_Memoization testRunner(1, 1);
    testRunner.runTestCases();
    return 0;
}