function Node(data) {
	this.data  = data;
	this.left  = null;
	this.right = null;
}

function insert(node, data) {
	if (node == null) {
		node = new Node(data);
		return node;
	} else {
		if (data < node.data) {
			node.left  = insert(node.left, data);
		} else {
			node.right = insert(node.right, data);
		}
		return node;
	}
}

function print(node) {
	if (node != null) {
		print(node.left);
		console.log(node.data);
		print(node.right);
	}
}

/*
var root = null;
for (var i = 0; i < 100; i++) {
	root = insert(root, parseInt(Math.random() * 100));
}
print(root);
*/
