#include<bits/stdc++.h>
using namespace std;

class Triplet{
public:
    int gcd;
    int x;
    int y;
};

Triplet extendedEuclid(int a,int b){
    //Base case
    if(b==0){
        Triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    //Extended Euclid algorithm
    //gcd(a,b)=gcd(b,a%b)
    //(ax+by)=gcd(a,b)
    //ie. bx1+(a%b)y1=gcd(b,a%b)
    //therefore we get x=y1 and y=x1-[a/b]y1
    Triplet smallAns=extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}

int MMInverse(int a,int m){
    Triplet ans=extendedEuclid(a,m);
    return ans.x;
}

int main(){
    int a,m;
    cin>>a>>m;
    int b=0;
    b=MMInverse(a,m);
    cout<<"Multiplicative MOdulo Inverse "<<b<<endl;
}

/*input  5,17
 output: 7
  b has to be 5 for
  (a.b)mod m=1
  (5*17)%7
  =1
*/

