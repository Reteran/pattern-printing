#include <stdio.h>
#include <stdlib.h>

void printer(int r)
{
    int rows = r;
	int *prev = (int *)malloc(1 * sizeof(int));
	
	for(int i = 1; i <= rows; i++)
	{
		int now[i];
		
		for(int j = 1; j <= rows - i; j++)
		{
			printf(" ");
		}
		
		for(int k = 1; k <= i; k++)
		{
			if(k == 1 || k == i)
			{
				now[k-1] = 1;
				printf("█ ");
				
			}
			else
			{
				now[k-1] = prev[k-2] + prev[k-1];
				
				if(now[k-1]%2==0)
					printf("  ");
				else
					printf("█ ");
			}
		}
		
		printf("\n");
		
		
		int *temp = (int *)realloc(prev, i * sizeof(int));
		if(temp == NULL)
			printf("Memory Reallocation Failed");
		else
			prev = temp;
		
		for(int l = 0; l < i; l++)
		{
			prev[l] = now[l];
		}
		
		
	}
}

int main() 
{
	int n;
	scanf("%d", &n);
    printer(n);
    return 0;
}

