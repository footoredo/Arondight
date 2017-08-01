import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static int get(char c) {
		if (c <= '9')
			return c - '0';
		else if (c <= 'Z')
			return c - 'A' + 10;
		else
			return c - 'a' + 36;
	}
	static char get(int x) {
		if (x <= 9)
			return (char)(x + '0');
		else if (x <= 35)
			return (char)(x - 10 + 'A');
		else
			return (char)(x - 36 + 'a');
	}
	static BigInteger get(String s, BigInteger x) {
		BigInteger ans = BigInteger.valueOf(0), now = BigInteger.valueOf(1);
		for (int i = s.length() - 1; i >= 0; i--) {
			ans = ans.add(now.multiply(BigInteger.valueOf(get(s.charAt(i)))));
			now = now.multiply(x);
		}
		return ans;
	}
	public static void main(String [] args) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		for (; ; ) {
			BigInteger x = cin.nextBigInteger();
			if (x.compareTo(BigInteger.valueOf(0)) == 0)
				break;
			String s = cin.next(), t = cin.next(), r = "";
			BigInteger ans = get(s, x).mod(get(t, x));
			if (ans.compareTo(BigInteger.valueOf(0)) == 0)
				r = "0";
			for (; ans.compareTo(BigInteger.valueOf(0)) > 0;) {
				r = get(ans.mod(x).intValue()) + r;
				ans = ans.divide(x);
			}
			System.out.println(r);
		}
	}
}

// Arrays
int a[];
.fill(a[, int fromIndex, int toIndex],val); | .sort(a[, int fromIndex, int toIndex])
// String
String s;
.charAt(int i); | compareTo(String) | compareToIgnoreCase () | contains(String) |
length () | substring(int l, int len)
// BigInteger
.abs() | .add() | bitLength () | subtract () | divide () | remainder () | divideAndRemainder () | modPow(b, c) |
pow(int) | multiply () | compareTo () |
gcd() | intValue () | longValue () | isProbablePrime(int c) (1 - 1/2^c) |
nextProbablePrime () | shiftLeft(int) | valueOf ()
// BigDecimal
.ROUND_CEILING | ROUND_DOWN_FLOOR | ROUND_HALF_DOWN | ROUND_HALF_EVEN | ROUND_HALF_UP | ROUND_UP
.divide(BigDecimal b, int scale , int round_mode) | doubleValue () | movePointLeft(int) | pow(int) |
setScale(int scale , int round_mode) | stripTrailingZeros ()
// StringBuilder
StringBuilder sb = new StringBuilder ();
sb.append(elem) | out.println(sb)
