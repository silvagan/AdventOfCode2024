//advent of code 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int main(){
	FILE *fptr;
	char *line = malloc(1000);
	size_t len = 0;
	long read;

	errno_t err = fopen_s(&fptr, "1.txt", "r");

	if (err != 0)
	{
		perror("failed to open file");
		free(line);
		return 1;
	}
	char* token;

	int left[2000];
	int right[2000];
	int working_index = 0;

	while (fgets(line, 1000, fptr) != NULL)
	{
		token = strtok(line, " ");
		printf("%s\n", token);
		left[working_index] = atoi(token);
		token = strtok(NULL, " ");
		printf("%s\n", token);
		right[working_index] = atoi(token);
		working_index++;
	}
	free(line);
	fclose(fptr);

	int sum = 0;

	qsort(left, working_index, sizeof(int), comp);
	qsort(right, working_index, sizeof(int), comp);

	for (int i = 0; i < working_index; i++)
	{
		sum += abs(left[i] - right[i]);
	}
	printf("sum of differences between sorted arrays: %d\n", sum);

	int similarity = 0;
	for (int i = 0; i < working_index; i++)
	{
		for (int j = 0; j < working_index; j++)
		{
			if (left[i] == right[j])
			{
				similarity+=left[i];
			}
		}
	} 
	printf("similarity: %d", similarity);
	return 0;
}
