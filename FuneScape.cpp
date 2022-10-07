#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void mainMenu();
void controlGame();

char gameScreen[25][100] = {
"##########################################################################",
"#   #                           #    #                               # E #",
"# P #  #### ## ## ### ## ### ## ## ### # ## #### ## ## ### ## ### ## #   #",
"#      #              #    # #     # #    # #              #    # #      #",
"###    # # # ### ### ## ## #       #     ## # # # ### ### ## ## #      ###",
"#   #  # #     #        #  # #    ####      # #     #        #  # ##     #",
"# ##     ### # #####  # ## # # ## #   # ## # #         ######## # #  #   #",
"# #      #   #  #          # #  #   ## ##     ### # #####  # ## # # ## # #",
"# ### # ## #### # ###    ### #    #           #   #              #       #",
"#     #    # #  #          #   ## # ### ## # #         ###  ### # #  #   #",
"## ## # #         ######## # #  #          #    # #  #          #   ## # #",
"#   # # # #### #         # # ## ## # # # # ## ### #   #   # ##### ## #####",
"# # # #      # ### ### #   #  #     ##      #   # #            #         #",
"# # # ## ### #   #   # ##### ## ####### ## # #      #  ######## # #  #   #",
"#     #      # #   #         #             #   # #            #      #   #",
"# ### #   ## ###  #######  #### ######        #     #            #       |",
"#          # #                      #  ## # #         ######## # #  #    #",
"###    # ### # ####  #### ### ### ####      #   # #            #       ###",
"#      #   # #            #          ###    # # # # ####  #### ###       #",
"#   # ## # # ###   #   #### ####### ## # # ## ### #   #   #  ###     #   #",
"# E #    #                  #        #        #                   #  # E #",
"##########################################################################"};

int fragments = 0;
int row = 2;
int column = 2;
int rowE1 = 20;
int columnE1 = 2;
int rowE2 = 1;
int columnE2 = 71;
int rowE3 = 20;
int columnE3 = 71;

void clearScreen(){
	for(int i=0;i<15;i++){
		puts("");
	}
}

void printMenu(){
	puts("     _____                 ____");
    puts("    |  ___|   _ _ __   ___/ ___|  ___ __ _ _ __   ___");
    puts("    | |_ | | | | '_ \\ / _ \\___ \\ / __/ _` | '_ \\ / _ \\");
    puts("    |  _|| |_| | | | |  __/___) | (_| (_| | |_) |  __/");
    puts("    |_|   \\__,_|_| |_|\\___|____/ \\___\\__,_| .__/ \\___|");
    puts("                                          |_|");
}

void winPage(){
	puts("YOU WIN");
	printf("Press any key to continue");
	getch();
	getch();
	mainMenu();
}

void losePage(){
	system("cls");
	puts("     __   __   _____  _   _   _     ___  ____  _____    __");
    puts("     \\ \\  \\ \\ / / _ \\| | | | | |   / _ \\/ ___|| ____|  / /");
    puts("      \\ \\  \\ V / | | | | | | | |  | | | \\___ \\|  _|   / /");
    puts("      / /   | || |_| | |_| | | |__| |_| |___) | |___  \\ \\");
    puts("     /_/    |_| \\___/ \\___/  |_____\\___/|____/|_____|  \\_\\");
    puts("");
    printf("\t\t Press any key to continue");
    getch();
    getch();
    mainMenu();
}

void printMap(){
	system("cls");
	for(int i=0;i<25;i++){
		for(int j=0;j<100;j++){
			printf("%c",gameScreen[i][j]);
		}
		puts("");
	}
	printf("Key Fragments Collected : %d\n",fragments);
	printf(">> ");
}

void printNewMap(){
	srand(time(NULL));
	int ctr,x,y;
	ctr = 0;
	while(ctr!=5){
		x = 0;
		y = 0;
		x = rand()%74+1;
		y = rand()%22+1;
		if(gameScreen[y][x]==' '){
			gameScreen[y][x] = '*';
			ctr++;
		}
		else{
			continue;
		}
	}
}

void playPage(){
	int choose;
	do{
		clearScreen();
		puts("Select Difficulty");
		puts("1. Insane");
		puts("2. Hard");
		puts("3. Easy");
		scanf("%d",&choose);
		getchar();
	}while(choose<1 || choose>3);
	printNewMap();
	printMap();
	controlGame();
}

void controlEnemy(){
	srand(time(NULL));
	int x,y;
	
	int random = 0;
	while(random == 0){
		x = 0;
		y = 0;
		x = rand()%74+1;
		y = rand()%22+1;
		if(gameScreen[y][x]==' '){
			gameScreen[y][x] = 'E';
			gameScreen[rowE1][columnE1] = ' ';
			rowE1 = y;
			columnE1 = x;
			random = 1;
		}
		if(gameScreen[y][x] == 'P'){
			losePage();
		}
	}
	random = 0;
	while(random == 0){
		x = 0;
		y = 0;
		x = rand()%74+1;
		y = rand()%22+1;
		if(gameScreen[y][x]==' '){
			gameScreen[y][x] = 'E';
			gameScreen[rowE2][columnE2] = ' ';
			rowE2 = y;
			columnE2 = x;
			random = 1;
		}
		if(gameScreen[y][x] == 'P'){
			losePage();
		}
	}
	x = 0;
	y = 0;
	random = 0;
	while(random == 0){
		x = 0;
		y = 0;
		x = rand()%74+1;
		y = rand()%22+1;
		if(gameScreen[y][x]==' '){
			gameScreen[y][x] = 'E';
			gameScreen[rowE3][columnE3] = ' ';
			rowE3 = y;
			columnE3 = x;
			random = 1;
		}
		if(gameScreen[y][x] == 'P'){
			losePage();
		}
	}
	
}

void controlGame(){
	char control;
	control = getch();
	controlEnemy();
	if((control == 'W' || control == 'w') && gameScreen[row-1][column]!='#'){
		if(gameScreen[row-1][column] == '*') {
			fragments++;
		}
		if(gameScreen[row-1][column] == '|' && fragments == 5){
			winPage();
		}
		gameScreen[row][column] = ' ';
		gameScreen[row-1][column] = 'P';
		row -= 1;
		printMap();
	}
	else if((control == 'S' || control == 's') && gameScreen[row+1][column] != '#'){
		if(gameScreen[row+1][column] == '*'){
			fragments++;
		}
		if(gameScreen[row+1][column] == '|' && fragments == 5){
			winPage();
		}
		gameScreen[row][column] = ' ';
		gameScreen[row+1][column] = 'P';
		row += 1;
		printMap();
	}
	else if((control == 'A' || control == 'a') && gameScreen[row][column-1] != '#'){
		if(gameScreen[row][column-1] == '*'){
			fragments++;
		}
		if(gameScreen[row][column-1] == '|' && fragments == 5){
			winPage();
		}
		gameScreen[row][column] = ' ';
		gameScreen[row][column-1] = 'P';
		column -= 1;
		printMap();
	}
	else if((control == 'D' || control == 'd') && gameScreen[row][column+1] != '#'){
		if(gameScreen[row][column+1] == '*'){
			fragments++;
		}
		if(gameScreen[row][column+1] == '|' && fragments == 5){
			winPage();
		}
		gameScreen[row][column] = ' ';
		gameScreen[row][column+1] = 'P';
		column += 1;
		printMap();
	}
	else{
		printMap();
	}
	controlGame();
}

void howToPlay(){
	clearScreen();
	puts("Welcome to FuneScape,");
	puts("");
	puts("You are now locked inside this maze by the evil wizard Efes,");
	puts("");
	puts("but there is no maze that has no end!");
	puts("If you look carefully you could find the escape door symbolized by '|' on the map.");
	puts("");
	puts("You should find 5 key fragments scattered around the maze in order to unlock that door and escape.");
	puts("The fragments are symbolized by '*' on the map, to get it you should travel the maze carefully!");
	puts("");
	puts("Use 'W' to move upwards, 'S' to move downwards, 'A' to move left and 'D' to move right.");
	puts("");
	puts("After you gather all of the fragments the door should be automatically opened");
	puts("Be quick before the monsters of the maze catch up on you!");
	puts("");
	printf("Press any key to continue . . .");
	getch();
	mainMenu();
}

void mainMenu(){
	clearScreen();
	printMenu();
	int choose;
	do{
		puts("1. Play");
		puts("2. How to Play");
		puts("3. Exit game");
		printf(">> ");
		scanf("%d",&choose);
		getchar();
		switch(choose){
			case 1:{
				playPage();
				break;
			}
			case 2:{
				howToPlay();
				break;
			}
			case 3:{
				system("cls");
				break;
			}
		}
	}while(choose!=3);
}

int main(){
	
	mainMenu();
	
	return 0;
}
