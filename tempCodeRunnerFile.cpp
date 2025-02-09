#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    // Read the input binary string
    string binaryString;
    cin >> binaryString;

    // Read the worth array
    int n = binaryString.size();
    vector<int> worth(n);
    for (int i = 0; i < n; i++) {
        cin >> worth[i];
    }

    // To find the largest alternating string, keep track of the last used character
    // and maintain the maximum worth for valid subsequences.
    vector<vector<int>> dp(n, vector<int>(2, 0)); // dp[i][0] for ending with '0', dp[i][1] for ending with '1'

    dp[0][binaryString[0] - '0'] = worth[0];

    for (int i = 1; i < n; i++) {
        int currentChar = binaryString[i] - '0';
        int oppositeChar = 1 - currentChar;

        dp[i][currentChar] = max(dp[i - 1][currentChar], dp[i - 1][oppositeChar] + worth[i]);
        dp[i][oppositeChar] = dp[i - 1][oppositeChar];
    }

    // Find the maximum worth of the largest alternating string
    int maxWorth = max(dp[n - 1][0], dp[n - 1][1]);

    // Calculate the total worth of the original string
    int totalWorth = accumulate(worth.begin(), worth.end(), 0);

    // The worth of removed characters
    int removedWorth = totalWorth - maxWorth;

    cout << removedWorth << endl;

    return 0;
}