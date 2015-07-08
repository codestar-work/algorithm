var count = 0;
function permute(s, k) {
	if (k == 0) {
		count++;
		console.log(count + ' ' + s);
	} else {
		for (var i = k; i >= 0; i--) {
			var tmp;
			tmp = s[k]; s[k] = s[i]; s[i] = tmp;
			permute(s, k-1);
			tmp = s[k]; s[k] = s[i]; s[i] = tmp;
		}
	}
}

var a = ['A','B','C','D'];
permute(a, a.length-1);
