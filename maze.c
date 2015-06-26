#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

char maze[MAX][MAX];

void printMaze() {
	for (int i = 0; maze[i][0] != 0; i++) {
		for (int j = 0; j < (int)strlen(maze[i]); j++) {
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

void readMaze() {
	char buffer[BUFSIZ];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			maze[i][j] = 0;
	int i = 0;
	while (gets(buffer) != NULL) {
		for (int j = 0; j < (int)strlen(buffer); j++) {
			maze[i][j] = buffer[j];
		}
		i++;
	}
}

void search(int r, int c, int goalRow, int goalCol) {
	printf("%d %d\n", r, c);
	if (r == goalRow && c == goalCol) {
		printMaze();
	} else {
		if (maze[r-1][c  ] == ' ') {                 // Up
			maze[r-1][c  ]  = 'O';
			search(r-1, c, goalRow, goalCol);
			maze[r-1][c  ]  = ' ';
		}
		if (maze[r+1][c  ] == ' ') {                 // Down
			maze[r+1][c  ]  = 'O';
			search(r+1, c, goalRow, goalCol);
			maze[r+1][c  ]  = ' ';
		}
		if (maze[r  ][c-1] == ' ') {                 // Left
			maze[r  ][c-1]  = 'O';
			search(r, c-1, goalRow, goalCol);
			maze[r  ][c-1]  = ' ';
		}
		if (maze[r  ][c+1] == ' ') {                 // Right
			maze[r  ][c+1]  = 'O';
			search(r, c+1, goalRow, goalCol);
			maze[r  ][c+1]  = ' ';
		}
	}
}
void dfs() {
	int startRow = -1, startCol = -1, goalRow = -1, goalCol = -1;
	for (int i = 0; maze[i][0] != 0; i++) {
		for (int j = 0; maze[i][j] != 0; j++) {
			if (maze[i][j] == 'R') {
				startRow = i;
				startCol = j;
			}
			if (maze[i][j] == 'X') {
				goalRow  = i;
				goalCol  = j;
			}
		}
	}
	maze[startRow][startCol] = 'O';
	maze[goalRow ][goalCol ] = ' ';
	search(startRow, startCol, goalRow, goalCol);
}

struct item {
	int row;
	int col;
	int parent;
};
struct item queue[MAX*MAX];
int front = 0;
int rear  = 0;
void putQueue(int row, int col, int parent) {
	queue[rear].row = row;
	queue[rear].col = col;
	queue[rear].parent = parent;
	rear++;
}

struct item *getQueue() {
	front++;
	return &(queue[front-1]);
}

int isQueueEmpty() {
	return rear == front;
}

void bfs() {
	int startRow = -1, startCol = -1, goalRow = -1, goalCol = -1;
	for (int i = 0; maze[i][0] != 0; i++) {
		for (int j = 0; maze[i][j] != 0; j++) {
			if (maze[i][j] == 'R') {
				startRow = i;
				startCol = j;
			}
			if (maze[i][j] == 'X') {
				goalRow  = i;
				goalCol  = j;
			}
		}
	}
	maze[startRow][startCol] = 'O';
	maze[goalRow ][goalCol ] = ' ';
	putQueue(startRow, startCol, -1);

	while (!isQueueEmpty()) {
		struct item *current = getQueue();
		printf("%d %d\n", current->row, current->col);
		if (current->row == goalRow && current->col == goalCol) {
			int path = front-1;
			for (int i = 0; maze[i][0] != 0; i++) {
				for (int j = 0; maze[i][j] != 0; j++) {
					if (maze[i][j] == 'O') {
						maze[i][j]  = ' ';
					}
				}
			}

			while (path != -1) {
				maze[queue[path].row][queue[path].col] = 'O';
				path = queue[path].parent;
			}
			printMaze();
			break;
		} else {
			if (maze[current->row-1][current->col] == ' ') {
				maze[current->row-1][current->col]  = 'O';
				putQueue(current->row-1, current->col, front-1);
			}
			if (maze[current->row+1][current->col] == ' ') {
				maze[current->row+1][current->col]  = 'O';
				putQueue(current->row+1, current->col, front-1);
			}
			if (maze[current->row][current->col-1] == ' ') {
				maze[current->row][current->col-1]  = 'O';
				putQueue(current->row, current->col-1, front-1);
			}
			if (maze[current->row][current->col+1] == ' ') {
				maze[current->row][current->col+1]  = 'O';
				putQueue(current->row, current->col+1, front-1);
			}
		}
	}
}

int main() {
	readMaze();
	bfs();
	return 0;
}
