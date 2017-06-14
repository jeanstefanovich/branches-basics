#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "modul.h"
#include <time.h>
#include <string.h>

int main(){
    wv *head_list=(wv*)malloc(sizeof(wv));;
    int structcounter; 
    LoadWords(&head_list, &structcounter);
	while(1){
		int mode=ModeChoose();
		int falsecounter=0, truecounter=0, totalcounter=0;
		switch(mode){
			case 1:
				QuestionAnswer(&head_list, structcounter, &falsecounter, &truecounter, &totalcounter);
				break;
			case 2:
				printf("\033[2J\033[1;1H");
				PrintWords(&head_list, &structcounter);
				printf("\nЧтобы закончить просмотр (Done) нажмите Enter.");
				getchar();
				getchar();
				printf("\033[2J\033[1;1H");
				break;
			case 3:
				return 0;
		}
	}
return 0;
}



