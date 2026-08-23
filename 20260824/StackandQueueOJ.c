#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


bool checkthefit(char s1, char s2) {
	//if ((s1 == '(') && (s2 == ']' || s2 == '}')) {
	//	return false;
	//}
	//if ((s1 == '[') && (s2 == ')' || s2 == '}')) {
	//	return false;
	//}
	//if ((s1 == '{') && (s2 == ']' || s2 == ')')) {
	//	return false;
	//}
	if (s1 == '(' && s2 == ')') {
		return true;
	}
	if (s1 == '{' && s2 == '}') {
		return true;
	}
	if (s1 == '[' && s2 == ']') {
		return true;
	}
	return false;
}

//ÓÐÐ§µÄÀ¨ºÅ
bool isValid(char* s) {
	if (s == NULL) {
		return true;
	}
	else {
		char find = *s;
		while (find != '\0') {
			s++;
			char* tmphead = NULL;
			char* tmp = NULL;
			int count = 0;
			while (*s != '\0') {
				if (checkthefit(find, *s)) {
					s++;
					count = 1;
					continue;
				}
				else {
					if (tmp == NULL) {
						tmp = s;
						tmphead = tmp;
						s++;
						tmp++;
						continue;
					}
					*tmp = *s;//
					s++;
					tmp++;
				}
			}
			if (count == 0) {
				return false;
			}
			if (tmphead == NULL) {
				return true;
			}
			
			*tmp = '\0';
			s = tmphead;
			find = *s;
		}
		return true;
	}
}

void main() {
	isValid("([)]");
}