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

int main() {
	readMaze();
	dfs();
	// printMaze();
	return 0;
}
