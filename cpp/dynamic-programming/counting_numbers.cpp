#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 1e2 + 5;
const int M = 1e6 + 5;

string num1, num2;

int count_numbers_less_than(string num) {
    int n = num.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(10, vector<int>(2, 0)));

    dp[0][0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (j == k) continue;
                dp[i][j][0] += dp[i - 1][k][0];
            }
        }

        for (int j = 0; j < num[i - 1] - '0'; j++) {
            for (int k = 0; k < 10; k++) {
                if (j == k) continue;
                dp[i][j][0] += dp[i - 1][k][1];
            }
        }

        for (int k = 0; k < 10; k++) {
            if (k != num[i - 1] - '0') {
                dp[i][num[i - 1] - '0'][1] += dp[i - 1][k][1];
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        ans += dp[n][i][0] + dp[n][i][1];
    }

    return ans;
}

int count_numbers(string num) {
    string curr = "";
    int ans = 0;

    for (int i = 0; i < num.size() - 1; i++) {
        curr += "9";
        ans += count_numbers_less_than(curr);
    }

    ans += count_numbers_less_than(num);

    return ans;
}

bool is_valid(string num) {
    for (int i = 1; i < num.size(); i++) {
        if (num[i] == num[i - 1]) return false;
    }

    return true;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> num1 >> num2;

    cout << count_numbers(num2) - count_numbers(num1) + is_valid(num1) << endl;


    return 0;
}
