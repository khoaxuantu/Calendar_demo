#include <stdio.h>
#include <string.h>

int monthdays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void calendar(int year, int daynumber, int startMonth, bool wholeCalendar=1);
int daynumber(int year);
void leapyear(int year);

/* Main Function */
int main(int argc, char* argv[])
{
	// Validate command line arguments
	if (argc != 2)
	{
		printf("Missing command line arguments\n");
		printf("Usage: calendar display_calendar_option\n");
		printf("  + display_calendar_option: year/month\n");
		return 1;
	}
	// Read the inputs
	int year;
	printf("Calendar -  ");
	scanf("%d", &year);
	leapyear(year);
	printf("Option %s\n", argv[1]);
	
	if (strcmp(argv[1], "year") == 0)
	{
		calendar(year, daynumber(year), 0);
	}
	if (strcmp(argv[1], "month") == 0)
	{
		int month;
		printf("Month (Number): ");
		scanf("%d", &month);
		calendar(year, daynumber(year), month - 1, 0);
	}
}

/* Checking leap year
* A year is a leap year if:
* - It is divisible by 4
* - It is divisible by 100 and is also divisble by 400
*/
void leapyear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
		{
			monthdays[1] = 29;
			printf("%d is a leap year\n", year);
		}
		else if (year % 100 == 0 && year % 400 == 0)
		{
			monthdays[1] = 29;
			printf("%d is a leap year\n", year);
		}
		else
		{
			printf("%d is not a leap year\n", year);
		}
	}
	else
	{
		printf("%d is not a leap year\n", year);
	}
}

// Calculate first day of a year
int daynumber(int year)
{
	int num1;
	num1 = (year + (year-1)/4 - (year-1)/100 + (year-1)/400) % 7;
	return num1;
}

// Print calendar
void calendar(int year, int num, int startMonth, bool wholeCalendar)
{
	
	int months = 12;

	for(int i = 0; i < months; i++)
	{	
		// Decide to print the whole calendar of only a month by startMonth
		// If wholeCalendar is false then only need to print a month
		// Else print the whole calendar
		if (wholeCalendar || 
			(!wholeCalendar && i == startMonth))
		{
			printf("\n\n%10d%11s", year, month[i]);
			printf("\nSun Mon Tue Wed Thu Fri Sat\n");
			
			for(int day = 1; day <= 1+num*4; day++)
			{
				printf(" ");
			}
			
			for(int day = 1; day <= monthdays[i]; day++)
			{
				printf("%2d ", day);
				if((day+num)%7 > 0)
				{
					printf(" ");
				}
				else
				{
					printf("\n ");
				}
			}
		}
		num = (num + monthdays[i])%7;
	}
	printf("\n");
}
