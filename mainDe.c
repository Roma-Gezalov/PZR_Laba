#include<strio.h>
#include<strlib.h>
#include<string.h>
#include"Strin.h"

int main(int n, char* par[]) {
        int cnm;
	char* codName;
	char* str;
	char* key;
	if (n == 4) {
		codName = par[1];
		str = par[2];
		key = par[3];
	} else {
		cnm = 0;
	}

	if (!strcmp(codName, "--caesar")) {
		cnm = 1;
	} else if (!strcmp(codName, "--xor")) {
		cnm = 2;
	} else {
		cnm = 0;
	}

	int kay;
	if (cnm == 1) {
		if (ifNumbStr(key) == 0) {
			cnm = 0;
		} else {
 			int l, tan;
			l = strlen(key);
			tan = 1;
			kay = 0;
			for (int i = 0; i < l; i++) {
				kay += (key[l - i - 1] - 48) * tan;
				tan *= 10;
			}
			if (key[0] == '-') {
				kay = (kay - (('-' - 48) * (tan/10))) * (-1);
			}
			if ((kay > 26) || (kay < -26)) {
				kay = kay - 26 * (kay / 26);
			}

		}
		if (ifLettStr(str) == 0) {
			cnm = 0;
		}
	}

	if (cnm != 0) {



		if (cnm == 1) {
			mutFilterSp(str);
			mutToLower(str);
			mutCodCez(str, (-1) * kay);
		}
		if (cnm == 2) {
			mutCodXor(str, key);
		}
		printf("%s\n", str);
		return 0;
	} else {
		printf("error:\n");

		return 1;
	}
}
