// Algorithm #1
int Max_Subsequence_Sum_Blue(const int A[], const int N)
{
	int This_Sum = 0, Max_Sum = 0;
	for (int i = 0; i < N; i++)
	{
		This_Sum = 0;
		for (int j = i; j < N; j++)
		{
			This_Sum += A[j];
			if (This_Sum > Max_Sum)
			{
				Max_Sum = This_Sum;
			}
		}
	}
	return Max_Sum;
}

/*
Analysis: O(n^2)
Outer for loop is O(n), Inner for loop is O(n), combined is O(n^2)

*/

// Algorithm #2
int Max_Subsequence_Sum_Green(const int A[], const int N)
{
	int This_Sum = 0, Max_Sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			This_Sum = 0;
			for (int k = i; k <= j; k++)
			{
				This_Sum += A[k];
			}
			if (This_Sum > Max_Sum)
			{
				Max_Sum = This_Sum;
			}
		}
	}
	return Max_Sum;
}
/*
Analysis: O(n^3)
Outer for loop is O(n), Inner for loop is O(n), Most Inner for loop is O(n), combined is O(n^3)
*/
// Algorithm #3
int Max_Subsequence_Sum_Red(const int A[], const int N)
{
	int This_Sum = 0, Max_Sum = 0;
	for (int Seq_End = 0; Seq_End < N; Seq_End++)
	{
		This_Sum += A[Seq_End];
		if (This_Sum > Max_Sum)
		{
			Max_Sum = This_Sum;
		}
		else if (This_Sum < 0)
		{
			This_Sum = 0;
		}
	}
	return Max_Sum;
}

/*
Analysis: O(n)
for loop is O(n).

*/

/*
System Information:
Elementary OS
Pentium 4
1024mb DDR2

Analyzing Blue Algorithm
	-Size-  -Big O Estimate-   -Runtime-
	  8192                 2       0.024
	 16384                 2       0.106
	 32768                 2       0.467
	 65536                 2        2.01
	131072                 2       6.605

Analyzing Green Algorithm
	-Size-  -Big O Estimate-   -Runtime-
	  1024                 3       0.082
	  2048                 3       0.638
	  4096                 3       4.493

Analyzing Red Algorithm
	-Size-  -Big O Estimate-   -Runtime-
   4194304                 1       0.009
   8388608                 1       0.018
  16777216                 1        0.03
  33554432                 1        0.07
  67108864                 1       0.137
 134217728                 1       0.271
 */