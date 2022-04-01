#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main(int argc, char* argv[]) {
	DATE hDate = date_init_default();
	if (hDate == NULL) {
		printf("Error. Failed to create date object due to memory allocation failure.\n");
		exit(1);
	}

	// print original date
	printf("Original Date: ");
	date_print(hDate);
	printf("\n\n");

	int day, month, year;
	int noc;

	// new year
	printf("Enter a new year: ");
	noc = scanf("%d", &year);
	while (getchar() != '\n');    // clear keyboard buffer
	while (noc != 1 || !date_set_year(hDate, year)) {
		if (noc != 1)
			printf("Input error. Enter a number for the year.\n");
		else
			printf("Input error. The year must be greater than or equal to zero.\n");
		printf("Enter a new year: ");
		noc = scanf("%d", &year);
		while (getchar() != '\n');
	}
	printf("You successfully changed the year to %d\n\n", date_get_year(hDate));

	// new month
	printf("Enter a new month: ");
	noc = scanf("%d", &month);
	while (getchar() != '\n');
	while (noc != 1 || !date_set_month(hDate, month)) {
		if (noc != 1)
			printf("Input error. Enter a number for the month.\n");
		else
			printf("Input error. The month must be 1 - 12 and/or be compatible with the day.\n");
		printf("Enter a new month: ");
		noc = scanf("%d", &month);
		while (getchar() != '\n');
	}
	printf("You successfully changed the month to %d\n\n", date_get_month(hDate));


	// new day
	printf("Enter a new day: ");
	noc = scanf("%d", &day);
	while (getchar() != '\n');
	while (noc != 1 || !date_set_day(hDate, day)) {
		if (noc != 1)
			printf("Input error. Enter a number for the day.\n");
		else
			printf("Input error. That is not a valid day for the month.\n");
		printf("Enter a new day: ");
		noc = scanf("%d", &day);
		while (getchar() != '\n');
	}
	printf("You successfully changed the day to %d\n\n", date_get_day(hDate));


	// print updated date
	printf("Update Date: ");
	date_print(hDate);
	printf("\n\n");

	date_destroy(&hDate);
	if (hDate == NULL)
		printf("Successfully avoided a dangling pointer\n");
	else
		printf("Failed to avoid a dangling pointer\n");

	return 0;
}
