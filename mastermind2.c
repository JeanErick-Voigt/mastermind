#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char random_generator();
void guess_my_number(char *secret_number);

void main()
{
	srand(time(NULL));	
	char final_result_array[4];
	for (int i = 0; i < 4; i++){	
		final_result_array[i] = random_generator();
		printf("final[i] = %d\n", final_result_array[i]);		
	}
	guess_my_number(final_result_array);
}

char random_generator()
{
	int result;	
	static int num = 0;
	result = rand() % 9;
	printf("this is result %d \n\n", result);

	if(result > 0){
		num++;		
		printf("This is num %d \n", num);		
		return(result);
		
	}else{
		printf("bad number \n");		
		random_generator();
	}
}

void guess_my_number(char *secret_number)
{
	char my_number[5];
	fgets(my_number, 5, stdin);
	printf("This is whole number: %s\n", my_number);
	printf("This is one of the numbers: %c\n", my_number[1]);	
	printf("this is my secret number %d", *(secret_number + 3));
	
	for(int i = 0; i < 4; i++){
		printf("%d", *(secret_number + i));
	}
}




