#include <stdio.h>

int main() {
    int b = ~0;
    printf("%d\n", b);
    bool a = false;
    a |= true;
    printf("%d\n",a);
    return 0;
}
