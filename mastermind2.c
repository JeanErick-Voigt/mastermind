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
	//printf("This is whole number: %s\n", my_number);	
	printf("TEST TEST TEST This is one of the numbers: %c\n", my_number[2]);	
	printf("TEST TEST  TEST this is my secret number %c\n\n\n", *(secret_number  + 1));
	int red_count = 0, white_count = 0;
	//printf("entering loop");
	int count = 0;
	int tmp_count = 0;
	int win_count = 0;
	char win_array[5];
	int red = 0, white = 0;
	while(win_count != 4){			
		count++;		
		for (int i = 0; i < 4; i++){
			if(my_number[i] == *(secret_number + i)){
					printf("In first\n");					
					//printf("my number i is %d", my_number[i]);
					win_count++;
					printf("wincount %d", win_count);
					//continue;
			}else{
				break;
			}		
		}
		//printf("Next loop is coming");
		if(win_count == 4){
			printf("guessed correctly\n");
			printf("%d red\n", win_count);
			printf("it took you %d guesses ", count);
			break;
		}
		printf("Next loop is here");
		for(int i = 0; i < 4; i++){
			for(int x = 0; x < 4; x++){			
				//printf("for loop statement");	
				//printf("%c %c\*secret_number);
				printf("This is secret number:  %c\n", *(secret_number + x));
				printf("my number i is now :  %c\n", my_number[i]);		
				if(my_number[i] == *(secret_number + x)){
					printf("my number i is %c", my_number[i]);
					red_count++;
					win_array[i] = '1';
					break;
				//else if (my_number[i] == *(secret_number + (x))){
				//					
				//	printf("my number i is %d", my_number[i]);
				//	break;
				}else{
					white_count++;
					if (white_count == 4){
						win_array[i] = '0';
					}
				}
			}
		}							
		for (int number = 0; number < 4; number++){
			if (win_array[number] == '1'){
				red += 1;
			}else{
				white += 1;
			}	
		}
		printf("This is count: %d red, %d white\n", red, white);
		red = 0;
		white = 0;
		win_count = 0;
		
		my_number[0] = '\0';
		printf("Guess again");
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




