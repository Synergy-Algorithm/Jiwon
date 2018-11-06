// 9506.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


#include <stdio.h>


int main()
{
	int n;
	int hap[500];
	int i, j;
	int count = 0;
	int sum = 1;
	while (1) {
		scanf_s("%d", &n);
		if (n == -1) break;


		for (i = 2; i < n; i++)
		{
			if (n%i == 0)
			{
				hap[count++] = i;
				sum += i;
			}
		}

		if (sum == n)
		{
			printf("%d = 1 ", n);
			for (j = 0; j < count; j++)
			{
				printf("+ %d ", hap[j]);
			}
			printf("\n");
			count = 0;
			sum = 1;
		}
		else
		{
			printf("%d is NOT perfect.\n", n);
			count = 0;
			sum = 1;
		}
			
	}



	return 0;
}



