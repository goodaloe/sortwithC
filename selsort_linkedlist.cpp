/* ID 2015114727
 * NAME Kim Ho-Jeong */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 /////////////////////////////////////////////
struct NODE {
	int val;
	struct NODE *next;
};

/////////////////////////////////////////////
void freelist(struct NODE *head)
{
	struct NODE *next;
	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
}

/////////////////////////////////////////////
void printlist(struct NODE *head)
{
	while (head) {
		fprintf(stdout, "%d\n", head->val);
		head = head->next;
	}
}

/////////////////////////////////////////////
// List SELECTION SORT
struct NODE* selectionsort_list(struct NODE *head)
{

	int i=0, k=0, N=1;




	struct NODE *temphead, *cur, *tail,*prev, *temp, *temp2, *temprev;
	temphead, cur, tail, temp, temp2, prev, temprev = NULL;
	int min = 0;

	cur = head;
	while (cur->next != NULL)
	{
		N++;
		cur = cur->next;
	}
	tail = cur;

	cur = head;
	for (i = 0; i < N; i++) { // after comparing, move to tail
		temp = cur;
		temp2 = cur;
		min = temp->val;
		for (k = 0; k < N - 1 - i; k++) {
			prev = cur;
			cur = cur->next;
			
			if ( min > cur->val)
			{
				temprev = prev;
				temp2 = cur;
				min = cur->val;
			}


		}
		if (temp2 != head)	//in min is not first
		{
			cur = temp;
			if (temprev->next->next != NULL) {
				temprev->next = temprev->next->next;
			}
		}
		else//if min is first
		{
			cur = temp->next;
			if (i != N - 1)
				head = head->next;
		}

		//send to tail
		tail->next = temp2;
		tail = temp2;

		if (i == 0)
			temphead = temp2;
	}
	tail->next = NULL;
	head = temphead;




	/////////////////////////////////////////////
	// FILL: should return sorted list
	/////////////////////////////////////////////

	return head;
}

/////////////////////////////////////////////

int main()
{
	int i, N;
	int val;
	struct NODE *head, *tail, *cur;

	fprintf(stderr, "How many numbers? ");
	fscanf(stdin, "%d", &N);

	head = tail = NULL;
	for (i = 0; i < N; i++) {
		if (fscanf(stdin, "%d", &val) != 1) {
			fprintf(stderr, "cannot read integer from standard input.\n");
			freelist(head);
			exit(0);
		}
		else {
			cur = (struct NODE*) malloc(sizeof(struct NODE));
			cur->val = val;
			cur->next = NULL;
			if (!head) head = tail = cur;
			else {
				tail->next = cur;
				tail = cur;
			}
		}
	}
	head = selectionsort_list(head);

	printlist(head);

	// free memory
	freelist(head);

	return 0;
}
