#include <stdio.h>
#include <stdlib.h>

typedef struct _Node Node;
struct _Node {
	int info;
	Node *left;
	Node *right;
};

Node *insert(Node *p, int info) {
	if (p == NULL) {
		p = (Node *)malloc(sizeof(Node));
		p->info  = info;
		p->left  = NULL;
		p->right = NULL;
	} else {
		if (info < p->info) {
			p->left  = insert(p->left,  info);
		} else {
			p->right = insert(p->right, info);
		}
	}
	return p;
}

void inorder(Node *p) {
	if (p->left)  inorder(p->left);
	printf("%d\n", p->info);
	if (p->right) inorder(p->right);
}

int main() {
	Node *root = NULL;
	root = insert(root, 4);
	root = insert(root, 6);
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 5);
	root = insert(root, 7);
	inorder(root);
	return 0;
}
