int findUnique(int *arr, int size)
{
    //Write your code here
    int i,j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(arr[i] == arr[j] && i != j)
            break;
        }
        if(j == size )
        {
           return arr[i];
        }

	}
}
