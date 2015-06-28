import java.util.*;

class Graph {

	void main() {
		read();
		printMatrix();
	}

	void read() {
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
			/*
			matrix[i][i] = value;
			matrix[j][j] = value;
			*/
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
