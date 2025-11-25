//Program	to	find	longest	common	subsequence	and	all	common	
//subsequence	between	pair	of	string.	


#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to find LCS length using DP
int lcsLength(char* X, char* Y, int m, int n, int dp[MAX][MAX]) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }
    return dp[m][n];
}

// Recursive function to print all LCS
void printAllLCS(char* X, char* Y, int m, int n, int dp[MAX][MAX], char* lcs, int index) {
    if (m == 0 || n == 0) {
        lcs[index] = '\0';
        printf("%s\n", lcs);
        return;
    }

    if (X[m-1] == Y[n-1]) {
        lcs[index] = X[m-1];
        printAllLCS(X, Y, m-1, n-1, dp, lcs, index+1);
    } else {
        if (dp[m-1][n] > dp[m][n-1])
            printAllLCS(X, Y, m-1, n, dp, lcs, index);
        else if (dp[m][n-1] > dp[m-1][n])
            printAllLCS(X, Y, m, n-1, dp, lcs, index);
        else { // dp[m-1][n] == dp[m][n-1], both paths possible
            printAllLCS(X, Y, m-1, n, dp, lcs, index);
            printAllLCS(X, Y, m, n-1, dp, lcs, index);
        }
    }
}

// Helper function to reverse a string in place
void reverseStr(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

int main() {
    char X[MAX], Y[MAX];
    int dp[MAX][MAX];
    char lcs[MAX];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int length = lcsLength(X, Y, m, n, dp);
    printf("\nLength of Longest Common Subsequence: %d\n", length);

    printf("All Longest Common Subsequences:\n");
    printAllLCS(X, Y, m, n, dp, lcs, 0);

    return 0;
}
