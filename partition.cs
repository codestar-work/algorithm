using System;
using System.Collections;

class MainClass {

	static void Main() {
		int [] a = {3, 2, 1};
		int sum = 0;
		for (int i = 0; i < a.Length; i++)
			sum += a[i];
		bool [,] possible = new bool[sum+1,a.Length];

		possible[0,0] = true;
		possible[a[0],0] = true;

		for (int j = 1; j < a.Length; j++) {
			possible[0,j] = true;
			for (int i = 1; i <= sum; i++) {
				if (possible[i,j-1])
					possible[i,j] = true;
				int previous = i - a[j];
				if (previous >= 0 && possible[previous,j-1])
					possible[i,j] = true;
			}
		}
		Print(possible);
	}

	static void Print(bool [,] data) {
		for (int i = 0; i < data.GetLength(0); i++) {
			System.Console.Write(i + "\t");
			for (int j = 0; j < data.GetLength(1); j++) {
				if (data[i,j])
					System.Console.Write("Y\t");
				else
					System.Console.Write(" \t");
			}
			System.Console.WriteLine();
		}
	}
}

