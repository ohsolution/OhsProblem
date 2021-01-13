
//================code===================//

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>
#define M_PI 3.14159265358979323846
#define micro 0.000001



#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"
#else
#define AT
#define AE
#define ce(t)
#endif

using namespace std;

LL gcd(LL a, LL b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }

pair <int, int> vu[8] = { {0,1},{1,0},{0,-1} ,{-1,0},{-1,1}, {0,1} , {1,1},{1,-1} }; //RDLU EWSN

template<typename T, typename U>
void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U>
void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } };

const int max_v = 1e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e18 + 7;
const LL mod = 1e9+7;

int zn;
LL fact[max_v];

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fact[0] = fact[1] = 1;
	for (LL i = 2; i < max_v; ++i) fact[i] = (fact[i - 1] * i) %mod; 

	int n; LL s; ci(n >> s);

	//cout << n << " "<< s << endl;

	fa(i, 0, n)
	{
		LL x; ci(x);
		if (!x) ++zn;
		else s /= x;
	}

	//cout << zn << " "<< s << " zn s \n";

	vector <int> p;

	for (LL i = 2; i * i <= s; ++i)
	{
		int c = 0;
		
		while (s % i == 0)
		{
			++c;
			s /= i;
		}

		//if(c) cout << "pc : " << i << " "<< c << endl;	

		if(c) p.push_back(c);
	}

	if(s != 1) p.push_back(1);




	LL ans = fact[zn];
	LL b = 1;

	for (auto x : p)
	{
		b *= fact[x];
		b %= mod;
		zn -= x;
	}

	b *= fact[zn];
	b%= mod;

	LL mp = 1e9 + 5;
	LL base = b;

	while (mp)
	{
		if (mp & 1)
		{
			ans *= base;
			ans %= mod;
		}

		base *= base;
		base %= mod;
		mp >>= 1;
	}

	co(ans);
	return 0;
}
