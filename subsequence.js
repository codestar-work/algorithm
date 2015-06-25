// run by node subsequence.js < subsequence.txt

var pattern = "welcome to code jam";

function count(s, p) {
	var table = [];
	for (var j = 0; j < p.length; j++) {
		table[j] = 0;
	}

	for (var i = 0; i < s.length; i++) {
		for (var j = 0; j < p.length; j++) {
			if (s.charAt(i) == p.charAt(j)) {
				if (j == 0) {
					table[j]++;
				} else {
					table[j] += table[j-1];
				}
				table[j] %= 10000;
			}
		}
	}

	return table[p.length-1];
}

function parse(data) {
	var lines = data.split("\n");
	var T = parseInt(lines[0]);
	for (var i = 1; i <= T; i++) {
		var result = count(lines[i], pattern);
		var info = result % 10000;
		if (result < 10) info = "000" + result; else
		if (result < 100) info = "00" + result; else
		if (result < 1000) info = "0" + result;
		console.log("Case #" + i + ": " + info);
	}
}

function main() {
	var process = require("process");
	process.stdin.setEncoding('utf8');
	var buffer = "";
	process.stdin.on("readable", function() {
		var chunk = process.stdin.read();
		buffer += chunk == null ? "" : chunk;
	});

	process.stdin.on("end", function() {
		parse(buffer);
	});
}

main();

// console.log(count("wweell", "wel"));
/*
  w w e e l l c c o o m m e e
w 1 2 2 2 2 2 2 2 2 2 2 2 2 2
e 0 0 2 4 4 4 4 4 4 4 4 4 6 8
l 0 0 0 0 4 8 8 8 8 8 8 8 8 8
c 0 0 0 0 0 0 8
o
m
e

*/
/*
var s = "";
s = "wweellccoommee to code qps jam";
// s = "welcome to code jam";
*/
