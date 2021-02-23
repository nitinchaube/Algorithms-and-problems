# include <iostream>
# include <cmath>
using namespace std;
int main(){
    int basic,allow;
    double hra,da,pf,totalSalary;
    char grade;

    cin>>basic>>grade;

    hra=basic*0.2;
    da=basic*0.5;
    pf=basic*0.11;

    if(grade=='A'){
        allow=1700;
    }else if(grade=='B'){
        allow=1500;
    }else {
        allow=1300;
    }

    totalSalary= basic+hra+da+allow-pf;
    cout<<round(totalSalary);

}
