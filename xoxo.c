#include<stdio.h>
#include<stdlib.h>
char field[3][3], symbol[3] = " XO";

void reset(){
	for(int x=0;x<=2;x++)
		for(int y=0;y<=2;y++)field[x][y]=' ';
}

void head(){
	system("cls");
	printf("\n\t\t      This GAME is made by liNuX MAllu\n");
}

int end(){
    int rtn=0;
	char terminate='N';
	printf("\n\n\t\tPress any key to continue (or) Q for exit : ");
	fflush(stdin);
	scanf("%c",&terminate);
	if(terminate=='q'||terminate=='Q')rtn=0;
	return rtn;
}

void win(int player){
	printf("\n\n\t*****************************************************************");
	printf("\n\n\t\t\t\tPlayer %d wins\n",player);
	printf("\n\n\t*****************************************************************");
}

void draw(){
	printf("\n\n\t*****************************************************************");
	printf("\n\n\t\t\t\t!!!! GAME DRAW !!!!\n");
	printf("\n\n\t*****************************************************************");
}

void fielddraw(){
	printf("\n\n\t\t\tPlayer[1] = %c\t Player[2] = %c", symbol[1], symbol[2]);
	printf("\n\n\t\t\t\t   1   2   3\n\n");
	printf("\t\t\t\t1  %c | %c | %c \n\t\t\t\t  ---+---+---", field[0][0], field[0][1], field[0][2]);
	printf("\n\t\t\t\t2  %c | %c | %c \n\t\t\t\t  ---+---+---", field[1][0], field[1][1], field[1][2]);
	printf("\n\t\t\t\t3  %c | %c | %c \n", field[2][0], field[2][1], field[2][2]);
}

int checkwin(){
	char player = 'X';
	int count = 0,rtn = 0;
	while(count != 2){
		if(field[0][0]==player && field[0][1]==player && field[0][2]==player){
			rtn=0;
			break;
		}else if(field[1][0]==player && field[1][1]==player && field[1][2]==player){
			rtn = 0;
			break;
		}else if(field[2][0]==player && field[2][1]==player && field[2][2]==player){
			rtn = 0;
			break;
		}else if(field[0][0]==player && field[1][0]==player && field[2][0]==player){
			rtn = 0;
			break;
		}else if(field[0][1]==player && field[1][1]==player && field[2][1]==player){
			rtn = 0;
			break;
		}else if(field[0][2]==player && field[1][2]==player && field[2][2]==player){
			rtn = 0;
			break;
		}else if(field[0][0]==player && field[1][1]==player && field[2][2]==player){
			rtn = 0;
			break;
		}else if(field[0][0]==player && field[1][1]==player && field[2][2]==player){
			rtn = 0;
			break;
		}else if(field[0][2]==player && field[1][1]==player && field[2][0]==player){
			rtn = 0;
			break;
		}else{
			rtn = 1;
		}
		player = 'O';
		count++;
	}

	if( field[0][0]!=' '&&field[0][1]!=' '&&field[0][2]!=' '&&
		field[1][0]!=' '&&field[1][1]!=' '&&field[1][2]!=' '&&
		field[2][0]!=' '&&field[2][1]!=' '&&field[2][2]!=' '){
		rtn=2;
	}
	return rtn;
}

int main()
{
	int status=1, x1=0, y1=0, exit=1, ret=1, player;
	while(exit){
		player = 1;
		reset();
		while(ret){
			head();
			printf("\n\n\n\n\n\t\t\tEnter Player[1] choice (X O): ");
			scanf("%c",&symbol[0]);
			if(symbol[0] == 'O' || symbol[0] == 'o'){
				symbol[1] = 'O';
				symbol[2] = 'X';
				ret = 0;
			}else if(symbol[0] == 'X' || symbol[0] == 'x'){
				symbol[1] = 'X';
				symbol[2] = 'O';
				ret = 0;
			}else{
				head();
				printf("\n\n\n\n\n\t\t\tEnter the player symbol correctly ");
				system("pause >nul");
			}
			fflush(stdin);
		}
		ret++;
		while(status){
			while(ret){
				head();
				fielddraw();
				printf("\n\n\t\t\tEnter the Player %d grid (x y): ",player);
				scanf("%d%d",&x1 ,&y1);
				x1--;
				y1--;
				if(x1<=2 && x1>=0 && y1<=2 && y1>=0){
					if(field[x1][y1] == symbol[1] || field[x1][y1] == symbol[2]){
						head();
						fielddraw();
						printf("\n\n\t\t!!! Grid already used, Enter the grid correctly\n");
						system("pause >nul");
					}else{
						ret=0;
					}
				}else{
					head();
					fielddraw();
					printf("\n\n\t\t  !!! Input Error, Enter the grid correctly\n");
					system("pause >nul");
				}
				fflush(stdin);
			}
			ret++;
			field[x1][y1] = (player == 1)?symbol[1]:symbol[2];
			status = checkwin();
			if(status == 0){
				head();
				fielddraw();
				win(player);
				reset();
				exit = end();
			}
			if(status == 2){
				head();
				fielddraw();
				draw();
				reset();
				exit = end();
			}
			player = (player%2) ? 2 : 1;
		}
		status=1;
	}
	return 0;
}