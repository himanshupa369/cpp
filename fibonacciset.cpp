#include<iostream>
using namespace std;

bool checkMember(int n)
int main(){

  /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Return output and don't print it.
   * Taking input and printing output is handled automatically.
  */
    int arr[n];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
        if(arr[i]==n)
        {
            return true;
        }
    }
    return false;

}
