function dp(left, right) {
	var key = left + "-" + right;
	if (cache[key] != null) return cache[key]
	if (right <= left) return cache[key] = 0;

	var min = null;
	for (var i = 0; i < list.length; i++) {
		if (list[i] >= left && list[i] <= right) {
			var gold = {
				value: right - left,
				left:  dp(left, list[i] - 1),
				right: dp(list[i] + 1, right)
			}
			var sum = gold.value + gold.left + gold.right;
			min = Math.min(min || sum, sum);
		}
	}
	min = min || 0;
	return cache[key] = min;
}

function solve(data) {
	var lines = data.split("\n");
	var T = parseInt(lines[0]);
	for (var t = 1; t <= T; t++) {
		var tokens = lines[2 * t - 1].split(" ");
		var prisoner = parseInt(tokens[0]);
		list = lines[2 * t].split(" ");
		for (var i = 0; i < list.length; i++)
			list[i] = parseInt(list[i]);
		cache = [];
		var result = dp(1, prisoner);
		console.log("Case #" + t + ": " + result);
	}
}

var cache = [];
var list = [];
var buffer = "";

process.stdin.setEncoding('utf8');
process.stdin.on("readable", function() {
	var chunk = process.stdin.read();
	buffer += chunk == null ? "" : chunk;
});
process.stdin.on("end", function() {
	solve(buffer);
});
