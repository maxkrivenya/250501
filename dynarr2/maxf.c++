#include<stdio.h>
#include<stdlib.h>
	//Memory allocation
/*	int** memalloc(int** p, int l)
	{
		p = (int**)calloc(l * l, sizeof(int**));
		for (int i = 0; i < l; i++) p[i] = (int*)calloc(l, sizeof(int));
		return(p);
	}
	*/
	//Memory allocation


	//Input function
	void arrinput(int** p, int l)
	{
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				printf("Input %d - %d element ", i, j);
				scanf_s("%d", (p[i] + j));
			}
		}
	}
	//Input function


	//Output function
	void arrprint(int** p, int l)
	{
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				printf("%d ", p[i][j]);
			}
			printf("\n");
		}
	}
	//Output function



	//Sorting function
	void latinf(int** p, int l)
	{
		int check = 0;
		int bruh = 0;
		int i = 0;
		int j = 0;
		int num = 0;

		while ((check == 0) && (i < l))

		{
			for (i = 0; i < l; i++)
			{
				bruh = 0;
				for (num = 1; num <= l; num++)
				{
					for (j = 0; j < l; j++)
					{
						if (p[i][j] == num)
						{
							bruh++;
							j = l;
						}
					}
				}
				if (bruh != l) check++;
			}
		}
		i = 0;
		j = 0;
		while ((check == 0) && (j < l))
		{
			for (j = 0; j < l; j++)
			{
				bruh = 0;
				for (num = 1; num <= l; num++)
				{
					for (i = 0; i < l; i++)
					{
						if (p[i][j] == num)
						{
							bruh++;
							i = l;
						}
					}
				}
				if (bruh != l) check++;
			}
		}
		if (check == 0) printf("true");
		else printf("false");
	}

//sorting function