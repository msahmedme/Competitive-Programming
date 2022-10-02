#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


typedef long long ll;

void solve(){
    ll n;
    scanf("%lld", &n);
    // printf("Got n: %lld\n", n);
    ll skill[n], damageFire[n], damageFrost[n]; // damageFire = 1, damageFrost = 0
    ll val;
    ll total_one = 0, total_zero = 0;

    for(ll i= 0; i<n; i++){
        scanf("%lld", &skill[i]);
        // printf("got skill: %lld\n", skill[i]);
        if(skill[i]==0)
            total_zero++;
        else
            total_one++;
    }

    // printf("Total 0: %lld\nTotal 1: %lld\n", total_zero, total_one);

    ll frost = 0;
    ll fire = 0;

    for(ll i= 0; i<n; i++){
        scanf("%lld", &val);
        // printf("got damage: %d\n", val);
        if(skill[i] == 0)
            damageFrost[frost++] = val ;
        else
            damageFire[fire++] = val;
    }
    
    // //prints the array for frost
    // cout << "UnSorted Frost damage: " ;
    // for (ll i = 0; i < total_zero; i++){
    //     cout << damageFrost[i] << " ";
    // }
    // r = total_one;
    // cout << endl << "UnSorted Fire damage: ";
    // //prints the array for fire
    // for (ll i = 0; i < total_one; i++){
    //     cout << damageFire[i] << " ";
    // }
    // cout << endl;

    // sort damage array
    sort(damageFire, damageFire + total_one);
    sort(damageFrost, damageFrost + total_zero);

    // //prints the array for frost
    // cout << "Sorted Frost damage: " ;
    // for (ll i = 0; i < total_zero; ++i){
    //     cout << damageFrost[i] << " ";
    // }

    // cout << endl << "Sorted Fire damage: ";
    // //prints the array for fire
    // for (ll i = 0; i < total_one; ++i){
    //     cout << damageFire[i] << " ";
    // }
    // cout << endl;
        

    ll totalDamage = 0;
    // printf("Total Damage: %lld\n", totalDamage);
    if(total_one > total_zero){
        while(total_zero){
            totalDamage += (2*damageFire[--total_one] ) + (2*damageFrost[--total_zero]);
            // total_one--;
            // total_zero--;
        }
        // printf("Remaining total 1: %lld, Remaining total 0: %lld\n", total_one, total_zero);
        while(total_one){
            totalDamage += damageFire[--total_one];
            // total_one--;
        }
        // printf("Total Damage: %lld\n", totalDamage);
    }
    else if(total_zero > total_one){
        while(total_one){
            totalDamage += (2*damageFrost[--total_zero] ) + (2*damageFire[--total_one]);
            // total_one--;
            // total_zero--;
        }
        // printf("Remaining total 1: %lld, Remaining total 0: %lld\n", total_one, total_zero);
        while(total_zero){
            totalDamage += damageFrost[--total_zero];
            // total_zero--;
        }
    }
    else{ // total_zero == total_one
        if(damageFire[0]<damageFrost[0]){
            while(total_zero-1){
                totalDamage += (2*damageFire[--total_one] ) + (2*damageFrost[--total_zero]);
                // total_one--;
                // total_zero--;
            }
            // printf("Remaining total 1: %lld, Remaining total 0: %lld\n", total_one, total_zero);
            // while(total_one){
            //     totalDamage += damageFire[total_one-1];
            //     total_one--;
            // }

            totalDamage += (2 * damageFrost[0]) + damageFire[0];
            
        }else{
            while(total_zero-1){
                totalDamage += (2*damageFire[--total_one] ) + (2*damageFrost[--total_zero]);
                // total_one--;
                // total_zero--;
            }
            // printf("Remaining total 1: %lld, Remaining total 0: %lld\n", total_one, total_zero);
            // while(total_one){
            //     totalDamage += damageFire[total_one-1];
            //     total_one--;
            // }

            totalDamage +=(2* damageFire[0]) + damageFrost[0];
        }

    }
    // printf("Remaining total 1: %d, Remaining total 0: %d\n", total_one, total_zero);
    // printf("Total Damage: ");
    printf("%lld\n", totalDamage);


}

int main(){

// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//fast_cin();
    ll t;
    cin >> t;
    for(int it=0;it<t;++it) {
        // cout << "Case #" << it+1 << ": "; 
        solve();
    }

return 0;
}