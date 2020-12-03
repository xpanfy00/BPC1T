#pragma once
void navigace();
void klavesTady(int aktualniPozice, int sipkaPozice);
int questions(FILE* questions_file_location);
void StudentInfo();
void show_all_users();
int file_scan(const char* word);
void navigace_statistika();
void show_all_users_podle_pohlavi(const char* word);
void show_all_users_podle_oboru(const char* word);
void show_osobni(const char* word);
void o_programm();
int hra(FILE* questions_file_location);





struct Info
{
    char name[25];
    char surname[25];
    char sex[25];
    char faculty[25];
    char age[3];
    char ID[10];
    char test1[25] = "0";
    char test2[25] = "0";
    char test3[25] = "0";
};


