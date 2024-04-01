#include<iostream>
using namespace std;


int main(){
int n;
    cin >>n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n-i)
        {
            cout<<" ";
            j++;
        }
        int k=1;
        int var=i;
        while(k<=i)
        {
            cout <<var;
            var++;
            k++;
        }
        int l=1;
        int num=(2*i-2);
        while(l<i)
        {
            cout<<num;
           num--;
            l++;
        }
    cout<<endl;
    i++;
    }
}

