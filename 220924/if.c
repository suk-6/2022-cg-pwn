// if.c
#include <stdio.h>

const char func(int a)
{
	if (a > 89)
	{
		return "A";
	}
	if (a > 79) // else 필요
	{
		return "B";
	}
	if (a > 69)
	{
		return "C";
	}
	if (a > 59)
	{
		return "D";
	}
	return "F";
}
int main()
{
	int a = 0;

	printf("점수를 입력하세요 : ");
	scanf("%d", &a);

	prtinf("%C 등급입니다.\n", func(a));

	return 0;
}

/*
89 A
79 B
69 C
59 D

F
*/