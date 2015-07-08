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

void findMaxFriend() {
	int maxFriendIndex = 0;
	int maxFriendCount = 0;
	for (int i = 0; i < vertex; i++) {
		int count = 0;
		for (int j = 0; j < vertex; j++) {
			if (matrix[i][j] == 1) {
				count++;
			}
		}
		if (maxFriendCount < count) {
			maxFriendCount = count;
			maxFriendIndex = i;
		}
	}
	printf("%s has maximum number of friend which is %d\n",
		name[maxFriendIndex], maxFriendCount-1);
}

void commonFriend(char *s, char *t) {
	int a = getIndex(s);
	int z = getIndex(t);
	for (int t = 0; t < vertex; t++) {
		if (matrix[a][t] && matrix[t][z]) {
			printf("%s\n", name[t]);
		}
	}
}

int isConnect(char *r, char *s) {
	int rIndex = getIndex(r);
	int sIndex = getIndex(s);
	for (int t = 0; t < vertex; t++) {
		for (int a = 0; a < vertex; a++) {
			for (int z = 0; z < vertex; z++) {
				matrix[a][z] = matrix[a][z] ||
							  (matrix[a][t] && matrix[t][z]);
			}
		}
	}
	return matrix[rIndex][sIndex];
}

int main() {
	buildMatrix();
	printMatrix();
	printf("%d\n", isConnect("Luna", "Ron"));
	printf("%d\n", isConnect("Hagrid", "Tom"));
	return 0;
}
