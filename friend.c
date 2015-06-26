#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define NAME_LENGTH 256

int matrix[MAX][MAX];
char name[MAX][NAME_LENGTH];
int vertex = 0;
int edge;

int getIndex(char *s) {
	for (int i = 0; i < vertex; i++) {
		if (strcmp(s, name[i]) == 0) {
			return i;
		}
	}
	strcpy(name[vertex++], s);
	return vertex-1;
}

void buildMatrix() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			matrix[i][j] = 0;
		}
	}

	scanf("%d\n", &edge);
	for (int i = 0; i < edge; i++) {
		char s[NAME_LENGTH];
		char t[NAME_LENGTH];
		scanf("%s %s\n", s, t);
		int j = getIndex(s);
		int k = getIndex(t);
		if (j != -1 && k != -1) {
			matrix[j][k] = 1;
			matrix[k][j] = 1;
			matrix[j][j] = 1;
			matrix[k][k] = 1;
		}
	}
}

void printMatrix() {
	for (int i = 0; i < vertex; i++) {
		printf("\t%s", name[i]);
	}
	printf("\n");
	for (int i = 0; i < vertex; i++) {
		printf("%s\t", name[i]);
		for (int j = 0; j < vertex; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	buildMatrix();
	printMatrix();
}
