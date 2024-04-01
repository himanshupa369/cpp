#include<iostream>
using namespace std;

int main() {
	// Write your code here
	float basic;
	char grade;
    int x;
    cin >> basic>>grade;
    float allow;
    float totalSalary,hra,pf,da;
     hra=(basic*20)/100;
     da=(basic*50)/100;
     pf=(basic*11)/100;
    if(grade=='A')
    {
        allow=1700;
    }
    else if(grade=='B')
    {
        allow=1500;
    }
    else
    {
        allow=1300;
    }
   totalSalary=basic+hra+da+allow-pf;
    x = (int) totalSalary;
   if(totalSalary - x > 0.5)
   {
    totalSalary = x+1;
     }
     else
     {
    totalSalary = x;
    }
    cout <<totalSalary<<endl;
}
