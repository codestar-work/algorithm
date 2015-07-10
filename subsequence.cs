using System;
using System.Collections;
using System.Collections.Generic;

class MainClass {

	static void Main() {
		int result = Solve("ATATTAA", "AATTAA");
		Console.Write(result);
	}

	static int Solve(String s, String t) {
		if (s == "" || t == "") return 0;
		string key = s + "-" + t;
		if (cache.ContainsKey(key)) return cache[key];
		if (s[0] == t[0]) {
			return 1 + Solve(s.Substring(1), t.Substring(1));
		} else {
			int result1 = Solve(s, t.Substring(1));
			int result2 = Solve(s.Substring(1), t);
			int result  = Math.Max(result1, result2);
			cache[key]  = result;
			return result;
		}
	}

	static Dictionary<string, int> cache = new Dictionary<string, int>();
}

