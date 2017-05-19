#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char random_generator();
void guess_my_number(char *secret_number);

void main()
{
	srand(time(NULL));	
	char final_result_array[4];
	for (int i = 0; i < 4; i++){	
		final_result_array[i]  = random_generator();
		printf("final[i] = %c\n", final_result_array[i]);		
	}
	guess_my_number(final_result_array);
}

char random_generator()
{
	char buffer[20];	
	int result;
	char result2;	
	static int num = 0;
	result = rand() % 9;
	

	if(result > 0){
		num++;		
		printf("This is num %d \n", num);		
		return(result + '0');
		
	}else{
		printf("bad number \n");		
		random_generator();
	}
}

void guess_my_number(char *secret_number)
{
	char c; 	
	char * str_number;	
	char my_number[5];
	char new_number[5];
	fgets(my_number, 5, stdin);
	my_number[strlen(my_number) - 1] = '\0';
	while (( c = getchar()) != '\n' && c != EOF){}
	printf("This is whole number: %s\n", my_number);	
	//printf("This is one of the numbers: %c\n", new_number[2]);	
	//printf("this is my secret number %c", *(secret_number  + 1));
	int red_count = 0, white_count = 0;
	//printf("entering loop");
	int count = 0;
	int tmp_count = 0;
	int win_count = 0
	while(1){			
		for (int i = 0; i < 4; i++){
			if(my_number[i] == *(secret_number + i)){
					printf("my number i is %d", my_number[i]);
					win_count++;
					continue;
			}else{
				for(int x = 1; x < 4; x++){			
					//printf("for loop statement");	
					//printf("%c %c\n", my_number[0], *secret_number);		
					if(my_number[i] == *(secret_number + x)){
						printf("my number i is %d", my_number[i]);
						red_count++;
						i++;
					
					//else if (my_number[i] == *(secret_number + (x))){
					//	red_count++;					
					//	printf("my number i is %d", my_number[i]);
					//	break;
					}else{
						white_count++;
					}
				}
			}		
		}	
		count++;			
		if(win_count == 4){
			printf("guessed correctly\n");
			printf("%d red\n", red_count);
			printf("it took you %d guesses ", count);
			break;
		}else{
			printf("%d red, %d white\n", red_count, white_count);
			red_count = 0;
			white_count = 0;
		}
		my_number[0] = '\0';
		fgets(my_number, 5, stdin);
		my_number[strlen(my_number) - 1] = '\0';
		while (( c = getchar()) != '\n' && c != EOF){}
	
	
		//for(int i = 0; i < 4; i++){
		//	for(int x = 0; x < 4; x++){
				//if(my_number[i]
		//	}
		//}
		//for(int i = 0; i < 4; i++){
		//	printf("%d", *(secret_number + i));
		//}
	}
	//printf("out of loop %d", count);
}




