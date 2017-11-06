#include <stdio.h>
#include <string.h>

int maxi(int x, int y)
{
	printf("in max() for int\n");
	return (x>y)?x:y;
}
float maxf(float x, float y)
{
	printf("in max() for float\n");
	return (x>y)?x:y;
}

#define IS_FLOAT(TYPE) ({\
	int x = 0x0a0a0a0a;\
	TYPE* p;\
	p = (typeof(p))&x;\
	int num = (int)(*p * 3.0);\
	num == 0;\
})

#define MAX(A, B) ({\
	char res[4];\
	char arg1[4];\
	char arg2[4];\
	memcpy(arg1, &A, 4);\
	memcpy(arg2, &B, 4);\
	if(IS_FLOAT(typeof(A)))\
		*(float*)res = maxf(*(float*)arg1,*(float*)arg2);\
	else\
		*(int*)res = maxi(*(int*)arg1,*(int*)arg2);\
	*(typeof(A)*)res;\
})

int main()
{
	int a,b;
	float x,y;
	a = 2;
	b = 3;
	printf("max (should be 3) = %d\n", MAX(a,b));
	x = 5.5;
	y = 6.5;
	printf("max (should be 6.5) = %f\n", MAX(x,y));
}
