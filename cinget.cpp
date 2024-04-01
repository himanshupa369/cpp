#include<iostream>
using namespace std;

int main(){

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
    char c;
    int lowcase=0, digs=0, tabspace=0;
    c = cin.get();
    while(c!='$')
    {
        if(c>=97 && c<=122)
            lowcase++;
        else if(c>=48 && c<=57)
            digs++;
        else if(c==9 || c==32 || c==10)
            tabspace++;
        c = cin.get();
    }
    cout<<lowcase<<" "<<digs<<" "<<tabspace;
    return 0;
}
