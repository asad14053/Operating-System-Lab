#include<bits/stdc++.h>
using namespace std;
#define m 1000001
typedef long long ll;
ll a[m + 7], n, e, phi, d,l=0;
bool p[m + 7];
ll bigmod(ll a,ll b,ll z)
{
    if(b==0) return 1%z;
    ll x=bigmod(a,b/2,z);
    x=(x*x)%n;
    if(b%2==1)
    x=(x*a)%n;
    return x;
}

ll prime()
{


    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for (ll i = 2; i < m; i++)
    {
        if (p[i])
        {
            a[l++] = i;
            for (ll j = i * i; j < m; j += i)
                p[j] = false;
        }
    }
}
ll key()
{
    prime();
    ll x = a[(rand() % 20)];
    ll y = a[(rand() % 20)];
    e = 2;
    n = x * y;
    phi = (x - 1) * (y - 1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (__gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    ll k = rand() % m;
    d = (1 + (k * phi)) / e;
}

int main()
{   prime();
    ll b;
    while (cin >>b)
    {
        key();
        cout<<"public key :"<<n<<" "<<e<<endl;
        cout<<"private key :"<<phi<<" "<<d<<endl;
        cout<<"message :"<<b<<endl;
        ll c = bigmod(b, e,n);
       // c = bigmod(c, n);
        cout<<"encrypted message :"<<c<<endl;
        ll mess = bigmod(c, d,n);
       // mess = bigmod(mess, n);
       cout<<"decrypted message :"<<mess<<endl;
    }

    return 0;
}
