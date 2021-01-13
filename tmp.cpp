
#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long int;

vector<pair<ll, int>> fPrimes;

void get_f_primes(ll v)
{
    fPrimes.clear();

    for(ll i = 2; i * i <= v; i++) {
        if(v % i != 0) continue;
        fPrimes.push_back({ i, 0 });
        while(v % i == 0) {
            fPrimes.back().second++;
            v /= i;
        }
    }
    if(v > 1) fPrimes.push_back({ v, 1 });
}

// (a / b) % mod == (a * b^(mod-2)) % mod
ll divmod(ll a, ll b, ll mod)
{
    ll res = 1;
    ll ex = mod - 2;
    while(ex > 0) {
        if(ex % 2 != 0) {
            res = (res * b) % mod;
        }
        b = (b * b) % mod;
        ex /= 2;
    }
    res = (res * a) % mod;
    return res;
}

int n;
ll s;
int num;

constexpr ll MOD = 1000000007;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        ll d;
        cin >> d;
        if(d == 0) num++;
        else if(d != 1) {
            s /= d;
        }
    }

    get_f_primes(s);
    int pNum = 0;
    for(int i = 0; i < fPrimes.size(); i++) {
        pNum += fPrimes[i].second;
    }
    fPrimes.push_back({ 1, num - pNum });

    ll res = 1;
    for(ll i = 2; i <= num; i++) {
        res = (res * i) % MOD;
    }
    for(int i = 0; i < fPrimes.size(); i++) {
        int tnum = fPrimes[i].second;
        for(ll j = 2; j <= tnum; j++) {
            res = divmod(res, j, MOD);
        }
    }

    cout << res;

    return 0;
}
