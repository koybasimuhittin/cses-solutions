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
const int N = 5e3 + 5;
const int M = 30;

int n, q, dp[N];
string s, qs;

typedef struct TrieNode {
    int nxt[M];
    bool is_end_of_word = false;

    TrieNode() {
        fill(begin(nxt), end(nxt), -1);
    }
} TrieNode;

vector<TrieNode> trie;

void insert_trie(string s) {
    int node = 0;
    for (char c : s) {
        if (trie[node].nxt[c - 'a'] == -1) {
            trie[node].nxt[c - 'a'] = trie.size();
            trie.pb(TrieNode());
        }

        node = trie[node].nxt[c - 'a'];
    }

    trie[node].is_end_of_word = true;

}

bool find_word_in_trie(string s) {
    int node = 0;

    for (char c : s) {
        if (trie[node].nxt[c - 'a'] == -1) {
            return false;
        }

        node = trie[node].nxt[c - 'a'];
    }

    return trie[node].is_end_of_word;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.size();

    trie.pb(TrieNode());

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> qs;
        insert_trie(qs);
    }

    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        int node = 0;
        for (int j = i; j < n; j++) {
            char c = s[j] - 'a';
            node = trie[node].nxt[c];
            if (node == -1)break;
            dp[i] += trie[node].is_end_of_word * dp[j + 1];
            dp[i] %= MOD;
        }
    }
    cout << dp[0] << endl;

    return 0;
}
