import java.util.*;

class Demo {
	static int MAX = 1024;
	static boolean [][] possible = new boolean[MAX][MAX];
	static int [] a = {3, 2, 1, 6};


	public static void main(String [] args) {
		int sum = 0;
		for (int i = 0; i < a.length; i++) {
			sum += i;
		}
		if (sum % 2 != 0) {
			System.out.println("Impossible");
		} else {
			possible[a[0]][0] = true;
			possible[0][0] = true;

			for (int j = 1; j < a.length; j++) {
				for (int i = 0; i <= sum; i++) {
					if (possible[i][j-1]) {
						possible[i][j] = true;
					}
					int previous = i - a[j];
					if (previous >= 0) {
						if (possible[previous][j-1]) {
							possible[i][j] = true;
						}
					}
				}
			}

			System.out.print("\t");
			for (int i = 0; i < a.length; i++) {
				System.out.print(a[i] + "\t");
			}
			System.out.println();
			for (int i = 0; i <= sum; i++) {
				System.out.print(i + "\t");
				for (int j = 0; j < a.length; j++) {
					System.out.print(possible[i][j] + "\t");
				}
				System.out.println();
			}
		}

	}
}
