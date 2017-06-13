#include <stdio.h>
#include <unistd.h>

int ModeChoose();
void TrainigModul();


typedef struct wrong{
    struct wrong * next;
    char[20] form1;
    char[20] form2;
    char[20] form3;
    char[20] translate;
    int lastanswer;
} wv;



int main(){
        int mode=ModeChoose();
        wv *head_list;
        TrainigModul(&head_list);
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
                if(answer1==1 || answer1==2 || answer1==3 || answer1==4 || answer1==5){
			break;
		}
		else{
			printf("\nНеверный ввод.");
		}		
	}
	printf("\033[2J\033[1;1H");
    return answer1;
}

void TrainigModul(){
    LoadWords(wv *
}

void LoadWords(wv **head_list){
    FILE *f;
    wv * head=*head_list, tail=&(wv *)p;
    char st[81];
    f=fopen("wrong_verbs.txt", "r");
    if(f==NULL){
                printf("\nНет доступа к файлу. ");
                return -1;
    }
    while(fgets(st,81,f)){
        int i=0, g=0;
        p=(wv*)malloc(sizeof(wv));
        tail->next=p;
        tail=p;
        while(st[i]!='\0' && st[i] && g<20){
            p->form1[g]=st[i];
            i++;
            g++;
        }
        g=0;
        while(st[i]!='\0' && st[i] && g<20){
            p->form2[g]=st[i];
            i++;
            g++;
        }
        g=0;
        while(st[i]!='\0' && st[i] && g<20){
            p->form3[g]=st[i];
            i++;
            g++;
        }
        g=0;
        while(st[i]!='\0' && st[i] && g<20){
            p->translate[g]=st[i];
            i++;
            g++;
        }
    }
    tail->next=NULL;
    }
    fclose(f);
}
