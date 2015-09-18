
#include <iostream>
#include <string>
using namespace std;


class zipperSolver
{
private:

	typedef int * NR;		//In order to create a 2D pointer array
	int **table;			//Variable to hold the table to memoize

public:

	//Memoize the table to store already computed sub-problems
	void memo(string A, string B)
	{
		
		//Create an array of size A
		table = new NR [A.length()];

		int q = A.length();				//Of length string A
		int r = B.length();				//By length of string B
	
		//And make each row length B
		for (int i = 0; i < (q+1); i++)
		{
			table[i] = new int[B.length()];
		}
	
		//Set each value to -1 to show the sub-problem hasn't been solved
		for (int i = 0; i < (q+1); i++)
		{
			for (int j = 0; j < (r+1); j++)
				table[i][j] = -1;
		}

	}


	//Un-Optimized zipper, runs in O(2^n)
	bool zipper2(string A, string B, string C)
	{
		//Base case, get out, we are done here	
		if (A.length() == 0 && B.length() == 0)
			return true;
		//Worst case, we divide and conquer to find all possible concatinations of the strings
		else if (A[0] == C[0] && B[0] == C[0])
		{
			//We use the letter from string A, and not B
			if (zipper2(A.substr(1, A.length()), B, C.substr(1, C.length())))
				return true;
			//And we use the letter from string B, and not A
			else
				return zipper2(A, B.substr(1, B.length()), C.substr(1, C.length()));
		}
		else if (A[0] == C[0])
			return zipper2(A.substr(1, A.length()), B, C.substr(1, C.length()));
		else if (B[0] == C[0])
			return zipper2(A, B.substr(1, B.length()), C.substr(1, C.length()));
		else
			return false;
	}

	//Optimized zipper, runs in O(n^2)
	bool zipper(string A, string B, string C)
	{
		//Both strings are 0, so return yes
		if (A.length() == 0 && B.length() == 0)
			return true;

		//We already calculated this sub problem, stop wasting my time
		if (table[A.length()][B.length()] != -1)
				return false;

		//Are A[0] and B[0] both equal to C[0]?
		else if (A[0] == C[0] && B[0] == C[0])
		{
			bool flag = zipper(A.substr(1, A.length()), B, C.substr(1, C.length()));
				
			if (!flag)
				table[A.length()-1][B.length()] = 0;
			else 
				return true; 

			flag = zipper(A, B.substr(1, B.length()), C.substr(1, C.length()));
			if(!flag)
				table[A.length()][B.length()-1] = 0;
			else 
				return true; 
		}
		else if (A[0] == C[0])
				return zipper(A.substr(1, A.length()), B, C.substr(1, C.length()));

		else if (B[0] == C[0])
			return zipper(A, B.substr(1, B.length()), C.substr(1, C.length()));

		else
		{
			return false;
		}
	}
};

int main()
{
	zipperSolver test;

	string A = "cat";
	string B = "tree";
	string C = "catrtee";
	test.memo(A, B);

    
    //Run using the optimized solution
	if (test.zipper(A, B, C))
		cout<<"By the joe, I do believe that this is quite possible it is"<<endl;
	else
		cout<<"No"<<endl;
    
    
    //Run using the unoptimized solution
    if (test.zipper2(A, B, C))
        cout<<"By the joe, I do believe that this is quite possible it is"<<endl;
    else
        cout<<"No"<<endl;

	return 0;
}