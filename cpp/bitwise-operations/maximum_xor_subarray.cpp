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
const int N = 32;
const int M = 2;

typedef struct TrieNode {
    int nxt[M];

    TrieNode() {
        fill(begin(nxt), end(nxt), -1);
    }
} TrieNode;

vector<TrieNode> trie;

void insert_trie(int x) {
    vector<bool> bits;
    while (x > 0) {
        bits.pb(x % 2);
        x /= 2;
    }
    while (bits.size() < N) {
        bits.pb(0);
    }
    reverse(bits.begin(), bits.end());

    int node = 0;
    for (bool bit : bits) {
        if (trie[node].nxt[bit] == -1) {
            trie[node].nxt[bit] = trie.size();
            trie.pb(TrieNode());
        }

        node = trie[node].nxt[bit];
    }
}

int calc(int x) {
    vector<bool> bits;
    while (x > 0) {
        bits.pb((x % 2) == 0);
        x /= 2;
    }
    while (bits.size() < N) {
        bits.pb(1);
    }
    reverse(bits.begin(), bits.end());

    int ret = 0;
    int node = 0;
    int cnt = N - 1;
    for (bool bit : bits) {
        if (trie[node].nxt[bit] != -1) {
            ret += (1 << cnt);
            node = trie[node].nxt[bit];
        }
        else {
            node = trie[node].nxt[1 - bit];
        }
        cnt--;
    }

    return ret;
}

int n, pref, x;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    trie.pb(TrieNode());
    insert_trie(0);

    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pref ^= x;
        insert_trie(pref);
        res = max(res, calc(pref));
    }

    cout << res << endl;


    return 0;
}
