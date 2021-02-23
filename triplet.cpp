int tripletSum(int *arr, int n, int x)
{
	//Write your code here
    sort(arr, arr+n);
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			for(int k=j+1; k<n; k++)
			{
				if(arr[i]+arr[j]+arr[k]==x)
				{
					cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
				}
				else if(arr[i]+arr[j]+arr[k]>x)
				{
					break;
				}
			}
			if(arr[i]+arr[j]>x)
			{
				break;
			}
		}
		if(arr[i]>x)
		{
			break;
		}
	}
}
