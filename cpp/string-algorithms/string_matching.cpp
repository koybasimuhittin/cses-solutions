#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int lps[N];
string text, pattern;

void calc_lps() {
    int len = 0;
    for (int i = 1; i < pattern.size(); i++) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
        } else {
            while (len > 0) {
                len = lps[len - 1];
                if (pattern[i] == pattern[len]) {
                    len++;
                    lps[i] = len;
                    break;
                }
            }
        }
    }
}

int count_patterns() {
    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < text.size(); i++) {
        if (pattern[idx] == text[i]) {
            idx++;

            if (idx == pattern.size()) {
                cnt++;
                idx = lps[idx - 1];
            }
        } else {
            if (idx != 0) {
                idx = lps[idx - 1];
                i--;
            }
        }
    }

    return cnt;
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> text >> pattern;

    calc_lps();
    cout << count_patterns() << endl;

    return 0;
}
