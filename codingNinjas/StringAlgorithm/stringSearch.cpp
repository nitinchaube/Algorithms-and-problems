// S and T - input strings
// You need to check if string T is present in S or not
#include<bits/stdc++.h>
using namespace std;
int* getLps(string pattern){

        int len=pattern.length();

        int *lps=new int[len];
        lps[0]=0;
        int i=1;
        int j=0;
        while(i<len){
            if(pattern[i]==pattern[j]){
                lps[i]=j+1;
                i++;
                j++;
            }else{
                if(j!=0){

                    j=lps[j-1];

                }else{

                    lps[i]=0;
                    i++;

                }
            }
        }

}

int kmp(string text , string pattern){

    int textLen=text.length();
    int patternLen=pattern.length();
    int i=0,j=0;
    int *lps=getLps(pattern);
    while(i<textLen && j<patternLen){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j=lps[i-1];
            }else{
                i++;
            }

        }
    }
    return j==patternLen?(i-j):-1;


}

int findString(char S[], char T[]) {
    // Write your code here
    string pattern="";
    string text="";
    for(int i=0;S[i]!='\0';i++){
        text+=S[i];
    }

    for(int i=0;T[i]!='\0';i++){
        pattern+=T[i];
    }

    int i=kmp(text,pattern);

    return i;


}



int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}


