#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long powerMod(long long base, long long exp) {
    
    long long result = 1;
    while(exp > 0){
        if(exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int n, m;
        cin >> n >> m;
        
        long long ans = powerMod(2, n) - 1;
        ans = powerMod(ans, m);
        
        cout << ans << " ";
    }
    
    cout << endl;
    
    return 0;
}
