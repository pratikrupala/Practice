#include <stdio.h>
#include <string.h>

#define MAX_NO 4

typedef struct {
	int day;
	int month;
	int year;
} date;

struct human_info {
	char name[10];
	int  age;
	enum {single, married, widowed, divorced} status;
	union {
		date marriage_date;
		date divorce_date;
	} date_info;
	union {
		date death_date;
		int  divorce_nr;
	} extra_info;
};

int main(void)
{
	int i;
	struct human_info  human[MAX_NO];

	strcpy(human[0].name, "Akela");
	human[0].age = 45;
	human[0].status = single;

	strcpy(human[1].name, "Coupled");
        human[1].age = 35;
        human[1].status = married;
        human[1].date_info.marriage_date.day = 15;
	human[1].date_info.marriage_date.month = 6;
	human[1].date_info.marriage_date.year = 2005;

	strcpy(human[2].name, "Widowed");
        human[2].age = 75;
        human[2].status = widowed;
        human[2].date_info.marriage_date.day = 23;
        human[2].date_info.marriage_date.month = 9;
        human[2].date_info.marriage_date.year = 1965;
        human[2].extra_info.death_date.day = 13;
        human[2].extra_info.death_date.month = 2;
        human[2].extra_info.death_date.year = 2007;

	strcpy(human[3].name, "Divorced");
        human[3].age = 55;
        human[3].status = divorced;
        human[3].date_info.divorce_date.day = 23;
        human[3].date_info.divorce_date.month = 9;
        human[3].date_info.divorce_date.year = 1965;
	human[3].extra_info.divorce_nr = 2;

	printf("\n");
	for (i = 0; i < MAX_NO; i++) {
		printf("Category           : %s\n", human[i].name);
		printf("Age                : %d\n", human[i].age);

		if ((human[i].status == married) || (human[i].status == widowed)) {
			printf("Marriage Date      : %d/%d/%d\n", human[i].date_info.marriage_date.day,
							          human[i].date_info.marriage_date.month,
							          human[i].date_info.marriage_date.year);
		}

		if (human[i].status == widowed) {
			printf("Death of spouse    : %d/%d/%d\n", human[i].extra_info.death_date.day,
						  	          human[i].extra_info.death_date.month,
							          human[i].extra_info.death_date.year);
		}

		if (human[i].status == divorced) {
			printf("Date of divorce    : %d/%d/%d\n", human[i].date_info.divorce_date.day,
						                  human[i].date_info.divorce_date.month,
						                  human[i].date_info.divorce_date.year);

			printf("Number of divorces : %d\n", human[i].extra_info.divorce_nr);
		}
		printf("\n");
	}

	return 0;
}
