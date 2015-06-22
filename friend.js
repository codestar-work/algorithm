var friend = [
	["Harry", "Ron"],
	["Harry", "Hagrid"],
	["Ron", "Hermione"],
	["Hermione", "Harry"]
];

/*
  +--------- Hermione
  |            |
  Harry ----- Ron
  |
  Hagrid
*/

function buildMatrix(f) {
	var matrix = [];
	for (var i = 0; i < f.length; i++) {
		if (matrix[f[i][0]] == null)
			matrix[f[i][0]]  = [];
		if (matrix[f[i][1]] == null)
			matrix[f[i][1]]  = [];
		matrix[f[i][0]][f[i][1]] = true;
		matrix[f[i][1]][f[i][0]] = true;
	}
	for (var u in matrix) {
		for (var v in matrix) {
			if (matrix[u][v] != true) {
				matrix[u][v]  = false;
			}
		}
	}
	
	var header = "\t";
	for (var u in matrix) {
		header += u + "\t";
	}
	// console.log(header);
	
	for (var u in matrix) {
		var data = u + "\t";
		for (var v in matrix) {
			if (matrix[u][v] == true)
				data += "1\t";
			else
				data += "0\t";
		}
		// console.log(data);
	}
	return matrix;
}


var matrix = buildMatrix(friend);
showCommon(matrix, "Hermione", "Hagrid");
maxFriend(matrix);

function showCommon(matrix, u, v) {
	for (var f in matrix) {
		if (matrix[u][f] && matrix[f][v]) {
			console.log(f);
		}
	}
}

function maxFriend(matrix) {
	var maxName = "";
	var maxValue = 0;
	for (var u in matrix) {
		var count = 0;
		for (var v in matrix) {
			if (matrix[u][v]) {
				count++;
			}
		}
		if (maxName == "") {
			maxName  = u;
			maxValue = count;
		}
		if (maxValue < count) {
			maxName  = u;
			maxValue = count;
		}
	}
	console.log(maxName + " " + maxValue);
}
