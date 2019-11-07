															
#include <stdio.h>
#include <stdlib.h>
//存在问题
#define ERROR NULL
	typedef int ElementType;
	typedef struct LNode* PtrToLNode;
	struct LNode {
		ElementType Data;
		PtrToLNode Next;
	};
	typedef PtrToLNode Position;
	typedef PtrToLNode List;

	Position Find(List L, ElementType X);
	List Insert(List L, ElementType X, Position P);
	List Delete(List L, Position P);

int main()
{
		List L;
		ElementType X;
		Position P, tmp;
		int N;

		L = NULL;
		scanf("%d", &N);
		while (N--) {
			scanf("%d", &X);
			L = Insert(L, X, L);
			if (L == ERROR) printf("Wrong Answer\n");
		}
		for (P = L; P; P = P->Next) printf("%d ", P->Data);
		scanf("%d", &N);
		while (N--) {
			scanf("%d", &X);
			P = Find(L, X);
			if (P == ERROR)
				printf("Finding Error: %d is not in.\n", X);
			else {
				L = Delete(L, P);
				printf("%d is found and deleted.\n", X);
				if (L == ERROR)
					printf("Wrong Answer or Empty List.\n");
			}
		}
		L = Insert(L, X, NULL);
		if (L == ERROR) printf("Wrong Answer\n");
		else
			printf("%d is inserted as the last element.\n", X);
		P = (Position)malloc(sizeof(struct LNode));
		tmp = Insert(L, X, P);
		if (tmp != ERROR) printf("Wrong Answer\n");
		tmp = Delete(L, P);
		if (tmp != ERROR) printf("Wrong Answer\n");
		for (P = L; P; P = P->Next) printf("%d ", P->Data);
		return 0;
}


Position Find(List L, ElementType X)
{
	Position p = NULL;
	for (p = L; p; p = p->Next) {
		if (p->Data == X)
			return p;
	}
	return ERROR;
}
List Insert(List L, ElementType X, Position P)
{
	PtrToLNode t = NULL;
	t = (PtrToLNode)malloc(sizeof(struct LNode));
	t->Data == X;
	t->Next == NULL;
	if (L == P) {           //创建链表 反向
		t->Next = L;
		return t;
	}
	PtrToLNode q = NULL;
	for (q = L; q; q = q->Next) {
		if (q->Next == P) {
			q->Next = t;
			t->Next = P;
			return L;
		}
	}
	printf("Wrong Position for Insertion");
	return ERROR;
}
List Delete(List L, Position P)
{
	PtrToLNode p = NULL;
	PtrToLNode q = NULL;
	if (L == P) {
		L = L->Next;
		free(P);
		return L;
	}
	for (p = L; p; q = p, p = p->Next) {
		if (p == P) {
			q->Next = p->Next;	
			free(P);
			return L;
		}
	}	
	printf("Wrong Position for Deletion\n");
	return ERROR;

}
