using System;
using System.Collections;
using System.Collections.Generic;

class Graph {

	static void Main() {
		Graph graph = new Graph();
		graph.Read();
		graph.Print();
	}

	void Print() {
		for (int i = 0; i < list.Count; i++) {
			Console.Write("\t" + list[i]);
		}
		Console.WriteLine();
		for (int i = 0; i < list.Count; i++) {
			Console.Write(list[i] + "\t");
			for (int j = 0; j < list.Count; j++) {
				Console.Write(matrix[i,j] + "\t");
			}
			Console.WriteLine();
		}
	}

	void Read() {
		while (true) {
			String s = Console.ReadLine();
			if (s == null)
				break;
			String [] fields = s.Split(' ');
			int i = GetIndex(fields[0]);
			int j = GetIndex(fields[1]);
			matrix[i,j] = true;
			matrix[j,i] = true;
			matrix[i,i] = true;
			matrix[j,j] = true;
		}
	}

	int GetIndex(String name) {
		for (int i = 0; i < list.Count; i++) {
			if (list[i] == name) {
				return i;
			}
		}
		list.Add(name);
		return list.Count-1;
	}

	static int MAX = 200;
	bool [,] matrix = new bool[MAX,MAX];
	List<String> list = new List<String>();
}

