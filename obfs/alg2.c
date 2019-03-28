#include <stdio.h>

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

int main(int argc, char** argv){
    int a; int b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
}