import java.util.*;

class Graph {

	void main() {
		read();
		printMatrix();
		floyd();
	}

	void floyd() {
		for (int t = 0; t < vertex; t++) {
			for (int u = 0; u < vertex; u++) {
				for (int v = 0; v < vertex; v++) {
					matrix[u][v] = Math.min(matrix[u][v],
						matrix[u][t] + matrix[t][v]);
				}
			}
		}

		int h = getIndex("HuaHin");
		int k = getIndex("Korat");
		System.out.println("Cost = " + matrix[h][k]);
	}

	void common(String s, String t) {
		int i = getIndex(s);
		int j = getIndex(t);

		for (int k = 0; k < vertex; k++) {
			if (i != k && j != k) {
				if (matrix[i][k] == 1 && matrix[k][j] == 1) {
					System.out.println(names[k]);
				}
			}
		}
	}

	String maxFriend() {
		int max = 0;
		String name = "";
		for (int i = 0; i < vertex; i++) {
			int count = 0;
			for (int j = 0; j < vertex; j++) {
				if (matrix[i][j] == 1) {
					count++;
				}
			}
			if (max < count) {
				max = count;
				name = names[i];
			}
		}
		return name;
	}

	int INFINITY = 99999;

	void read() {
		for (int i = 0; i < MAX_VERTEX; i++) {
			for (int j = 0; j < MAX_VERTEX; j++) {
				matrix[i][j] = INFINITY;
			}
		}
		vertex = 0;
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			String [] tokens = line.split("\t");
			int value = 0;
			try { value = Integer.parseInt(tokens[2]); } catch (Exception e) {}
			int i = getIndex(tokens[0]);
			int j = getIndex(tokens[1]);
			matrix[i][j] = value;
			matrix[j][i] = value;
			matrix[i][i] = 0;
			matrix[j][j] = 0;
		}
	}

	int MAX_VERTEX = 1024;
	int [][] matrix = new int[MAX_VERTEX][MAX_VERTEX];
	String [] names = new String[MAX_VERTEX];
	int vertex = 0;

	int getIndex(String s) {
		for (int i = 0; i < vertex; i++) {
			if (s.equals(names[i])) {
				return i;
			}
		}
		names[vertex] = s;
		vertex++;
		return vertex-1;
	}

	void printMatrix() {
		System.out.print("\t");
		for (int i = 0; i < vertex; i++) {
			System.out.print(names[i] + "\t");
		}
		System.out.println();
		for (int i = 0; i < vertex; i++) {
			System.out.print(names[i] + "\t");
			for (int j = 0; j < vertex; j++) {
				System.out.print(matrix[i][j] + "\t");
			}
			System.out.println();
		}
	}

	public static void main(String [] args) {
		Graph g = new Graph();
		g.main();
	}
}
