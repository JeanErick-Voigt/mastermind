#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char random_number_generator();
void guess_the_number(char *secret_number);

void main()
{
	srand(time(NULL));	
	char final_result_array[4];
	for (int i = 0; i < 4; i++){	
		final_result_array[i]  = random__number_generator();
		printf("final[i] = %c\n", final_result_array[i]);		
	}
	guess_the_number(final_result_array);
}

char random_number_generator()
{
	char buffer[20];	
	int result;
	char result2;	
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
	
	int red_count = 0, white_count = 0;
	//printf("entering loop");
	int count = 0;
	int tmp_count = 0;
	int win_count = 0;
	int win_array[16] = {0};
	int red = 0, white = 0;
	char *temp_array;
	int count_a = 0, count_b = 0, count_c = 0, count_d = 0;	
	while(1){			
		printf("Guessing>");		
		fgets(my_number, 5, stdin);
		while (( c = getchar()) != '\n' && c != EOF){}	
		//printf("TEST TEST TEST This is one of the numbers: %c\n", my_number[3]);	
		//printf("TEST TEST  TEST this is my secret number %c\n\n\n", *(secret_number  + 3));
		count++;		
		for (int i = 0; i < 4; i++){               //all correct
			if(my_number[i] == *(secret_number + i)){
				win_count++;
				red++;
			}	
		}
		if (win_count == 4){
			printf("You won\n");			
			break;		
		}
		win_count = 0;
		red = 0;
		
		//mismatched values
		int win_number = 0;	
		//printf("Pre win array values %d", win_aray[5]);	
		for (int num = 0; num < 4; num++){
			for (int inside_num = 0; inside_num < 4 && win_number < 16; inside_num++ && win_number++){
				if (my_number[num] == *(secret_number + inside_num)){
					win_array[win_number] = num;
					printf("inside number %d\n", inside_num);
					printf("win array number %d \n", win_array[win_number]);
					continue;
				}
			}
			printf(win_array[8]);
		}
		for (int x = 0; x < ((sizeof(win_array)/4)) && count_a < 6 && count_b < 6 && count_c < 6 && count_d < 6; x++){
			//printf("This is win_array %d\n", win_array[x]);		
			if(win_array[x] == 0){
				count_a++;
				printf("This is count_a %d \n", count_a);
			}
			else if(win_array[x] == 1){
				count_b++;
				printf("This is count_b %d \n", count_b);
			}
			else if(win_array[x] == 2){
				count_c++;
				printf("This is count_c %d \n", count_c);
			}else if(win_array[x] == 3){
				count_d++;
				printf("This is count_d %d \n", count_d);
			}else{
				continue;
			}
				
		}
		if (count_a > 0){
			red += 1;
		}
		if (count_b > 0){
			red += 1;
		}
		if (count_c > 0){
			red += 1;
		}
		if (count_d > 0){
			red += 1;
		}
		white = 4 - red;
	
		printf("THis is your count %d REDS, and %d WHITES\n", red, white);
		win_array[0] = '\0';
	}		
		
}




