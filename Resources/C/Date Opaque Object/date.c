#include <stdlib.h>
#include "date.h"


typedef struct date {
	int day;          // 1 - 28, 1 - 30, 1 - 31, not taking into account leap year for simplicity
	int month;        // January = 1...December = 12
	int year;         // all years after and including 0
} Date;


DATE date_init_default(void) {
	Date* pDate = malloc(sizeof(*pDate));
	if (pDate != NULL) {
		pDate->day = 1;
		pDate->month = 1;
		pDate->year = 1970;
	}
	return pDate;    // returns the address of the date object, or NULL if malloc failed
}




Status date_set_day(DATE hDate, int newDay) {
	Date* pDate = hDate;    // cast to the known type

	// no day can be less than 1 or greater than 31
	// certain months only allow for certain days
	if ((newDay < 1 || newDay > 31) ||
		(pDate->month == 2 && newDay > 28) ||
		((pDate->month == 4 || pDate->month == 5 || pDate->month == 9 || pDate->month == 11) && newDay > 30))
	{
		return FAILURE;
	}

	pDate->day = newDay;
	return SUCCESS;
}


Status date_set_month(DATE hDate, int newMonth) {
	Date* pDate = hDate;
	
	// no month can be less than 1 or greater than 12
	if (newMonth < 1 || newMonth > 12)
		return FAILURE;

	pDate->month = newMonth;
	return SUCCESS;
}


Status date_set_year(DATE hDate, int newYear) {
	Date* pDate = hDate;

	// no year can be less than 0
	if (newYear < 0)
		return FAILURE;

	pDate->year = newYear;
	return SUCCESS;
}




int date_get_day(DATE hDate) {
	Date* pDate = hDate;
	return pDate->day;
}


int date_get_month(DATE hDate) {
	Date* pDate = hDate;
	return pDate->month;
}


int date_get_year(DATE hDate) {
	Date* pDate = hDate;
	return pDate->year;
}





void date_print(DATE hDate) {
	Date* pDate = hDate;

	if (pDate->month < 10)
		printf("0");
	printf("%d/", pDate->month);

	if (pDate->day < 10)
		printf("0");
	printf("%d/", pDate->day);

	if (pDate->year < 10)
		printf("000");
	else if (pDate->year < 100)
		printf("00");
	else if (pDate->year < 1000)
		printf("0");
	printf("%d", pDate->year);
}




void date_destroy(DATE* phDate) {
	Date* pDate = *phDate;
	free(pDate);
	*phDate = NULL;
}
