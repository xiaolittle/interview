#include <stdio.h>

void multi(){
int a[5] = {2,3,4,5,6};
int left=1;
int right=1;
int ans[5];
for (int k=0;k<5;++k)
    ans[k]=1;
for (int i=0;i<5;i++){
    ans[i]=ans[i]*left;
    ans[5-i-1]=ans[5-i-1]*right;
    printf("%d,ans[i] = %d, ans[5 - i - 1] = %d\n",i,ans[i],ans[5 - i- 1]);
    left=left*a[i];
    right=right*a[5-1-i];
}
    for(int i = 0; i < 5; ++i) {
        printf("%d\n",ans[i]);
    }
}

int main() {
    multi();
}

