﻿#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <Windows.h>
#include "project_4.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>

#pragma warning(disable : 4996)

void navigace() {

	system("cls");
	int pozice = 1;
	int zmacknuteTlacitko = 0;
	int pozice_case_5 = 0;
	FILE* questions_file_location,* seznam,* question_file_result;
	Info studenti[100], student;
	int i = 0;
	int test_info;
	char word[128];
	char vyber[25];
	

	while (zmacknuteTlacitko != 13) {

		system("cls");
		klavesTady(1, pozice); printf("  osobni udaje\n");
		klavesTady(2, pozice); printf("  Test - 1\n");
		klavesTady(3, pozice); printf("  Test - 2\n");
		klavesTady(4, pozice); printf("  Test - 3\n");
		klavesTady(5, pozice); printf("  Statistika\n");
		klavesTady(6, pozice); printf("  O programe\n");
		klavesTady(7, pozice); printf("  EXIT\n");


		zmacknuteTlacitko = _getch();


		if (zmacknuteTlacitko == 80 && pozice != 7) {
			pozice++;
		}
		else if (zmacknuteTlacitko == 72 && pozice != 1) {
			pozice--;
		}
		else {
			pozice = pozice;
		}

	}

	switch (pozice) {
	case 1:
		StudentInfo();
		break;
	case 2:
		printf("napiste vas VutID\n");
		scanf("%127s", word);
		i = file_scan(word);
		if (i == 1)
		{
			questions_file_location = fopen("questions.txt", "r");
			question_file_result = fopen("question_result.txt", "w+");
			system("cls");

			test_info = questions(questions_file_location);
			seznam = fopen("seznam.txt", "r");
			while (!feof(seznam))
			{
				fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);

				if (!strcmp(student.ID, word))
				{
					snprintf(student.test1, 10, "%d", test_info);
					fprintf(question_file_result, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				}
				else
				{
					fprintf(question_file_result, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				}
			}
			fclose(seznam);
			fclose(question_file_result);
			fclose(questions_file_location);

			question_file_result = fopen("question_result.txt", "r");
			seznam = fopen("seznam.txt", "w");
			while (!feof(question_file_result))
			{

				fscanf(question_file_result, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				fprintf(seznam, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
			}
			fclose(seznam);
			fclose(question_file_result);
			break;
		}
		else
		{
			printf("nejste zapsani, zapiste vasi osobni udaje stisknutim <<Osobni udaje>>");
			break;
		}

	case 3:
		printf("napiste vas VutID\n");
		scanf("%127s", word);
		i = file_scan(word);
		if (i == 1)
		{
			questions_file_location = fopen("questions-2.txt", "r");
			question_file_result = fopen("question_result.txt", "w+");
			system("cls");

			test_info = questions(questions_file_location);
			seznam = fopen("seznam.txt", "r");
			while (!feof(seznam))
			{
				fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);

				if (!strcmp(student.ID, word))
				{
					snprintf(student.test2, 10, "%d", test_info);
					fprintf(question_file_result, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				}
				else
				{
					fprintf(question_file_result, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				}
			}
			fclose(seznam);
			fclose(question_file_result);
			fclose(questions_file_location);

			question_file_result = fopen("question_result.txt", "r");
			seznam = fopen("seznam.txt", "w");
			while (!feof(question_file_result))
			{

				fscanf(question_file_result, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				fprintf(seznam, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
			}
			fclose(seznam);
			fclose(question_file_result);
			break;
		}
		else
		{
			printf("nejste zapsani, zapiste vasi osobni udaje stisknutim <<Osobni udaje>>");
			break;
		}

	case 4:
		printf("napiste vas VutID\n");
		scanf("%127s", word);
		i = file_scan(word);
		if (i == 1)
		{
			questions_file_location = fopen("questions-3.txt", "r");
			question_file_result = fopen("question_result.txt", "w+");
			system("cls");

			test_info = questions(questions_file_location);
			seznam = fopen("seznam.txt", "r");
			while (!feof(seznam))
			{
				fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);

				if (!strcmp(student.ID, word))
				{
					snprintf(student.test3, 10, "%d", test_info);
					fprintf(question_file_result, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				}
				else
				{
					fprintf(question_file_result, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				}
			}
			fclose(seznam);
			fclose(question_file_result);
			fclose(questions_file_location);

			question_file_result = fopen("question_result.txt", "r");
			seznam = fopen("seznam.txt", "w");
			while (!feof(question_file_result))
			{

				fscanf(question_file_result, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
				fprintf(seznam, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
			}
			fclose(seznam);
			fclose(question_file_result);
			break;
		}
		else
		{
			printf("nejste zapsani, zapiste vasi osobni udaje stisknutim <<Osobni udaje>>");
			break;
		}

	case 5:
		/*pozice_case_5 = navigace_statistika();
		if (pozice_case_5 == 1)
		{
			show_all_users();
			_getch();
			navigace_statistika();
		}
		else if (pozice_case_5 == 2)
		{
			printf("vyberte pohlavi (M/Z)\n");
			scanf("%s", word);
			if (strcmp(word, "M"))
			{
				if (strcmp(word, "Z"))
				{
					printf("zkuste znovu");
				}
				else
				{
					show_all_users_podle_pohlavi(word);
				}
			}
			else
			{
				show_all_users_podle_pohlavi(word);
			}
			_getch();
			navigace();
		}
		else if(pozice_case_5 == 3)
		{
			printf("vyberte obor (napr. IBE ,AMT, EKT, MET a t.d.)\n");
			scanf("%s", word);
			show_all_users_podle_oboru(word);
		}
		else if (pozice_case_5 == 4)
		{
			printf("Napiste vas VutID\n");
			scanf("%s", word);
			show_osobni(word);
		}
		else
		{
			navigace();
		}*/

		navigace_statistika();
		break;
	case 6:
		o_programm();
		break;
	case 7:
		exit(99);
		break;
	}
	_getch();
	navigace();
}

void navigace_statistika()
{
	char word[255];
	system("cls");
	int pozice_case_5 = 1;
	int zmacknuteTlacitko_case_5 = 0;
	while (zmacknuteTlacitko_case_5 != 13)
	{
		system("cls");
		klavesTady(1, pozice_case_5); printf("  statistika vseh uzivatelu\n");
		klavesTady(2, pozice_case_5); printf("  statistiku podle pohlavi\n");
		klavesTady(3, pozice_case_5); printf("  statistika podle oboru\n");
		klavesTady(4, pozice_case_5); printf("  osobni statistika \n");
		klavesTady(5, pozice_case_5); printf("  zpet do menu\n");
		zmacknuteTlacitko_case_5 = _getch();


		if (zmacknuteTlacitko_case_5 == 80 && pozice_case_5 != 5)
		{
			pozice_case_5++;
		}
		else if (zmacknuteTlacitko_case_5 == 72 && pozice_case_5 != 1)
		{
			pozice_case_5--;
		}
		else
		{
			pozice_case_5 = pozice_case_5;
		}
	}
	if (pozice_case_5 == 1)
	{
		show_all_users();
		_getch();
		navigace_statistika();
	}
	else if (pozice_case_5 == 2)
	{
		printf("vyberte pohlavi (M/Z)\n");
		scanf("%s", word);
		if (strcmp(word, "M"))
		{
			if (strcmp(word, "Z"))
			{
				printf("zkuste znovu");
			}
			else
			{
				show_all_users_podle_pohlavi(word);
			}
		}
		else
		{
			show_all_users_podle_pohlavi(word);
		}
		_getch();
		navigace_statistika();
	}
	else if (pozice_case_5 == 3)
	{
		printf("vyberte obor (napr. IBE ,AMT, EKT, MET a t.d.)\n");
		scanf("%s", word);
		show_all_users_podle_oboru(word);
		_getch();
		navigace_statistika();
	}
	else if (pozice_case_5 == 4)
	{
		printf("Napiste vas VutID\n");
		scanf("%s", word);
		show_osobni(word);
		_getch();
		navigace_statistika();
	}
	else
	{
		navigace();
	}
	
}
void klavesTady(int aktualniPozice, int sipkaPozice) { //Sipka v navigaci

	if (aktualniPozice == sipkaPozice) { //Pokud je nas vyber na tom
		printf("------> ");
	}
	else {
		printf("          "); //Pokud neni
	}

}

void StudentInfo() {
	FILE* seznam;
	struct Info student;
	char chek_login1[255];
	int counter;
	int value;
	char word[25];
	int i = 0;
	printf("napiste vas VutID");
	scanf("%127s", word);
	i = file_scan(word);
	if (i == 1)
	{
		printf("uz jste zapsan");
		_getch();
		navigace();
	}
	else
	{

		seznam = fopen("seznam.txt", "a");
		if (seznam == NULL)
			return;
		
		printf("Napiste Vase jmeno (Napr. Tomas) .\n");
		scanf("%s", &student.name);
		printf("Napiste Vase prijmeni (Pouzivejte jenom slovesa!) .\n");
		scanf("%s", &student.surname);
		printf("Napiste Vas Obor (Pouzivejte jenom slovesa!) .\n");
		scanf("%s", &student.faculty);
		printf("Napiste Vase Pohlavi.\n");
		scanf("%s", &student.sex);
		printf("Napiste Vas vek.\n");
		scanf("%s", &student.age);
		//VLOZENI DO DATABAZE
		fprintf(seznam, "Jmeno: #%s# Prijmeni: #%s# Obor: #%s# Pohlavi: #%s# Vek: #%s# ID: #%s# Test1: #%s# Test2: #%s# Test3: #%s#\n", student.name, student.surname, student.faculty, student.sex, student.age, word, student.test1, student.test2, student.test3);
		fclose(seznam);
		_getch();
		navigace();
	}

}

int questions(FILE* questions_file_location)
{
	Info student;
	int prumer;
	int i = 0;
	int reading_counter;
	clock_t t;
	char question[255];
	char answer[255];
	char input_answer[255];
	int  count_good_answer = 0;
	int counter;
	int count_file_scan;
	if (questions_file_location == NULL)
	{
		printf("Chiba pri otevirani souboru.\n");
	}
	t = clock();
		while (1)
		{
			reading_counter = fscanf(questions_file_location, "Q: #%254[^#]# A: #%254[^#]#\n", question, answer);
			if (reading_counter == EOF)
				break;
			printf("%s\n", question);
			i++;
			while (1)
			{
				scanf("%s", input_answer);



				if (!strcmp(answer, input_answer))
				{
					count_good_answer++;
					system("cls");
					break;
				}
				
				{
					system("cls");
					break;
				}
			}


		}
		prumer = (count_good_answer * 100 / i);
		printf("spravne jste odpovedel na %d otazek %d %%\n", count_good_answer, prumer);
		fclose(questions_file_location);
		return prumer;
}

void show_all_users() {

	FILE* seznam;
	int counter;
	int i = 0;
	Info student, studenti[100]; //struktura kde sa ulozia data o uzivatelovi
	int code = 0;
	int pocet_uzivatelov = 0;
	int middle , a , b , c;
	seznam = fopen("seznam.txt", "r");

	while (!feof(seznam))
	{
		counter = fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
		if (counter == EOF) {
			strcpy(student.name, "CHYBA"); //ak sa nepodarilo vsetko nacitat, do mena sa ulozi error, aby sme vedeli ze nastala chyba
		}
		if (!strcmp(student.test1, "0") && !strcmp(student.test2, "0") && !strcmp(student.test3, "0")) {
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.name, "CHYBA")) {  //ak nenastal error ulozi ho do pola uzivatelov
			studenti[i] = student;
			i++;
			pocet_uzivatelov++;
		}
		//vrati strukturu hrad
	}
	printf("  Uzivatelia: \n");
	printf(" #  |   Jmeno    |   Test-1    |   Test-2    |   Test-3    |             |\n"
		   "    |            |   vysledek  |   vysledek  |   vysledek  |   prumer    |\n"
	       "----+------------+-------------+-------------+-------------+-------------|\n");
	for (int i = 0; i < pocet_uzivatelov; i++) {  //vypise nazvy vsetkych nacitanych uzivatelov
		a = atoi(studenti[i].test1);
		b = atoi(studenti[i].test2);
		c = atoi(studenti[i].test3);
		middle = ((a+b+c)/3);
		printf("%3d | %10s | %10s%% | %10s%% | %10s%% | %10d%% |\n", i, studenti[i].name, studenti[i].test1, studenti[i].test2, studenti[i].test3, middle);
	}
	fclose(seznam);
	
}

void show_all_users_podle_pohlavi(const char* word) {

	FILE* seznam;
	int counter;
	int i = 0;
	Info student, studenti[100]; //struktura kde sa ulozia data o uzivatelovi
	int code = 0;
	int pocet_uzivatelov = 0;
	int middle, a, b, c;
	seznam = fopen("seznam.txt", "r");

	while (!feof(seznam))
	{
		counter = fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
		if (counter == EOF) {
			strcpy(student.name, "CHYBA"); //ak sa nepodarilo vsetko nacitat, do mena sa ulozi error, aby sme vedeli ze nastala chyba
		}
		if (!strcmp(student.test1, "0") && !strcmp(student.test2, "0") && !strcmp(student.test3, "0")) {
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.sex, word) || strcmp(student.sex, word))
		{
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.name, "CHYBA")) {  //ak nenastal error ulozi ho do pola uzivatelov
			studenti[i] = student;
			i++;
			pocet_uzivatelov++;
		}
		//vrati strukturu hrad
	}
	printf("  Uzivatelia: \n");
	printf(" #  |   Jmeno    |   Test-1    |   Test-2    |   Test-3    |             |\n"
		"    |            |   vysledek  |   vysledek  |   vysledek  |   prumer    |\n"
		"----+------------+-------------+-------------+-------------+-------------|\n");
	for (int i = 0; i < pocet_uzivatelov; i++) {  //vypise nazvy vsetkych nacitanych uzivatelov
		a = atoi(studenti[i].test1);
		b = atoi(studenti[i].test2);
		c = atoi(studenti[i].test3);
		middle = ((a + b + c) / 3);
		printf("%3d | %10s | %10s%% | %10s%% | %10s%% | %10d%% |\n", i, studenti[i].name, studenti[i].test1, studenti[i].test2, studenti[i].test3, middle);
	}
	fclose(seznam);

}

void show_all_users_podle_oboru(const char* word) {

	FILE* seznam;
	int counter;
	int i = 0;
	Info student, studenti[100]; //struktura kde sa ulozia data o uzivatelovi
	int code = 0;
	int pocet_uzivatelov = 0;
	int middle, a, b, c;
	seznam = fopen("seznam.txt", "r");

	while (!feof(seznam))
	{
		counter = fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
		if (counter == EOF) {
			strcpy(student.name, "CHYBA"); //ak sa nepodarilo vsetko nacitat, do mena sa ulozi error, aby sme vedeli ze nastala chyba
		}
		if (!strcmp(student.test1, "0") && !strcmp(student.test2, "0") && !strcmp(student.test3, "0")) {
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.faculty, word))
		{
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.name, "CHYBA")) {  //ak nenastal error ulozi ho do pola uzivatelov
			studenti[i] = student;
			i++;
			pocet_uzivatelov++;
		}
		//vrati strukturu hrad
	}
	printf("  Uzivatelia: \n");
	printf(" #  |   Jmeno    |   Test-1    |   Test-2    |   Test-3    |             |\n"
		"    |            |   vysledek  |   vysledek  |   vysledek  |   prumer    |\n"
		"----+------------+-------------+-------------+-------------+-------------|\n");
	for (int i = 0; i < pocet_uzivatelov; i++) {  //vypise nazvy vsetkych nacitanych uzivatelov
		a = atoi(studenti[i].test1);
		b = atoi(studenti[i].test2);
		c = atoi(studenti[i].test3);
		middle = ((a + b + c) / 3);
		printf("%3d | %10s | %10s%% | %10s%% | %10s%% | %10d%% |\n", i, studenti[i].name, studenti[i].test1, studenti[i].test2, studenti[i].test3, middle);
	}
	fclose(seznam);

}

void show_osobni(const char* word)
{

	FILE* seznam;
	int counter;
	int i = 0;
	Info student; //struktura kde sa ulozia data o uzivatelovi
	int code = 0;
	int middle, a, b, c;
	seznam = fopen("seznam.txt", "r");

	while (!feof(seznam))
	{
		counter = fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
		if (counter == EOF) {
			strcpy(student.name, "CHYBA"); //ak sa nepodarilo vsetko nacitat, do mena sa ulozi error, aby sme vedeli ze nastala chyba
		}
		if (!strcmp(student.test1, "0") && !strcmp(student.test2, "0") && !strcmp(student.test3, "0")) {
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.ID, word))
		{
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.name, "CHYBA")) {  //ak nenastal error ulozi ho do pola uzivatelov
			printf("  Uzivatel: \n");
			printf(" #  |   Jmeno    |   Test-1    |   Test-2    |   Test-3    |             |\n"
				"    |            |   vysledek  |   vysledek  |   vysledek  |   prumer    |\n"
				"----+------------+-------------+-------------+-------------+-------------|\n");
			a = atoi(student.test1);
			b = atoi(student.test2);
			c = atoi(student.test3);
			middle = ((a + b + c) / 3);
			printf("%3d | %10s | %10s%% | %10s%% | %10s%% | %10d%% |\n", i, student.name, student.test1, student.test2, student.test3, middle);
			i++;
		}
		//vrati strukturu hrad
	}
	if (i != 1) 
	{
		printf("Nesplnil jste ani 1 test");
	}
	fclose(seznam);
}

int file_scan(const char* word)
{
	FILE* seznam;
	char buf[512];
	char bod[128];
	Info student;
	int i = 0;
	seznam = fopen("seznam.txt", "r");
	while (!feof(seznam))
	{
		fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);
		if (!strcmp(student.ID, word))
		{
			i++;
		}
	}
	fclose(seznam);
	return i;



}

void o_programm()
{
	
	printf("vypracovany program na tema projektu c. 4\n");
	printf("program je vyvinut v jazyce C.\n");
	printf("Na vyvoji se podileli Denis Jalovecky(203569) a Yaroslav Panfyorov(212273)\n");
	printf("Toto je maly studentsky testovací program\n");
	printf("Chcete-li projít 1 z testu, musite vyplnit sve osobni udaje\n");
	printf("Statistika provadení testu se zobrazi v procentech\n");
	printf("Chcete-li zobrazit prumerne procento uspeanych odpovedí, prejdete do casti\n");
	printf("Statistika -> osobni statistika\n");
	printf("Chcete-li zobrazit statistiku vsech uzivatelu, prejdete do casti\n");
	printf("Statistika -> statistika vsech uzivatelu\n");
	printf("take statistika podle oboru\n");
	printf("Statistika -> statistika podle oboru\n");
	printf("statistika podle pohlavi\n");
	printf("Statistika -> statistika podle pohlavi\n");
	printf("pokud ziskate prumerne procento ze vsech 3 testu\n");
	printf("60%% a vyse, ziskate pristup k tajne hre\n\n\n");
	printf("pro navrat do menu stisknete libovolnou klavesu\n");
	_getch();
	navigace();




}

