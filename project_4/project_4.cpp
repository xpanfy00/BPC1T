// project_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>	
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "project_4.h"
#include <locale.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 4700)
#pragma warning(disable : 4244)


int main()
{
    /*setlocale(LC_ALL, "CZ");
    struct Info student;
    printf("Vase jmeno\n");
    scanf("%s", &student.name);
    printf("Vase prijmeni\n");
    scanf("%s", &student.surname);
    printf("Vas Obor\n");
    scanf("%s", &student.obor);
    printf("Vas vek\n");
    scanf("%d", &student.age);
    FILE* fp;
    fp = fopen("Info.txt", "a");
    fprintf(fp, "jmeno - %s \n", student.name);
    fprintf(fp, "prijmeni - %s \n", student.surname);
    fprintf(fp, "Obor - %s \n", student.obor);
    fprintf(fp, "vek -%d \n", student.age);
    fclose(fp);
    system("cls");*/
    int i = 0;
    int reading_counter;
    FILE* questions_file_location, result_file_location ;
    questions_file_location = fopen("questions/questions.txt", "r");
    if (questions_file_location == NULL)
    {
        printf("Chiba pri otevirani souboru.\n");
        return 1;
    }
    char question[255];
    char answer[255];
    char input_answer[255];
    char result[255];
    int  count_good_answer = 0;
    int  questions_counter = 0;
    int  count_traing_answer = 0;
    
    while ( 1 )
    {
        reading_counter = fscanf(questions_file_location, "Q: #%254[^#]# A: #%254[^#]#\n", question, answer);
        if (reading_counter == EOF)
            break;
        if (reading_counter == 2)
        { 
            questions_counter++;
            reading_counter = 0;
            printf("%s\n", question);
            while (1)
            {
                scanf("%s", input_answer);

                if (!strcmp(answer, input_answer))
                {
                    count_traing_answer++;
                    count_good_answer++;
                    break;
                }
                else
                {   
                    count_traing_answer++;
                    system("cls");
                    printf("%s", question);
                    printf("\n\nNespravne! skuz znovu!\n");
                }
            }
            printf("spravne jste odpovedel na %d otazek\n", count_good_answer);
            printf("ale ztritil jste %d pokusu\n", count_traing_answer);
        }
        else
        {
            printf("Chyba v subore otazok!\n");
            fclose(questions_file_location);
            return 1;
        }
    }
    fclose(questions_file_location);
    return 0;
   
    /*int i = 0, prav = 0, neprav = 0;
    char a[50], b[10000], c[10000], d[100], e[1000];
    FILE* V, * O, * S, * R;
    R = fopen("Result.txt", "wt");
    fprintf(R, "%s", a);
    fclose(R);
    system("cls");
    V = fopen("Test-1.txt", "r");
    O = fopen("OS.txt", "r");
    S = fopen("ZO.txt", "r");
    while (!feof(V) && !feof(O))
    {
        fgets(b, 1000, V);
        fgets(c, 1000, O);
        printf("%s\n%s", b, c);
        printf("\n otvet: ");
        scanf("%s", &d);
        fscanf(S, "%s", &e);
        if (strcmp(d, e) == 0) { prav++; }
        else { neprav++; }
    }
    printf("vernych  %d\n", prav);
    printf("nevernych %d\n", neprav);
    fclose(O);
    fclose(V);
    system("color F0");
    system("pause");*/
}


