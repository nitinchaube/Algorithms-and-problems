bool checkNumber(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(size<=0){
        return 0;
    }
	 if(x==input[0]){
        return true;
    }else{
        checkNumber(input+1,size-1,x);
    }
   // return false;
}
