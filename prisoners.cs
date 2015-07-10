using System;
using System.Collections;
using System.Collections.Generic;

class MainClass {

	static void Main() {
		int T = Convert.ToInt32(Console.ReadLine());
		for (int t = 1; t <= T; t++) {
			String s = Console.ReadLine();
			String [] tokens = s.Split(' ');
			int P = Convert.ToInt32(tokens[0]);
			int N = Convert.ToInt32(tokens[1]);
			s = Console.ReadLine();
			tokens = s.Split(' ');
			int [] e = new int [N];
			for (int i = 0; i < N; i++) {
				e[i] = Convert.ToInt32(tokens[i]);
			}
			cache.Clear();
			int result = Solve(e, 1, P);
			Console.WriteLine("Case #" + t + ": " + result);
		}
	}

	static int Solve(int [] p, int L, int R) {
		string key = L + " " + R;
		if (cache.ContainsKey(key)) return cache[key];
		int min = Int32.MaxValue;
		for (int i = 0; i < p.Length; i++) {
			if (p[i] >= L && p[i] <= R) {
				int resultL = Solve(p, L, p[i]-1);
				int resultR = Solve(p, p[i]+1, R);
				int cost = resultL + resultR + (R-L);
				if (min > cost) min = cost;
			}
		}
		if (min == Int32.MaxValue)
			min = 0;
		cache[key] = min;
		return min;
	}

	static Dictionary<string, int> cache = new Dictionary<string, int>();
}

