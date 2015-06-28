import java.io.*;
import java.net.*;
import java.util.*;

class Maze {

	public static void main(String args[]) {
		Maze m = new Maze();
		m.main();
	}

	void main() {
		read();
		// dfs(startRow, startCol);
		bfs();
	}

	void bfs() {
		Item first = new Item(startRow, startCol, -1);
		queue.put(first);

		while (!queue.isEmpty()) {
			Item current = queue.get();
			if (current.row == goalRow && current.col == goalCol) {
				for (int i = 0; i < height; i++) {
					for (int j = 0; j < width; j++) {
						if (maze[i][j] == 'O') {
							maze[i][j]  = ' ';
						}
					}
				}
				while (current.parent != -1) {
					maze[current.row][current.col] = 'O';
					current = queue.get(current.parent);
				}
				print();
			} else {
				if (maze[current.row+1][current.col  ] == ' ') {
					maze[current.row+1][current.col  ]  = 'O';
					Item next = new Item(current.row+1, current.col  ,
						queue.front-1);
					queue.put(next);
				}
				if (maze[current.row-1][current.col  ] == ' ') {
					maze[current.row-1][current.col  ]  = 'O';
					Item next = new Item(current.row-1, current.col  ,
						queue.front-1);
					queue.put(next);
				}
				if (maze[current.row  ][current.col+1] == ' ') {
					maze[current.row  ][current.col+1]  = 'O';
					Item next = new Item(current.row  , current.col+1,
						queue.front-1);
					queue.put(next);
				}
				if (maze[current.row  ][current.col-1] == ' ') {
					maze[current.row  ][current.col-1]  = 'O';
					Item next = new Item(current.row  , current.col-1,
						queue.front-1);
					queue.put(next);
				}
			}
		}
	}

	Queue<Item> queue = new Queue<>();

	void dfs(int r, int c) {
		maze[r][c] = 'O';
		if (r == goalRow && c == goalCol) {
			print();
		} else {
			if (maze[r+1][c  ] == ' ') {
				dfs (r+1, c  );
				maze[r+1][c  ]  = ' ';
			}
			if (maze[r-1][c  ] == ' ') {
				dfs (r-1, c  );
				maze[r-1][c  ]  = ' ';
			}
			if (maze[r  ][c+1] == ' ') {
				dfs (r  , c+1);
				maze[r  ][c+1]  = ' ';
			}
			if (maze[r  ][c-1] == ' ') {
				dfs (r  , c-1);
				maze[r  ][c-1]  = ' ';
			}
		}
	}

	void read() {
		maze = new char[MAX][MAX];
		height = 0;
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNextLine()) {
			String s = scanner.nextLine();
			width = s.length();
			for (int j = 0; j < width; j++) {
				maze[height][j] = s.charAt(j);
			}
			height++;
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (maze[i][j] == 'R') {
					startRow = i;
					startCol = j;
					maze[i][j] = ' ';
				}
				if (maze[i][j] == 'X') {
					goalRow = i;
					goalCol = j;
					maze[i][j] = ' ';
				}
			}
		}
	}

	void print() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				System.out.print(maze[i][j]);
			}
			System.out.println();
		}
	}

	int MAX = 256;
	char [][] maze;
	int width;
	int height;
	int startRow = -1, startCol = -1, goalRow = -1, goalCol = -1;
}

class Item {
	int row;
	int col;
	int parent;
	Item(int r, int c, int p) {
		row = r;
		col = c;
		parent = p;
	}
}

class Queue<T> {
	ArrayList<T> queue = new ArrayList<>();
	int front = 0;
	int rear  = 0;
	void put(T t) {
		queue.add(t);
		rear++;
	}

	T get() {
		front++;
		return queue.get(front-1);
	}

	T get(int index) {
		return queue.get(index);
	}

	boolean isEmpty() {
		return front == rear;
	}
}
