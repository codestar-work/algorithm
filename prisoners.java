import java.util.*;

class Prisoners {
	static int MAX = 1024;
	static Map<String, Integer>mem = new HashMap<>();

	static int solve(int a, int b, int [] r) {
		String key = a + " " + b;
		if (mem.containsKey(key)) {
			return mem.get(key);
		}
		int result = Integer.MAX_VALUE;
		for (int i = 0; i < r.length; i++) {
			if (r[i] >= a && r[i] <= b) {
				int c1 = solve(a, r[i] - 1, r);
				int c2 = solve(r[i] + 1, b, r);
				result = Math.min(result, b-a + c1 + c2);
			}
		}
		if (result == Integer.MAX_VALUE)
			result = 0;
		mem.put(key, result);
		return result;
	}

	public static void main(String [] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int t = 1; t <= T; t++) {
			int P = scanner.nextInt();
			int N = scanner.nextInt();
			int a[] = new int[MAX];
			for (int i = 0; i < N; i++) {
				a[i] = scanner.nextInt();
			}
			mem.clear();
			int result = solve(1, P, a);
			System.out.println("Case #" + t + ": " + result);
		}
	}

}
