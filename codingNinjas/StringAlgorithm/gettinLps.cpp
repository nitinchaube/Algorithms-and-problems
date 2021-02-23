int* getLps(string pattern){

        int len=pattern.length();

        int *lps=new int[len];
        lps[0]=0;
        i=1;
        j=0;
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
