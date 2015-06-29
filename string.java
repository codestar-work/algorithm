import java.util.*;

class Demo {
	static int transform(String s, String t) {
		if (s.length() == 0)
			return t.length();
		if (t.length() == 0)
			return s.length();
		if (s.equals(t))
			return 0;

		if (s.charAt(0) == t.charAt(0)) {
			return transform(s.substring(1), t.substring(1));
		} else {
			int value1 = transform(s.substring(1), t.substring(1)) + 1; // replace
			int value2 = transform(s, t.substring(1)) + 1; // delete
			int value3 = transform(s.substring(1), t) + 1; // insert
			return Math.min(value1, Math.min(value2, value3));
		}
	}

	public static void main(String [] args) {
		int result = transform("KITTEN", "SITTING");
		System.out.println(result);
	}

}
