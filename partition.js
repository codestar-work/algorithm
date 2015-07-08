// run: node partition.js

var numbers = [];
numbers = [5, 2, 1, 8];
numbers = [5, 2, 8, 3];

function partition(numbers) {
	var sum = 0;
	for (var i = 0; i < numbers.length; i++) {
		sum += numbers[i];
	}
	if (sum % 2 != 0) return false;

	var possible = [];
	for (var i = 0; i < numbers.length; i++) {
		possible[i] = [];
		for (var j = 0; j <= sum; j++) {
			possible[i][j] = false;
		}
	}
	possible[0][0] = true;
	possible[0][numbers[0]] = true;

	for (var i = 1; i < numbers.length; i++) {
		for (var j = 0; j <= sum; j++) {
			var previous = j - numbers[i];
			if (previous >= 0) {
				possible[i][j] = possible[i-1][j] || possible[i-1][previous];
			} else {
				possible[i][j] = possible[i-1][j];
			}
		}
	}

	return possible[numbers.length-1][sum/2];
}

console.log(partition(numbers));
