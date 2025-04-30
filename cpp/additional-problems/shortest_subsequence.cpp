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
const int N = 1e6 + 5;
const int M = 4;

int nxt[N][M];
string s;
char alphabet[] = { 'A', 'C', 'T', 'G' };

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            nxt[i][j] = N;
        }
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (s[i] == alphabet[j]) {
                nxt[i][j] = i;
            }
            else {
                nxt[i][j] = nxt[i + 1][j];
            }
        }
    }

    int curr = 0;

    while (curr <= s.size()) {
        int max_curr = 0;
        int max_chr = 0;
        for (int i = 0; i < M; i++) {
            if (nxt[curr][i] + 1 > max_curr) {
                max_curr = nxt[curr][i] + 1;
                max_chr = i;
            }
        }
        curr = max_curr;

        cout << alphabet[max_chr];
    }
    cout << endl;


    return 0;
}
