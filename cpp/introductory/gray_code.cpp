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
const int N = 16;

int n;
vector<bool> visited((1 << N), false);

string binaryString(int num) {
    string ans = "";

    while (num > 0) {
        ans += (num & 1) ? '1' : '0';
        num >>= 1;
    }

    while (ans.size() < n) {
        ans += '0';
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int32_t main() {

    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int curr = 0;

    for (int i = 0; i < (1 << n); i++) {
        cout << binaryString(curr) << endl;
        visited[curr] = true;
        for (int j = 0; j < n; j++) {
            if (!visited[curr ^ (1 << j)]) {
                curr = curr ^ (1 << j);
                break;
            }
        }
    }


    return 0;
}
