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
int hra_riskuj(const char* body, FILE* questions_file);
int navigace_riskuj();
int navigace_body();
void show_all_users_fiskuj();





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

struct riskuj
{
    char qustion[255];
    char body[255];
    char answer[255];
    char surname[25];
    char name[25];
    char tema[25];
    char ID[10];
    int result = 0;
    char result1[25];
    char result2[25];
    char result3[25];
};

