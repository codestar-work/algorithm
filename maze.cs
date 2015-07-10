using System;
using System.Collections;
using System.Collections.Generic;

class Maze {

	static void Main() {
		Maze maze = new Maze();
		maze.Read();
		maze.BfsMain();
	}

	void BfsMain() {
		int startRow = -1, startCol = -1;
		int goalRow  = -1, goalCol  = -1;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (maze[i,j] == 'R') {
					startRow = i;
					startCol = j;
					maze[i,j] = ' ';
				}
				if (maze[i,j] == 'X') {
					goalRow = i;
					goalCol = j;
					maze[i,j] = ' ';
				}
			}
		}

		Bfs(startRow, startCol, goalRow, goalCol);
	}

	void Bfs(int row, int col, int goalRow, int goalCol) {
		PutQueue(row, col, -1);
		while (!IsQueueEmpty()) {
			QueueItem current = GetQueue();
			Console.WriteLine(current.ToString());

			if (current.row == goalRow && current.col == goalCol) {
				for (int i = 0; i < height; i++) {
					for (int j = 0; j < width; j++) {
						if (maze[i,j] == 'O') {
							maze[i,j] =  ' ';
						}
					}
				}

				while (true) {
					maze[current.row,current.col] = 'O';
					current = queue[current.parent];
					if (current.parent == -1)
						break;
				}

				Print();
				break;
			} else {
				if (maze[current.row+1,current.col  ] == ' ') {
					maze[current.row+1,current.col  ] =  'O';
					PutQueue(current.row+1, current.col  , front-1);
				}
				if (maze[current.row-1,current.col  ] == ' ') {
					maze[current.row-1,current.col  ] =  'O';
					PutQueue(current.row-1, current.col  , front-1);
				}
				if (maze[current.row  ,current.col+1] == ' ') {
					maze[current.row  ,current.col+1] =  'O';
					PutQueue(current.row  , current.col+1, front-1);
				}
				if (maze[current.row  ,current.col-1] == ' ') {
					maze[current.row  ,current.col-1] =  'O';
					PutQueue(current.row  , current.col-1, front-1);
				}
			}
		}
	}

	int front = 0;
	int rear  = 0;
	QueueItem [] queue = new QueueItem[MAX*MAX];
	void PutQueue(int row, int col, int parent) {
		queue[rear] = new QueueItem();
		queue[rear].row = row;
		queue[rear].col = col;
		queue[rear].parent = parent;
		rear++;
	}

	QueueItem GetQueue() {
		front++;
		return queue[front-1];
	}

	bool IsQueueEmpty() {
		return front == rear;
	}

	void DfsMain() {
		int startRow = -1, startCol = -1;
		int goalRow  = -1, goalCol  = -1;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (maze[i,j] == 'R') {
					startRow = i;
					startCol = j;
					maze[i,j] = ' ';
				}
				if (maze[i,j] == 'X') {
					goalRow = i;
					goalCol = j;
					maze[i,j] = ' ';
				}
			}
		}

		Dfs(startRow, startCol, goalRow, goalCol);
	}

	void Dfs(int row, int col, int goalRow, int goalCol) {
		maze[row,col] = 'O';
		if (row == goalRow && col == goalCol) {
			Print();
		} else {
			if (maze[row+1,col  ] == ' ') {
				Dfs (row+1,col  , goalRow, goalCol);
				maze[row+1,col  ] =  ' ';
			}
			if (maze[row-1,col  ] == ' ') {
				Dfs (row-1,col  , goalRow, goalCol);
				maze[row-1,col  ] =  ' ';
			}
			if (maze[row  ,col+1] == ' ') {
				Dfs (row  ,col+1, goalRow, goalCol);
				maze[row  ,col+1] =  ' ';
			}
			if (maze[row  ,col-1] == ' ') {
				Dfs (row  ,col-1, goalRow, goalCol);
				maze[row  ,col-1] =  ' ';
			}
		}
	}

	void Read() {
		width = 0;
		height = 0;
		while (true) {
			String s = Console.ReadLine();
			if (s == null) break;
			width = s.Length;
			for (int j = 0; j < width; j++) {
				maze[height, j] = s[j];
			}
			height++;
		}
	}

	void Print() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				Console.Write(maze[i,j]);
			}
			Console.WriteLine();
		}
	}

	static int MAX = 100;
	char [,] maze = new char[MAX,MAX];
	int width;
	int height;
}

class QueueItem {
	public int row;
	public int col;
	public int parent;
	override public String ToString() {
		return "row=" + row + ", col=" + col + ", parent=" + parent;
	}
}
