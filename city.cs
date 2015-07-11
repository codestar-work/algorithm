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
				if (matrix[i,j] == INFINITY)
					Console.Write(" \t");
				else
					Console.Write(matrix[i,j] + "\t");
			}
			Console.WriteLine();
		}
	}

	void Read() {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				matrix[i,j] = INFINITY;
			}
		}
		while (true) {
			String s = Console.ReadLine();
			if (s == null)
				break;
			String [] fields = s.Split(' ');
			int i = GetIndex(fields[0]);
			int j = GetIndex(fields[1]);
			int c = Convert.ToInt32(fields[2]);
			matrix[i,j] = c;
			matrix[j,i] = c;
			matrix[i,i] = 0;
			matrix[j,j] = 0;
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
	int [,] matrix = new int[MAX,MAX];
	List<String> list = new List<String>();
	static int INFINITY = 100000;
}

