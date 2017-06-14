#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "modul.h"
#include <time.h>
#include <string.h>

void QuestionAnswer(wv **head_list, int wordsquantity, int *falsecounter, int *truecounter, int *totalcounter){
	srand(time(NULL));
	int onemoreword=1;
	while(onemoreword){
		int randword=(rand()%wordsquantity);
		int i;
		wv *p=*head_list;
		for(i=0; i<randword && p!=NULL; i++, p=p->next);
        int cue=((rand()%4)+1);
		switch(cue){
            case 1:
                printf("\nПервая форма глагола: %s. ", p->form1);
                break;
            case 2:
                printf("\nВторая форма глагола: %s. ", p->form2);
                break;
            case 3:
                printf("\nТретья форма глагола: %s. ", p->form3);
                break;
            case 4:
                printf("\nПеревод глагола: %s. ", p->translate);
                break;
		}
        int randquestion;
        while((randquestion=((rand()%4)+1))==cue);
        char answer[20];
        switch(randquestion){
            case 1:
                printf("\nВведите первую форму глагола: ");
                scanf("%s", answer);
                if(strcmp(answer,p->form1)==0){
					printf(".\nВерный ответ.");
					(*truecounter)++;
					(*totalcounter)++;
                }
                else{
					printf(".\nНеверный ответ.");
					(*falsecounter)++;
					(*totalcounter)++;
                }
				break;
            case 2:
                printf("\nВведите вторую форму глагола: ");
                scanf("%s", answer);
                if(strcmp(answer,p->form2)==0){
					printf(".\nВерный ответ.");
					(*truecounter)++;
					(*totalcounter)++;
                }
                else{
					printf(".\nНеверный ответ.");
					(*falsecounter)++;
					(*totalcounter)++;
                }
                break;
            case 3:
                printf("\nВведите третью форму глагола: ");
                scanf("%s", answer);
                if(strcmp(answer,p->form3)==0){
					printf(".\nВерный ответ.");
					(*truecounter)++;
					(*totalcounter)++;
                }
                else{
					printf(".\nНеверный ответ.");
					(*falsecounter)++;
					(*totalcounter)++;
                }
                break;
            case 4:
                printf("\nВведите перевод глагола: ");
                scanf("%s", answer);
                if(strcmp(answer,p->translate)==0){
					printf(".\nВерный ответ.");
					(*truecounter)++;
					(*totalcounter)++;
                }
                else{
					printf(".\nНеверный ответ.");
					(*falsecounter)++;
					(*totalcounter)++;
                }
                break;
			}
			while(1){
				printf("\n Ещё слово (next word)?: 1/0 ");
				scanf("%d",&onemoreword);
				if(onemoreword==0 || onemoreword==1){
					break;
				}
				else{
					printf("\nНеверный ввод.");
				}
			}
			if(onemoreword==0){
				int statistic=0;
				while(1){
					printf("\n Показать статистику (show statistic)?: 1/0 ");
					scanf("%d",&statistic);
					if(statistic==0 || statistic==1){
						break;
					}
					else{
						printf("\nНеверный ввод.");
					}
				}
				if(statistic==1){
					float f1=(((float)(*truecounter))/((float)(*totalcounter)))*100, f2=(((float)(*falsecounter))/((float)(*totalcounter)))*100;
					printf("\033[2J\033[1;1H");
					printf("\nПроцент верных ответов (right answers): %3.0f%%.", f1);
					printf("\nПроцент неверных ответов (false answers): %3.0f%%.\n", f2);
				}
			}
	}
}

int ModeChoose(){
    int answer1;
    while(1){
        printf("\n Введите номер варианта: \n1. для тренировки всех"
        " неправильных глаголов\n"
        "2. Повторить все неправильные глаголы\n3. Выйти\n");
        scanf("%d", &answer1);
        if(answer1==1 || answer1==2 || answer1==3){
            break;
        }
        else{
            printf("\nНеверный ввод.");
        }
    }
    printf("\033[2J\033[1;1H");
    return answer1;
}

int LoadWords(wv **head_list,int* structcounter){
    FILE *f;
    *structcounter=0;
    wv *p=*head_list, *tail=(wv *)&p;
    char st[80];
    f=fopen("wrong_verbs.txt", "r");
    if(f==NULL){
                printf("\nНет доступа к файлу. || No access to file.\n");
                return -1;
    }
    while(fgets(st,81,f)){
        int i=0, g=0;
        if((*structcounter)!=0){
			p=(wv*)malloc(sizeof(wv));
		}
		tail->next=p;
        tail=p;
		while(st[i]!='\0' && st[i]!=' ' && g<20){
            p->form1[g]=st[i];
            i++;
            g++;
        }
        p->form1[g]='\0';
        i++;
        g=0;
        while(st[i]!='\0' && st[i]!=' ' && g<20){
            p->form2[g]=st[i];
            i++;
            g++;
        }
        p->form2[g]='\0';
        i++;
        g=0;
        while(st[i]!='\0' && st[i]!=' ' && g<20){
            p->form3[g]=st[i];
            i++;
            g++;
        }
        p->form3[g]='\0';
        i++;
        g=0;
        while(st[i]!='\0' && st[i]!=' ' && g<40){
            p->translate[g]=st[i];
            i++;
            g++;
        }
        p->translate[--g]='\0';
        (*structcounter)++;
        //printf("\n Первая форма глагола (Fist form): %s",p->form1);
        //printf("\n Первая форма глагола (Second form): %s",p->form2);
        //printf("\n Первая форма глагола (Third form): %s",p->form3);
        //printf("\n Первая форма глагола (Translate): %s",p->translate);
        //printf("\n *structcounter=%d",*structcounter);
    }
    tail->next=NULL;
    fclose(f);
    return 0;
}

void PrintWords(wv **head_list,int* structcounter){
	int n=(*structcounter);
    printf("\n Repeating %d words",*structcounter);
    wv* p=*head_list;
    for(;n>0 && p!=NULL;n--, p=p->next){
        printf("\n\n Первая форма глагола (Fist form): %s",p->form1);
        printf("\n Первая форма глагола (Second form): %s",p->form2);
        printf("\n Первая форма глагола (Third form): %s",p->form3);
        printf("\n Первая форма глагола (Translate): %s",p->translate);
    }
}
