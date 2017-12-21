#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} Slink;

void createR(Slink *&LA, int data[], int n)
{
	Slink *ta;
	for (int idx= 0; idx < n; idx++)
	{
		if (idx <= 0)
		{
			LA = new Slink();
			LA->data = data[idx];
			LA->next = 0;
			ta = LA;
		}
		else
		{
			ta->next = new Slink();
			ta=ta->next;
			ta->data = data[idx];
			ta->next=0;
		}
	}
}
void Display(Slink *L)
{
	Slink *p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void interSet(Slink *LA, Slink *LB, Slink *&LC) 
{
	
	Slink *ta = LA->next, *tb, *tc, *rc;

	LC = (Slink *)malloc(sizeof(Slink));
	rc = LC;
	while (ta)
	{
		tb = LB->next;
		while (tb && tb->data != ta->data)
			tb = tb->next;
		if (tb)
		{
			tc = (Slink *)malloc(sizeof(Slink));
			tc->data = ta->data; //?????
			rc->next = tc;		 //???c
			rc = tc;			 //?????
		}
		ta = ta->next;
	}

	rc->next = 0;
}
void unionSet(Slink *LA, Slink *LB, Slink *&LC) //???
{
	if (!LA && !LB) //a?b??
	{
		LC = 0;
	}
	else if (LA && !LB) //a??b?
	{
		Slink *tc;
		Slink *ta;

		LC = (Slink *)malloc(sizeof(Slink));
		tc = LC;
		ta = LA;

		while (ta)
		{
			tc->data = ta->data;
			if (ta->next)
			{
				tc->next = (Slink *)malloc(sizeof(Slink));
				tc = tc->next;
			}
			else
			{
				tc->next = 0;
			}
			ta = ta->next;
		}
	}
	else if (!LA && LB) //a?b??
	{
		Slink *tc;
		Slink *tb;

		LC = (Slink *)malloc(sizeof(Slink));
		tc = LC;
		tb = LB;

		while (tb)
		{
			tc->data = tb->data;
			if (tb->next)
			{
				tc->next = (Slink *)malloc(sizeof(Slink));
				tc = tc->next;
			}
			else
			{
				tc->next = 0;
			}
			tb = tb->next;
		}
	}
	 if (LA && LB)
	{
		Slink *tc, *rc;
		Slink *ta;
		Slink *tb;

		LC = (Slink *)malloc(sizeof(Slink));
		tc = LC;
		ta = LA;

		while (ta)
		{
			tc->data = ta->data;
			if (ta->next)
			{
				tc->next = (Slink *)malloc(sizeof(Slink));
				tc = tc->next;
			}
			else
			{
				rc = tc;
			}
			ta = ta->next;
		}

		tb = LB;

		while (tb)
		{
			ta = LC;

			while (ta != rc)
			{
				if (ta->data == tb->data)
				{
					break;
				}
				else
				{
					ta = ta->next;
				}
			}

			if (ta == rc) //??????
			{
				if (rc->data != tb->data) //?????????
				{
					tc->next = (Slink *)malloc(sizeof(Slink));
					tc = tc->next;
					tc->data = tb->data;
				}
			}

			tb = tb->next;
		}

		tc->next = 0;
	}
}
int main()
{
	Slink *L, *T, *P;
	int a[] = {2};
	int b[] = {1,2,3,4};
	createR(L, a, 1);
	createR(T, b, 4);
	interSet(L, T, P);
	//unionSet(L,T,P);
	Display(P);
	return 0;
}
