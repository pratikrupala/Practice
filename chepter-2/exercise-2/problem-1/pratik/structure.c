#include <stdio.h>
#include <string.h>

#define MAX_NO 2

struct solar_sys {
	char         name[10];
	unsigned int dist;
	int          moons;
};

int main(void)
{
	int i;
	struct solar_sys planets[MAX_NO];

	strcpy(planets[0].name, "Earth");
	planets[0].dist = 10000;
	planets[0].moons = 1;

	strcpy(planets[1].name, "Venus");
	planets[1].dist = 15000;
	planets[1].moons = 3;

	printf("\n");
	for (i = 0; i < MAX_NO; i++) {
		printf("Name of planet: %s\n", planets[i].name);
		printf("Distance from Sun: %u\n", planets[i].dist);
		printf("Number of moons: %d\n", planets[i].moons);
		printf("\n");
	}

	return 0;
}
