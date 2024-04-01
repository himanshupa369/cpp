#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {
    int T;
    cin >> T;
    int a[T],k=0;
    
    while (T--) {
        int N, D;
        cin >> N >> D;
    if(D<9){
        a[k++]=D+1;
        }
    else{
        a[k++]=D-1;  
        }
    }
    for(int i=0;i<T;i++)
    cout<<a[i]<<" ";

    return 0;
}
