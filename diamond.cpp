#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

//for the upper half




 for (int i=0; i<=n/2; i++){
            for (int j=n/2; j>=i+1; j--)
              cout<<" ";
            for (int j=0; j<=i*2; j++ )
              cout<<"*" ;
        cout<<endl;
     }
   //for the lower half




   for(int i=n/2;i>=0;i--){
             for(int k=n/2;k>=i;k--)
              cout<<" ";
             for(int j=0;j<i*2-1;j++)
               cout<<"*"  ;
             cout<<endl;
     }
}
