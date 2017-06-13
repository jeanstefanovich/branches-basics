#include <stdlib.h>
#include <stdio.h>

void QuestionAnswer(wv **head_list, int wordsquantity, int *falsecounter, int *truecounter, int *totalcounter){
	srand(time(NULL));
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
                while(randquestion=((rand()%4)+1)==cue);
                char answer[20];
                switch(randquestion){
                        case 1:
                            printf("\nВведите первую форму глагола: ");
                            scanf("%s", answer);
                            if(answer==p->form1){
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
                            if(answer==p->form2){
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
                            if(answer==p->form3){
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
                            if(answer==p->translate){
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
	}
}
