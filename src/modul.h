#ifndef _MY_functions
#define _MY_functions
typedef struct wrong{
    struct wrong * next;
    char form1[20];
    char form2[20];
    char form3[20];
    char translate[40];
    int lastanswer;
} wv;
void PrintWords(wv **head_list,int* structcounter);
void QuestionAnswer(wv **head_list, int wordsquantity, int *falsecounter, int *truecounter, int *totalcounter);
int LoadWords(wv **head_list,int* structcounter);
int ModeChoose();
#endif
