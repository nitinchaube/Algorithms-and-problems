#include<bits/stdc++.h>
using namespace std;

class Triplet{
public:
    int x;
    int y;
    int gcd;
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

int main(){
    int a,b;
    cin>>a>>b;
    Triplet ans=extendedEuclid(a,b);
    cout<<ans.gcd<<endl;
    cout<<ans.x<<endl;
    cout<<ans.y<<endl;
}
/*eg: a=10,b=16
    ax+by=gcd(a,b);
    hence x=-3;y=2;gcd=2
*/
