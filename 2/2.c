#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main (void)
{
	FILE *input;
	fopen_s(&input, "2.txt", "r");
	int bufferlength = 255;
	char buffer[bufferlength];

	const char* seperator = " ";
	int safecount = 0;
	while (fgets(buffer, bufferlength, input))
	{
		printf("read line: '%s'\n", buffer);
		char* token;
		buffer[strcspn(buffer, "\n")] = 0;

		char * context = NULL;
		token = strtok_s(buffer, seperator, &context);
		bool increasing = false;
		int previous = atoi(token);

		token = strtok_s(NULL, seperator, &context);
		int current = atoi(token);
		if (current > previous){
			increasing = true;
		}
		bool correct = true;
		printf("increasing %i\n", increasing);

		int diff = abs(current - previous);
		printf("first difference - %i\n", diff);
		if (diff > 3 || diff < 1){
			correct = false;
		}else
		{
			while ((token = strtok_s(NULL, seperator, &context)) != NULL){	
				
				int temp = current;
				current = atoi(token);
				previous = temp;
				printf("%i - %i\n", previous, current);	
				diff = abs(current - previous);
				printf("difference - %i\n", diff);

				if (diff <= 3 && diff >= 1){
					if ((increasing && current < previous) || (!increasing && current > previous)){
						correct = false;
						printf("break 1\n");
						break;
					}
				}
				else
				{
					correct = false;
					printf("break 2\n");
					break;
				}
			
			}
		}

		if (correct) {safecount += 1; printf("safe\n");}
	}
	printf("%i", safecount);
	return 0;
}





