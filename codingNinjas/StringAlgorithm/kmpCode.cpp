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

bool kmp(string text , string pattern){

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
    if(j==patternLen){
        return true;
    }else{
        return false;

    }



}


int main(){

    string text,pattern;
    cin>>text>>pattern;

    cout<<kmp(text,pattern);


}
