#include <bits/stdc++.h>
#include <random>
#include <ctime>
#include <functional>


using namespace std;
#define LL long long 

const int max_v = 1e3+7;
const LL maxi = 1e12;


int sp[max_v];
vector <int> prime;

int main(void)
{
    srand(time(NULL));
    int n = rand()%100000 + 1;

    for(int i=2;i<max_v;++i)
    {
        if(!sp[i]) prime.push_back(i);
        for(auto x : prime)
        { 
            if(i*x>=max_v) break;
            sp[x*i] = x;
            if(i%x==0) break;
        }
    }

    mt19937 engine((unsigned int)time(NULL));
    uniform_int_distribution<int> dis(0,prime.size()-1);
    auto gen = bind(dis,engine);

    LL s= 1;
    int c= 0;

    vector <int> vi;

    while(c++<n&&s<=maxi)
    {
        LL x = prime[gen()];
        int rn = rand()%3+1;
        int cprn = rn;
        LL X = 1;
        while(cprn--) X*=x;

        if(s*X<=0 || s*X > maxi) break;
        s *=X;
        while(rn--) vi.push_back(x);
    }

    uniform_int_distribution<int> dis3(0,vi.size()-1);
    auto gen3 = bind(dis3,engine);
    int t = gen3()*2;

    while(t--)
    {
        vi[gen3()] = 0;
    }


    while(vi.size()<n) vi.push_back(1);

    uniform_int_distribution<int> dis2(0,n-1);
    auto gen2 = bind(dis2,engine);

    t = gen2();
    while(t--)
    {
        vi[gen2()] = 0;
    }


    int p =n;

    while(p--)
    {
        swap(vi[gen2()] , vi[gen2()]);
    }


    cout << n << " "<< s<<"\n";
    for(int i= 0;i<vi.size()-1;++i) cout << vi[i] << " ";
    cout<<vi.back();
    return 0;
}