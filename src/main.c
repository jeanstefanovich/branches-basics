#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include "modul.h"

typedef struct wrong{
    struct wrong * next;
    char form1[20];
    char form2[20];
    char form3[20];
    char translate[20];
    int lastanswer;
} wv;

int ModeChoose();
void TrainigModul();
void LoadWords(wv **head_list,int* structcounter);
void PrintWords(wv **head_list,int* structcounter);

int main(){
    //int mode=ModeChoose();
    wv *head_list;
    int structcounter;
    LoadWords(&head_list, &structcounter);
    PrintWords(head_list, &structcounter);
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

//void TrainigModul(){
    //LoadWords(wv *
//}

void LoadWords(wv **head_list,int* structcounter){
    FILE *f;
    * structcounter=0;
    wv *p=*head_list, *tail=(wv *)&p;
    char st[80];
    f=fopen("wrong_verbs.txt", "r");
    if(f==NULL){
                printf("\nНет доступа к файлу. || No access to file.\n");
                return -1;
    }
    while(fgets(st,81,f)){
        int i=0, g=0;
        p=(wv*)malloc(sizeof(wv));
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
        while(st[i]!='\0' && st[i]!=' ' && g<20){
            p->translate[g]=st[i];
            i++;
            g++;
        }
        p->translate[g]='\0';
        (*structcounter)++;
        printf("\n Первая форма глагола (Fist form): %s",p->form1);
        printf("\n Первая форма глагола (Second form): %s",p->form2);
        printf("\n Первая форма глагола (Third form): %s",p->form3);
        printf("\n Первая форма глагола (Translate): %s",p->translate);
        printf("\n *structcounter=%d",*structcounter);
    }
    tail->next=NULL;
    fclose(f);
}

void PrintWords(wv **head_list,int* structcounter){
        int n=1;//*structcounter;
        printf("\n Repeating %d words",*structcounter);
        wv* p=*head_list;
        for(;n>0 && p!=NULL;n--, p=p->next){
            printf("\n Первая форма глагола (Fist form): %s",p->form1);
            printf("\n Первая форма глагола (Second form): %s",p->form2);
            printf("\n Первая форма глагола (Third form): %s",p->form3);
            printf("\n Первая форма глагола (Translate): %s",p->translate);
        }
    }
