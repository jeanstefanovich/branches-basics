#include <stdio.h>
#include <unistd.h>

int ModeChoose();

int main(){
	ModeChoose();
	return 0;
}

int ModeChoose(){
	int answer1;
	while(1){ 
		printf("\n Введите номер варианта: \n 1. тренировка 50"
		" популярных слов\n 2. для тренировки всех неправильных"
		" глаголов\n\n 3. Повторить 50 популярных глаголов\n"
		"4. Повторить все неправильные глаголы\n 5. Выйти\n");
		scanf("%d", &answer1);
		if(answer1==1 || answer1==2 || answer1==3 || answer1==4){ 
			break;
		}
		else{
			printf("\nНеверный ввод.");
		}		
	}
	printf("\033[2J\033[1;1H");
    return answer1;
}
