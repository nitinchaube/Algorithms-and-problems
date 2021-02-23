#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n;
    cin>>n;

   if(n>0) {
      while(n%2 == 0) {
         n/=2;
      }
      if(n == 1) {
         cout<<"YES";
      }
   }
   if(n == 0 || n != 1) {
      cout<<"NO";
   }
   return 0;
}
