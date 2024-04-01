#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int n,i,c,s=0,f=1;
    cin>>n;
    cin>>c;
    switch(c)
 {
     case 1:
           for(i=1;i<=n;i++)
           s=s+i;
           cout<<s<<endl;
           break;
     case 2:
           for(i=1;i<=n;i++)
           f=f*i;
           cout<<f<<endl;
           break;
     default:
           cout<<-1<<endl;
           break;

 }
}
