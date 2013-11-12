#include <stdio.h>

void replace(char *str) {
	char *t = str;
	int sp = 0;
	while(*t) {
		if(*t == ' ') {
			++sp;
		}
		++t;
	}
	int newLen = t - str + 2 * sp - 1;
	int i = newLen;
	str[i + 1] = '\0';
	--t;
	while(i >= 0) {
		if(*t == ' ') {
			str[i--] = '2';
			str[i--] = '0';
			str[i--] = '%';
		} else {
			str[i--] = *t;
		}
		--t;
	}
}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
