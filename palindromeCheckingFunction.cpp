
bool checkPalindrome(char str[]){


  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int count=0;
    for (int i=0;str[i]!='\0';i++){
        count++;
    }
    for (int i=0,j=count-1;i<count,j>=0;i++,j--){
        if(str[i]!=str[j]){
            return false;
        }

    }
    return true;


}
