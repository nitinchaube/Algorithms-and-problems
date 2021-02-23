#include <iostream>
using namespace std;

int main(){
    char c;
    int alpha=0,digits=0,chara=0;
    c=cin.get();

    while(c!='$'){
        if('z'>=c && c>='a'){
            alpha++;
        }else if('1'<=c && c<='9'){
            digits++;
        }else{
            chara++;
        }
        c=cin.get();


    }


    cout<<alpha<<" "<<digits<<" "<<chara;


}
