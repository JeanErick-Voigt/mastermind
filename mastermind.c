#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char random_number_generator();
void guess_the_number(char *secret_number);

int main()
{
	srand(time(NULL));	
	char final_result_array[4];
	for (int i = 0; i < 4; i++){	
		final_result_array[i]  = random_number_generator();
	}
	guess_the_number(final_result_array);
	return(0);
}

char random_number_generator()
{
		
	int result;
		
	static int num = 0;
	result = rand() % 10;
	

	if(result > 0){
		num++;		
		printf("This is num %d \n", num);		
		return(result + '0');
		
	}else{
		printf("bad number \n");		
		random_number_generator();
	}

}

void guess_the_number(char *secret_number)
{
	char c; 		
	char my_number[5];
	
	//int red_count = 0, white_count = 0;
	int count = 0;
	int array_of_whites[16] = {0};
	int red = 0, white = 0;
	
	int count_a = 0, count_b = 0, count_c = 0, count_d = 0;	
	while(1){			
		printf("Guessing>");		
		fgets(my_number, 5, stdin);
		while (( c = getchar()) != '\n' && c != EOF){}	
		count++;		
		for (int i = 0; i < 4; i++){               
			if(my_number[i] == *(secret_number + i)){
				red++;
			}	
		}
		if (red == 4){
			printf("You won\n");
			printf("It took you %d guesses", count);			
			break;		
		}
		int win_number = 0;	
			
		for (int num = 0; num < 4; num++){
			for (int inside_num = 0; inside_num < 4; inside_num++){
				if (my_number[num] == *(secret_number + inside_num) && num != inside_num){
					if (num == 0){
						
					}					
					array_of_whites[win_number] = num;
					printf("win array number %d \n", array_of_whites[win_number]); // answer line
					win_number++;
					continue;
				}
			}
		}
		// This iterates to through the aray for whites
		for (int x = 0; x < ((sizeof(array_of_whites)/4)) && count_a < 4 && count_b <  4 && count_c < 4 && count_d < 4; x++){
			//printf("This is array_of_whites %d\n", array_of_whites[x]);		
			if(array_of_whites[x] == 0){
				count_a++;
				printf("This is count_a %d \n", count_a);
			}
			else if(array_of_whites[x] == 1){
				count_b++;
				printf("This is count_b %d \n", count_b);
			}
			else if(array_of_whites[x] == 2){
				count_c++;
				printf("This is count_c %d \n", count_c);
			}else if(array_of_whites[x] == 3){
				count_d++;
				printf("This is count_d %d \n", count_d);
			}else{
				continue;
			}
				
		}
		if (count_a > 0){	//because the null pointer always has zero
			white += 1;
		}
		if (count_b > 0){
			white += 1;
		}
		if (count_c > 0){
			white += 1;
		}
		if (count_d > 0){
			white += 1;
		}
		int missed_numbers = 4 - (red + white-1);
	
		if(count_a > 3 || count_b > 3 || count_c > 3 || count_d > 3){
			white = 1;
			if (red > 0){
				white -= 1;
			}

		}//int guess_feedback;		
		if (missed_numbers == 4){
			printf("No matches\n");
		}		
		else if (white >= 3 && white < 4){
			printf("%d white\n", white -1);
		}else if (red < 4 && red >= 3){
			printf("%d red\n", red);
		}else{
			printf("%d red, %d white", red, white );
		} 
		//reset variable values
		array_of_whites[0] = '\0';
		white = 0;
		missed_numbers = 0;
		red = 0;
		count_a = count_b = count_c = count_d = 0;
	
	}		
		
}




