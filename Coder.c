#include<string.h>
#include<strlib.h>
#include"Strin.h"

void mutCezar(char* str, int key) {
	while (*str) {
		if (*str + key  > 'z') {
			*str = 'a' + *str - 'z' + key;
		} else if (*str + key < 'a') {
			*str = 'z' - 'a' + *str + key;
		} else {
			*str = *str + key;
		}
		++str;
	}
}

void mutCodXor(char* str, const char* key) {
	char* kay;
	while (*str) {
		*kay = *key;
		while (*str && *kay) {
			*str = *str ^ *kay;
			++str;
			++kay;
		}
	}
}


char* imutCodCez(const char* str, int key){
	char* str2;
	str2 = malloc(strlen(str) * sizeof(char));
	for (int i=0; i<strlen(str); i++) {
		str2[i] = str[i];
	}
	while (*str) {
		if (*str + key  > 'z') {
			*str = 'a' + *str - 'z' + key;
		} else if (*str + key < 'a') {
			*str = 'z' - 'a' + *str + key;
		} else {
			*str = *str + key;
		}
		++str;
	}
	return str2;
}

char* imutCodXor(const char* str, const char* key) {
	char* str2;
	str2 = malloc(strlen(str) * sizeof(char));
	for(int i=0;i<strlen(str);i++){
		str2[i] = str[i];
	}
	mutCodXor(str2, key);
	return str2;
}