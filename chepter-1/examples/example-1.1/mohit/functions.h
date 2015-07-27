#define MAX_SIZE 1000
#define FAILED 1
#define SUCESS 0
#define COMPARE(x,y) ((x>y)?1:((x<y)?-1:0))

int sort(int arr[], int n);
void swap(int *x, int *y);
void genrate_rand_num(int arr[], int n);
int binary_search_iterative(int arr[], int n, int num);
int binary_search_recursive(int arr[], int n, int num, int left, int right);
