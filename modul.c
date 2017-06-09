#include <stdlib.h>
#include <stdio.h>

void QuestionAnswer(wv **head_list, int wordsquantity){
	srand(time(NULL));
	while(onemoreword){
		int randword=(rand()%wordsquantity);
		int i;
		wv *p=*head_list;
		for(i=0; i<randword && p!=NULL; i++, p=p->next);
		int randquestion=((rand()%4)+1);
		switch(c){
			case 1: printf("\nПервая форма глагола: %s. ", p->form1);
			break;
			case 2: printf("\nВторая форма глагола: %s. ", p->form2);
			break;
			case 3: printf("\nТретья форма глагола: %s. ", p->form3);
			break;
			case 4: printf("\nПеревод глагола: %s. ", p->translate);
			break;
		}
		int randanswer;
		while(randanswer=((rand()%4)+1)==randquestion);
		switch(randanswer){
			case 1: printf("\nПервая форма глагола: %s. ", p->form1);
			break;
			case 2: printf("\nВторая форма глагола: %s. ", p->form2);
			break;
			case 3: printf("\nТретья форма глагола: %s. ", p->form3);
			break;
			case 4: printf("\nПеревод глагола: %s. ", p->translate);
			break;
		}
	}
}
