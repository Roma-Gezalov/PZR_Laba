#include<string.h>
#include<strlib.h>
#include"Strin.h"

char* toShifter(const char* str, int n) {
	int l;
	l = strlen(str);
	char* str2;
	str2 = malloc(l * sizeof(char));
	for (int i = 0; i < l; i++) {
		if ((str[i] > 96 - (n + 1) * 16) && (str[i] < 123- (n + 1) * 16)) {
			str2[i] = (char)(str[i] + n * 32);
		} else {
			str2[i] = (char) str[i];
		}
	}
	return str2;
}
char* imutToUpper(const char* str) {
        return toShifter(str, -1);
}
char* imutToLower(const char* str) {
       return toShifter(str, 1);
}

char* imutFilter(const char* str) {
	int l;
	l = strlen(str);
	char* str2;
	str2 = malloc(l * sizeof(char));
	int j = 0;
	for(int i = 0; i < l; i++){
		if(
((47 < str[i]) && (str[i] < 57)) || ((64 < str[i]) && (str[i] < 91)) || ((96 < str[i]) && (str[i] < 122)) || (str[i] == ' ')
		){
			str2[j] = str[i];
   			j += 1;
		}
	}
	str2 = realloc(str2, (1 + j) * sizeof(char));
        str2[j] ='\0';
	return str2;
}

char* imutFilterSp(const char* str) {
	int l;
	l = strlen(str);
	char* str2;
	str2 = malloc(l * sizeof(char));
	int j = 0;
	for (int i = 0; i < l; i++) {
		if (str[i] != ' ') {
			str2[j] = str[i];
			j += 1;
		}
	}
	str2 = realloc(str2, (2 + j) * sizeof(char));
	str2[j+1] = '\0';
	return str2;
}

char* imutDelSp(const char* str) {
	int l;
	l = strlen(str);
	int frontSp, tailSp;
	{
		int i = 0;
		while (str[i] == ' ') {
			i += 1;
		}
		frontSp = i;
	}
	{
		int i = l - 1;
		while (str[i] == ' ') {
			i += 1;
		}
		tailSp = i;
	}
	char* str2;
	str2 = malloc((tailSp - frontSp + 2) * sizeof(char));
	int j = 0;
	for (int i = frontSp; i < tailSp + 1; i++) {
		str2[j] = str[i];
		j += 1;
	}
	str2[j+1] = '\0';
	return str2;
}

void mutToUpper(char* str) {
        char* str2;
        str2 = imutToUpper(str);
        while (*str) {
                *str = *str2;
                *str++;
                *str2++;
        }
}
void mutToLower(char* str) {
        char* str2;
        str2 = imutToLower(str);
        while (*str) {
                *str = *str2;
                *str++;
                *str2++;
        }
}
void mutFilter(char* str) {
        char* str2;
        str2 = imutFilter(str);
	str = realloc(str2, strlen(str2) * sizeof(char));
}
void mutFilterSp(char* str) {
        char* str2;
        str2 = imutFilterSp(str);
        while (*str) {
                *str = *str2;
                *str++;
                *str2++;
        }
}
void mutDelSp(char* str) {
        char* str2;
        str2 = imutDelSp(str);
        while (*str) {
                *str = *str2;
                *str++;
                *str2++;
        }
}