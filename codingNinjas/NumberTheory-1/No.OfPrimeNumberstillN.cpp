/*Find Prime Numbers From 1 to N
Send Feedback
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3
Sample Output -
2
*/

#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int i){
    int countfactors=0;
    for(int j=1;j<=sqrt(i);j++){
        if((i%j) == 0 ){
            if((j*j)== i){
                countfactors+=1;
            }else{
                countfactors+=2;
            }

        }

    }
    if(countfactors>2){
        return false;
    }else{
        return true;
    }

}

int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++){
        if(checkPrime(i)){
            count+=1;
        }
    }
    cout<<count<<endl;
    return 0;
}
