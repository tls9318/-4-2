/*int형 스택IntStack(헤더)*/
#ifnedf ___IntStack
#define ___intStack

/*---스택을 구현하는 구조체---*/
typedef struct {
	int max;
	int ptr;
	int* stk;
} IntStack;

/*--- 스택 초기화 ---*/
int Initialize(IntStack* s, int max);

/*--- 스택에 데이터를 푸시---*/
int Push(IntStack* s, int x);

/*--- 스택에서 데이터를 팝---*/
int Pop(IntStack* s, int x);

/*--- 스택에서 데이터를 피크---*/
int Peek(const IntStack* s, int* x);

/*--- 스택 비우기 ---*/
void Clear(IntStack* s);

/*--- 스택의 최대 용량 ---*/
int Capacity(const IntStack* s);

/*--- 스택의 데이터개수---*/
int Size(const IntStack* s);

/*--- 스택이 비어 있나요?---*/
int IsEmpty(const IntStack* s);

/*--- 스택이 가득 찼나요?---*/
int IsFull(const IntStack* s);

/*--- 스택에서 검색---*/
int Search(const IntStack* s, int x);

/*--- 모든 데이터 출력---*/
void print(const IntStack* s);

/*--- 스택 종료 ---*/
void Terminate(IntStack* s);
#endif

/*------------------------------------------------------------------------*/
/*---실습 4-2[A]---*/
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/*--- 스택 초기화 ---*/
int Initialize(IntStack* s, int max)
{
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

/*------------------------------------------------------------------------*/
/*---실습 4-2[B]---*/
/*--- 스택에 데이터를 푸시*/
int Push(IntStack* s, int x)
{
	if (s->ptr >= s->max)
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

/*--- 스택에서 데이터를 팝---*/
int Pop(IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

/*---스택에서 데이터를 피크---*/
int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/*---스택 비우기---*/
void Clear(IntStack* s)
{
	s->ptr = 0;
}

/*-----------------------------------------------------------*/
/*--- 실습 4-2[C]---*/
int Capacity(const IntStack* s)
{
	return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수---*/
int Size(const IntStack* s)
{
	return s->ptr;
}

/*---스택이 비어있는가?---*/
int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0;
}

/*--- 스택은 가득 찼는가?---*/
int IsFull(const IntStack* s)
{
	return s->ptr >= s->max;
}

/*--- 스택에서 검색---*/
int Search(const IntStack* s, int x)
{
	int i;
	for (i = s->ptr - 1; i >= 0; i--)
		if (s->stk[i] == x)
			return i;
	return -1;
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack* s)
{
	int i;
	for (i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- 스택 종료---*/
void Terminate(IntStack* s)
{
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}