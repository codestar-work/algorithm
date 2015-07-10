using System;
using System.Collections;
using System.Collections.Generic;

class MainClass {

	static void Main() {
		int [] p = {3, 5};
		int result = Solve(p, 1, 9);
		Console.Write(result);
	}

	static int Solve(int [] p, int L, int R) {
		if (L > R) return 0;
		string key = "" + L + '-' + R;
		if (cache.ContainsKey(key)) return cache[key];
		int min = 0;
		for (int i = 0; i < p.Length; i++) {
			if (p[i] >= L && p[i] <= R) {
				int resultL = Solve(p, L, p[i]-1);
				int resultR = Solve(p, p[i]+1, R);
				int cost = resultL + resultR + (R-L);
				if (min == 0) min = cost;
				if (min > cost) min = cost;
			}
		}
		cache[key] = min;
		return min;
	}

	static Dictionary<string, int> cache = new Dictionary<string, int>();
}

