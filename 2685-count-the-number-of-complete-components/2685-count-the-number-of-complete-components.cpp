// Code by Vivek
// Language C++
#include <bits/stdc++.h>

// pbds for ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
using namespace chrono;

// data types
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// definitions
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef unordered_map<int, int> umapi;
typedef unordered_map<ll, ll> umapll;
typedef map<int, int> mapi;
typedef map<ll, ll> mapll;

// constants
const ll pi = 3.141592653589793238462;
const ll K = 1e9 + 7;
const ll INF = 2e18;

// for loop aliases
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rfr(i, n) for (ll i = n; i >= 0; i--)
#define frs(i, s, n) for (ll i = s; i < n; i++)
#define rfrs(i, s, n) for (ll i = s; i >= n; i--)

// pbds ordered set
// #define ordSet tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

template <class T>
using ordSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using greatOrdSet = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using duplicateOrdSet = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// use less_equal to store duplicate values
// can use (var name).find_by_order or (var name).order_of_key

// more macros
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define setBitsCount __builtin_popcountll

// vector sort functions, string sort functions
#define sor(v) v.begin(), v.end() // sort(sortv(var name));

// sort acc. to pair's first element or sec elements
bool sorti(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
bool sortd(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second > b.second);
}

// #ifndef ONLINE_JUDGE
// #define debugs(x)               \
//     cerr << #x << " :" << endl; \
//     _print(x);                  \
//     cerr << endl;
// #else
// #define debugs(x)
// #endif

//  operator overload for vectors
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// bits conversion
string decToBinary(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

// useful functions
template <typename T>
void print(T &&t) { cout << t << "\n"; }
void printv(ll v[], ll n)
{
    fr(i, n) cout << v[i] << " ";
    cout << "\n";
}
template <typename T>
void printVec(vector<T> v)
{
    ll n = v.size();
    fr(i, n) cout << v[i] << " ";
    cout << "\n";
}
template <typename T>
ll sumVec(vector<T> v)
{
    ll n = v.size();
    ll s = 0;
    fr(i, n) s += v[i];
    return s;
}

// Mathematical functions
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool isPowerOfTwo(ll n)
{
    if (n == 0)
    {
        return false;
    }
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
// m, n are size
int lcs(int i, string a, int m, int j, string b, int n, vector<vector<int>> &dp)
{
    int s = a.size(), st = b.size();
    if (i >= m || j >= n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + lcs(i + 1, a, m, j + 1, b, n, dp);
    }
    else
    {
        return dp[i][j] = max(lcs(i + 1, a, m, j, b, n, dp), lcs(i, a, m, j + 1, b, n, dp));
    }
}

class DisjointSet
{
public:
    vector<int> rank, sz, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        sz.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionRank(int node1, int node2)
    {
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if (par1 == par2)
            return;
        if (rank[par2] > rank[par1])
            parent[par1] = par2;
        else if (rank[par1] > rank[par2])
            parent[par2] = par1;
        else
        {
            parent[par2] = par1;
            rank[par1] += 1;
        }
    }
    void unionSize(int node1, int node2)
    {
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if (par1 == par2)
            return;
        if (sz[par1] > sz[par2])
        {
            parent[par2] = par1;
            sz[par1] += sz[par2];
        }
        else
        {
            parent[par1] = par2;
            sz[par2] += sz[par1];
        }
    }
};

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vi adj[n];
        DisjointSet ds(n);
        for (auto i : edges)
        {
            ds.unionSize(i[0], i[1]);
            adj[i[0]].pb(i[1]);
            adj[i[1]].pb(i[0]);
        }
        map<int, vi> m;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int parA = ds.findPar(i);
            m[parA].pb(i);
        }
        for (auto i : m)
        {
            bool pos = 1;
            for (auto it : i.second)
            {
                int cur=adj[it].size();
                if (cur + 1 == ds.sz[i.first])
                {
                    continue;
                }
                else
                {
                    pos = 0;
                    break;
                }
            }
            if (pos)
                ans++;
        }
        return ans;
    }
};