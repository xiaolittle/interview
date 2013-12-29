#include <stdio.h>

int main(int argc, char *argv[])
{
	int num;
	int x,y;
	scanf("%x,%d,%d",&num,&x,&y);
	int mask1 = ~(1 << x);
	//printf("num = %x,x = %d,y = %d,mask = %d\n",num,x,y,mask1);
	num &= mask1;
	//printf("%x\n",num);
	int rightmask = num & ((1 << (y - 2)) - 1);
	int leftmask = 0;
	if(y != 31) {
		leftmask = num & (~((1 << (y + 1)) - 1));
	}
	num = (leftmask | rightmask);

	num |= (6 << (y - 2));


//	int mask2 = (3 << (y - 1));
//	num |= mask2;
//	//printf("%x\n",num);
//	int mask3 = ~(1 << (y - 2));
//	num &= mask3;
	printf("%x\n",num);
	
	return 0;
}
//12345679,0,3
