#include <bits/stdc++.h>

#define RT(x, y) return std::make_pair(x, y)

std::pair<char, char> convert(std::string EBCDIC) {
	char rc = EBCDIC[0], cc = EBCDIC[1];
	int r = isdigit(rc) ? rc - '0' : 10 + rc - 'A';
	int c = isdigit(cc) ? cc - '0' : 10 + cc - 'A';
	if (r == 0) {
		if (c <= 3) return std::make_pair('0', '0' + c);
		else if (c == 5) return std::make_pair('0', '9');
		else if (c == 7) return std::make_pair('7', 'F');
		else return std::make_pair('0', cc);
	}
	else if (r == 1) {
		if (c <= 3) return std::make_pair('1', '0' + c);
		else if (c == 6) return std::make_pair('0', '8');
		else return std::make_pair('1', cc);
	}
	else if (r == 2) {
		if (c == 5) RT('0', 'A');
		else if (c == 6) RT('1', '7');
		else if (c == 7) RT('1', 'B');
		else if (cc == 'D') RT('0', '5');
		else if (cc == 'E') RT('0', '6');
		else if (cc == 'F') RT('0', '7');
	}:q
	else if (r == 3) {
		if ()
	}:
}

int main() {
}
