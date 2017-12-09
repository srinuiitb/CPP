#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;
int min(int a, int b) {
        return a<b?a:b;
}

int mm(int a[], int n) {
        int dp[n-1][n-1];
        memset(dp, 0, sizeof(dp));
        for(int k=0;k<n-1;k++) {
                int j = k+1;
                for(int i=0;i<n,j<n;i++,j++) {
                        dp[i][j] = min(dp[i][j-1] + a[i]*a[j+1]*a[j], dp[i+1][j] + a[i]*a[i+1]*a[j+1]);
                }
        }
        return dp[0][n-2];
}

int main() {
        int a[] = {1,2,3,4,5};
        int n = sizeof(a)/sizeof(a[0]);
        cout << mm(a,n) << endl;
        return 0;
}
