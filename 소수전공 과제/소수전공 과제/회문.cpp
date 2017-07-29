#include<iostream>
using namespace std;

bool is_palindrome(char* str) {
	int num = 0, i;
	while (*str != NULL) {
		num++;
		str++;
	}

	str -= num;
	for (i = 0; i <= num / 2-1; i++) {
		if (*(str + i) != *(str + (num - i-1)))
			break;
	}

	if (i == num / 2)
		return true;
	else
		return false;
}

void main() {
	char str1[] = "level";
	char str2[] = "asdf";
	cout << is_palindrome(str1) << endl;
	cout << is_palindrome(str2) << endl;

}