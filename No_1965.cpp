#include <stdio.h>


int main(int argc, char** argv)
{
	int n;
	scanf("%d", &n);
	int size[n];
	int count[n];
	int i,j;
	int max = 0;
	
	
	for(i = 0; i<n; i++)
	{
		scanf("%d", &size[i]);
	}
	
	
	
	for(i = 0; i<n; i++)
	{
		
		count[i] = 1;
		for(j = 0; j<i ;j++)
		{
			if(size[i] > size[j] && count[j] + 1 > count[i])
			{
				count[i] = count[j] + 1;
			}
			
			
			
		}	
	}
	for(i = 0; i < n; i++)
	{
		if(count[i]> max)
		{
			max = count[i];
		}
	}
	printf("%d", max);
	
	
	return 0;
}
	
	

