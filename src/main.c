#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include "modul.h"

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

void PrintWords(wv **head_list, int* structcounter);
void LoadWords(wv **head_list,int* structcounter);

int main(){
        int mode=ModeChoose();
        wv *head_list;
        int structcounter;
        LoadWords(&head_list, &structcounter);
        PrintWords(&head_list, &structcounter);
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

void LoadWords(wv **head_list,int* structcounter){
    FILE *f;
    *structcounter=0;
    wv* p=*head_list, tail=&(wv *)p;
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
        while(st[i]!='\0' && st[i]!=' ' && g<20){
            p->form1[g]=st[i];
            i++;
            g++;
        }
        p->form1[g]='\0';
        g=0;
        while(st[i]!='\0' && st[i]!=' ' && g<20){
            p->form2[g]=st[i];
            i++;
            g++;
        }
        p->form2[g]='\0';
        g=0;
        while(st[i]!='\0' && st[i]!=' ' && g<20){
            p->form3[g]=st[i];
            i++;
            g++;
        }
        p->form3[g]='\0';
        g=0;
        while(st[i]!='\0' && st[i]!=' ' && g<20){
            p->translate[g]=st[i];
            i++;
            g++;
        }
        p->translate[g]='\0';
        (*structcounter)++;
    }
    tail->next=NULL;
    fclose(f);
}

void PrintWords(wv **head_list, int* structcounter){
    int n=1//*structcounter;
    wv* p=*head_list;
    for(;n>0;n-- && p!=NULL, p=p->next){
        g=0;
        while(p->form1[g]='\0' && g<20){
            printf("%c" p->form1[g]);
            g++;
        }
        p->form1[g]='\0';
        g=0;
        //printf("\n Первая форма глагола (Fist form): %s",p->form1);
        //printf("\n Первая форма глагола (Second form): %s",p->form2);
        //printf("\n Первая форма глагола (Third form): %s",p->form3);
        //printf("\n Первая форма глагола (Translate): %s",p->translate);
    }
}
