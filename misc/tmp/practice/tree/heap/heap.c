#include <stdio.h>

#define HEAP_SIZE 10
#define HEAP_FULL(a) (a == (HEAP_SIZE - 1))
#define HEAP_EMPTY(b) (b == 0)

struct heap_area {
	int data;
};
struct heap_area heap[HEAP_SIZE];
int n = 0;

void heap_push(void)
{
	int d = -1;
	int pos = -1;

	if (HEAP_FULL(n)) {
		printf("Heap is full.\n");
		return;
	}

	printf("Enter new element value: ");
	scanf("%d", &d);

	pos = ++n;
	while ((pos != 1) && (d > heap[pos/2].data)) {
		heap[pos] = heap[pos/2];
		pos /= 2;
	}

	heap[pos].data = d;
}

int heap_pop(void)
{
	int value = -1;
	int tmp = -1;
	int parent = -1;
	int child = -1;

	if (HEAP_EMPTY(n)) {
		printf("\nHeap is empty, nothing to pop.\n");
		exit(EXIT_FAILURE);
	}

	value = heap[1].data;
	tmp = heap[n--].data;
	parent = 1;
	child = 2;

	while (child <= n) {
		if ((child < n) && (heap[child].data < heap[child + 1].data))
			child++;
		if (tmp >= heap[child].data)
			break;
		else
			heap[parent].data = heap[child].data;
		parent = child;
		child *= 2;
	}
	
	heap[parent].data = tmp;

	return value;
}

void print_heap(void)
{
	int i = 0;

	if (HEAP_EMPTY(n)) {
		printf("\nHeap is empty.\n");
		return;
	}

	for (i = 1; i <= n; i ++) {
		printf("heap[%d]: %d\n", i, heap[i].data);
	}
	printf("\n");
}

int main(void)
{
	int c = -1;
	int element = -1;

	while (1) {
		printf("\nPlease select item from below menu:\n");
		printf("1 - Push new element in heap.\n");
		printf("2 - Pop element from heap.\n");
		printf("3 - Print heap elements.\n");
		printf("4 - Find number of elements of heap.\n");
		printf("5 - Finish.\n");

		printf("\nEnter your choice: ");
		scanf("%d", &c);
		switch (c) {
			case 1:
				heap_push();
				break;
			case 2:
				element = heap_pop();
				printf("\nPopped value: %d\n", element);
				break;
			case 3:
				print_heap();
				break;
			case 4:
//				heap_elements();
				break;
			case 5:
				printf("\n");
				goto out;
			default:
				printf("Invalid case.\n");
				break;
		}
	}

out:
	return 0;
}
