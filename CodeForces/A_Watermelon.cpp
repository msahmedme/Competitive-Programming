#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    scanf("%d", &n);

    string output = ( n<=2 || n%2 ) ? "NO" : "YES";
    cout << output << endl;
    return 0;
}