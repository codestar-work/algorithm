main(bfs);
var data;

function bfs() {
	var maze = read();
	var startRow = -1, startCol = -1;
	var goalRow  = -1, goalCol  = -1;
	for (var i = 0; i < maze.length; i++) {
		for (var j = 0; j < maze[0].length; j++) {
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

	var queue = [];
	var front = 0;
	var rear  = 0;

	function addQueue(info) {
		queue[rear] = info;
		rear++;
	}

	function getQueue() {
		var info = queue[front];
		front++;
		return info;
	}

	function isQueueEmpty() {
		return front == rear;
	}

	addQueue({row: startRow, col:startCol, parent:null});
	while (!isQueueEmpty()) {
		var current = getQueue();
		if (current.row == goalRow && current.col == goalCol) {
			for (var i = 0; i < maze.length; i++) {
				for (var j = 0; j < maze[0].length; j++) {
					if (maze[i][j] == 'O') {
						maze[i][j]  = ' ';
					}
				}
			}
			var info = current;
			while (info != null) {
				maze[info.row][info.col] = 'O';
				info = queue[info.parent];
			}

			show(maze);
			break;
		}

		if (maze[current.row-1][current.col] == ' ') {
			maze[current.row-1][current.col]  = 'O';
			addQueue({row: current.row-1, col:current.col, parent: front-1});
		}
		if (maze[current.row+1][current.col] == ' ') {
			maze[current.row+1][current.col]  = 'O';
			addQueue({row: current.row+1, col:current.col, parent: front-1});
		}
		if (maze[current.row][current.col-1] == ' ') {
			maze[current.row][current.col-1]  = 'O';
			addQueue({row: current.row, col:current.col-1, parent: front-1});
		}
		if (maze[current.row][current.col+1] == ' ') {
			maze[current.row][current.col+1]  = 'O';
			addQueue({row: current.row, col:current.col+1, parent: front-1});
		}
	}

}

function dfs() {
	var maze = read();

	var startRow = -1, startCol = -1;
	var goalRow  = -1, goalCol  = -1;
	for (var i = 0; i < maze.length; i++) {
		for (var j = 0; j < maze[0].length; j++) {
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

	solve(startRow, startCol);

	function solve(row, col) {
		maze [row][col]  = 'O';
		if (row == goalRow && col == goalCol) {
			show(maze);
		} else {
			if (maze [row-1][col] == ' ') {
				solve(row-1, col);
				maze [row-1][col]  = ' ';
			}
			if (maze [row][col-1] == ' ') {
				solve(row, col-1);
				maze [row][col-1]  = ' ';
			}
			if (maze [row+1][col] == ' ') {
				solve(row+1, col);
				maze [row+1][col]  = ' ';
			}
			if (maze [row][col+1] == ' ') {
				solve(row, col+1);
				maze [row][col+1]  = ' ';
			}
		}
	}

}

function read() {
	var lines = data.split('\n');
	var maze = [];
	for (var i = 0; i < lines.length; i++) {
		maze[i] = [];
		for (var j = 0; j < lines[i].length; j++) {
			maze[i][j] = lines[i].charAt(j);
		}
	}
	return maze;
}

function show(maze) {
	var all = "";
	for (var i = 0; i < maze.length; i++) {
		var s = "";
		if (maze[i][0] != null) {
			for (var j = 0; j < maze[0].length; j++) {
				s += maze[i][j];
			}
			// console.log(s);
			all += s + "\n";
		}
	}
	console.log(all);
}

function main(algorithm) {
	var process = require("process");
	process.stdin.setEncoding('utf8');
	var buffer = "";
	process.stdin.on("readable", function() {
		var chunk = process.stdin.read();
		buffer += chunk == null ? "" : chunk;
	});

	process.stdin.on("end", function() {
		data = buffer;
		algorithm();
	});
}
