#include<string.h>
#include<strlib.h>
#include"Strin.h"


int ifNumbStr(const char* str) {
	int l;
	l = strlen(str);
	int i = 1;
	int testNS = 1;
	while (testNS && (i < l)) {
		if ((str[i] < 48) || (str[i] > 57)) {
			testNS = 0;
		}
		i += 1;
	}
	return testNS;
}

int ifLettStr(const char* str) {
	int l;
	l = strlen(str);
	int i = 0;
	int testLS = 1;
	while (testLS && (i < l)) {
		if ((str[i] < 65) || ((str[i] > 90) && (str[i] < 97)) || (str[i] > 122)) {
			testLS = 0;
		}
		i += 1;
	}
	return testLS;
}
