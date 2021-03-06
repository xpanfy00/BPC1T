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
// hlavni navigaze v ramci programmu
void navigace() {

	system("cls");
	int pozice = 1;
	int zmacknuteTlacitko = 0;
	int pozice_case_5 = 0;
	FILE* questions_file_location,* seznam,* question_file_result,* seznam_riskuj,* riskuj_result;
	Info studenti[100], student;
	int i = 0;
	int test_info;
	char word[128];
	char vyber[25];
	int body;
	int tema;
	char a[255];
	riskuj student_riskuj;
	

	while (zmacknuteTlacitko != 13) { // 13 == ENTER , ciklus se zastavi kdis zamknute tlachitko ENTER

		system("cls");
		klavesTady(1, pozice); printf("  osobni udaje\n");
		klavesTady(2, pozice); printf("  Test - 1\n");
		klavesTady(3, pozice); printf("  Test - 2\n");
		klavesTady(4, pozice); printf("  Test - 3\n");
		klavesTady(5, pozice); printf("  Statistika\n");
		klavesTady(6, pozice); printf("  O programe\n");
		klavesTady(7, pozice); printf("  riskuj\n");
		klavesTady(8, pozice); printf("  EXIT\n");


		zmacknuteTlacitko = _getch();


		if (zmacknuteTlacitko == 80 && pozice != 8) { // 80 = sipka dolu , pokud zamknute sipka dolu a pozice nejsou 8(konec menicka) 
			pozice++;
		}
		else if (zmacknuteTlacitko == 72 && pozice != 1) { // 72 = sipka nahoru
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
		printf("------> ");
		scanf("%127s", word);
		i = file_scan(word);
		if (i == 1) // podle funkce skan . kdis student s takovym vutID existuje spoyusti test 
		{
			questions_file_location = fopen("questions.txt", "r");
			question_file_result = fopen("question_result.txt", "w+");
			system("cls");

			test_info = questions(questions_file_location);// spoustime tes a dostaneme vysledki toho testu ve procentech
			seznam = fopen("seznam.txt", "r");
			while (!feof(seznam)) // ciklus se zastavi kdis budr konec souboru
			{
				// vezmem data z filu 
				fscanf(seznam, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# Obor: #%254[^#]# Pohlavi: #%254[^#]# Vek: #%254[^#]# ID: #%254[^#]# Test1: #%254[^#]# Test2: #%254[^#]# Test3: #%254[^#]#\n", student.name, student.surname, student.faculty, student.sex, student.age, student.ID, student.test1, student.test2, student.test3);

				if (!strcmp(student.ID, word))// najdeme studenta ktery vplnoval test 
				{
					// prevedem int to char aby zapsat do filu 
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
			// tady vezmeme data z filu kde mame vysledky a zapiseme do hlavniho seznamu studentu 
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
		else// kdys student nevplnil osobny udaje . nemuze spoustit test
		{
			printf("nejste zapsani, zapiste vasi osobni udaje stisknutim <<Osobni udaje>>");
			break;
		}

	case 3:
		printf("napiste vas VutID\n");
		printf("------> ");
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
		printf("------> ");
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
		navigace_statistika();
		break;
	case 6:
		o_programm();
		break;
	case 7: 
		FILE * questions_file;
		printf("napiste vas VutID");
		printf("------> ");
		scanf("%s", word);
		i = file_scan(word);
		if (i == 1) { // fungue stejne jako z testama 
			tema = navigace_riskuj();
			body = navigace_body();

			sprintf(a, "%d", body);
			if (tema == 1) {
				questions_file = fopen("Questions_IT.txt", "r");
			}
			else if (tema == 2) {
				questions_file = fopen("Questions_fyzika.txt", "r");
			}
			else {
				questions_file = fopen("Questions_matika.txt", "r");
			}

			student_riskuj.result = hra_riskuj(a, questions_file);
			printf("dostal jste %d bodu", student_riskuj.result);


			seznam_riskuj = fopen("seznam_riskuj.txt", "r");
			riskuj_result = fopen("riskuj_result.txt", "w");

			while (!feof(seznam_riskuj))
			{
				fscanf(seznam_riskuj, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# ID: #%254[^#]# Result1: #%254[^#]# Result2: #%254[^#]# Result3: #%254[^#]#\n", student.name, student.surname, student.ID, student_riskuj.result1, student_riskuj.result2, student_riskuj.result3);

				if (!strcmp(student.ID, word))
				{
					if (tema == 1) {
						i = atoi(student_riskuj.result1);
						student_riskuj.result = i + student_riskuj.result;
						sprintf(student_riskuj.result1, "%d", student_riskuj.result);

					}
					else if (tema == 2) {
						i = atoi(student_riskuj.result2);
						student_riskuj.result = i + student_riskuj.result;
						sprintf(student_riskuj.result2, "%d", student_riskuj.result);
					}
					else {
						i = atoi(student_riskuj.result3);
						student_riskuj.result = i + student_riskuj.result;
						sprintf(student_riskuj.result3, "%d", student_riskuj.result);
					}
					fprintf(riskuj_result, "Jmeno: #%s# Prijmeni: #%s# ID: #%s# Result1:#%s# Result2: #%s# Result3: #%s#\n", student.name, student.surname, student.ID, student_riskuj.result1, student_riskuj.result2, student_riskuj.result3);
				}
				else
				{
					fprintf(riskuj_result, "Jmeno: #%s# Prijmeni: #%s# ID: #%s# Result1:#%s# Result2: #%s# Result3: #%s#\n", student.name, student.surname, student.ID, student_riskuj.result1, student_riskuj.result2, student_riskuj.result3);
				}
			}
			fclose(seznam_riskuj);
			fclose(riskuj_result);

			riskuj_result = fopen("riskuj_result.txt", "r");
			seznam_riskuj = fopen("seznam_riskuj.txt", "w");
			while (!feof(riskuj_result))
			{

				fscanf(riskuj_result, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# ID: #%254[^#]# Result1: #%254[^#]# Result2: #%254[^#]# Result3: #%254[^#]#\n", student.name, student.surname, student.ID, student_riskuj.result1, student_riskuj.result2, student_riskuj.result3);
				fprintf(seznam_riskuj, "Jmeno: #%s# Prijmeni: #%s# ID: #%s# Result1: #%s# Result2: #%s# Result3: #%s#\n", student.name, student.surname, student.ID, student_riskuj.result1, student_riskuj.result2, student_riskuj.result3);
			}
			fclose(seznam_riskuj);
			fclose(riskuj_result);
		}
		else
		{
			printf("nejste zapsani, zapiste vasi osobni udaje stisknutim <<Osobni udaje>>");
			break;
		}
		break;

	case 8:
		exit(99);
		break;
	}
	printf("\n\n\n%(ESC)\n");
	_getch();
	navigace();
} 

void navigace_statistika() // navigaxe v menicku statistika
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
		klavesTady(5, pozice_case_5); printf("  statistika hra riskuj \n");
		klavesTady(6, pozice_case_5); printf("  zpet do menu\n");
		zmacknuteTlacitko_case_5 = _getch();


		if (zmacknuteTlacitko_case_5 == 80 && pozice_case_5 != 6)
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
	else if (pozice_case_5 == 5)
	{
		show_all_users_fiskuj();
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

void StudentInfo() { // zapis osobmich udaju studenta
	FILE* seznam;
	struct Info student;
	char chek_login1[255];
	int counter;
	int value;
	char word[25];
	int i = 0;
	printf("napiste vas VutID");
	printf("------> ");
	scanf("%127s", word);
	i = file_scan(word); // kontrola jeli student uz zapsany 
	if (i == 1) // kdyz uz byl zapsan 
	{
		printf("uz jste zapsan");
		_getch();
		navigace();
	}
	else // kdyz jeste nebyl zapsan 
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

int questions(FILE* questions_file_location) // funkce ktera generuje testy a odsud dostavame vysledky testu 
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
	if (questions_file_location == NULL) // kdyz file neexistuje dostaneme chibu
	{
		printf("Chiba pri otevirani souboru.\n");
	}
	t = clock();
		while (1) //cyklus bude jit pokud nebude prazdny retezec
		{
			reading_counter = fscanf(questions_file_location, "Q: #%254[^#]# A: #%254[^#]#\n", question, answer);
			if (reading_counter == EOF)
				break;
			printf("%s\n", question);
			i++; // mame tady i aby pocitat kolik mame otazek a pocitat procent
			while (1)
			{
				printf("Odpoved\n ");
				printf("------> ");
				scanf("%s", input_answer);



				if (!strcmp(answer, input_answer))
				{
					count_good_answer++;
					system("cls");
					break;
				}
				else
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
	printf("  #  |   Jmeno    |  Prijmeni  |   obor     |  pohlavi   |   Vek      |   Test-1    |   Test-2    |   Test-3    |             |\n"
		   "     |            |            |            |            |            |   vysledek  |   vysledek  |   vysledek  |   prumer    |\n"
		   "-----+------------+------------+------------+------------+------------+-------------+-------------+-------------+-------------|\n");
	for (int i = 0; i < pocet_uzivatelov; i++) {  //vypise nazvy vsetkych nacitanych uzivatelov
		a = atoi(studenti[i].test1);
		b = atoi(studenti[i].test2);
		c = atoi(studenti[i].test3);
		middle = ((a+b+c)/3);
		printf(" % 3d | % 10s | % 10s | % 10s | % 10s | % 10s | % 10s %%| % 10s %%| % 10s %%| % 10d %%| \n", i, studenti[i].name, studenti[i].surname, studenti[i].faculty,studenti[i].sex, studenti[i].age, studenti[i].test1, studenti[i].test2, studenti[i].test3, middle);
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
		if (!strcmp(student.test1, "0") && !strcmp(student.test2, "0") && !strcmp(student.test3, "0")) { // kdyz ma ve vsech testu vysledky 0 tak do mena se ulozi chiba 
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.sex, word) || strcmp(student.sex, word)) // kontrola aby vypisoval jen uzevatelu s stejnym pohlavi 
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
	printf(" #  |   Jmeno    |  Prijmeni  |   pohlavi  |   Test-1    |   Test-2    |   Test-3    |             |\n"
	   	   "    |            |            |            |   vysledek  |   vysledek  |   vysledek  |   prumer    |\n"
		   "----+------------+------------+------------+-------------+-------------+-------------+-------------|\n");
	for (int i = 0; i < pocet_uzivatelov; i++) {  //vypise nazvy vsetkych nacitanych uzivatelov
		a = atoi(studenti[i].test1);
		b = atoi(studenti[i].test2);
		c = atoi(studenti[i].test3);
		middle = ((a + b + c) / 3);
		printf("%3d | %10s | %10s | %10s | %10s%% | %10s%% | %10s%% | %10d%% |\n", i, studenti[i].name, studenti[i].surname, studenti[i].sex, studenti[i].test1, studenti[i].test2, studenti[i].test3, middle);
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
		if (!strcmp(student.test1, "0") && !strcmp(student.test2, "0") && !strcmp(student.test3, "0")) { // kdyz ma ve vsech testu vysledky 0 tak do mena se ulozi chiba 
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
	printf(" #  |   Jmeno    |  Prijmeni  |   Obor     |   Test-1    |   Test-2    |   Test-3    |             |\n"
		   "    |            |            |            |   vysledek  |   vysledek  |   vysledek  |   prumer    |\n"
		   "----+------------+------------+------------+-------------+-------------+-------------+-------------|\n");
	for (int i = 0; i < pocet_uzivatelov; i++) {  //vypise nazvy vsetkych nacitanych uzivatelov
		a = atoi(studenti[i].test1);
		b = atoi(studenti[i].test2);
		c = atoi(studenti[i].test3);
		middle = ((a + b + c) / 3);
		printf("%3d | %10s | %10s | %10s | %10s%% | %10s%% | %10s%% | %10d%% |\n", i, studenti[i].name, studenti[i].surname, studenti[i].sex, studenti[i].test1, studenti[i].test2, studenti[i].test3, middle);
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
		if (!strcmp(student.test1, "0") && !strcmp(student.test2, "0") && !strcmp(student.test3, "0")) { // kdyz ma ve vsech testu vysledky 0 tak do mena se ulozi chiba 
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.ID, word))
		{
			strcpy(student.name, "CHYBA");
		}
		if (strcmp(student.name, "CHYBA")) {  //ak nenastal error ulozi ho do pola uzivatelov
			printf("  Uzivatel: \n");
			printf(" #  |   Jmeno    |  Prijmeni  |   Obor     |   Test-1    |   Test-2    |   Test-3    |             |\n"
				   "    |            |            |            |   vysledek  |   vysledek  |   vysledek  |   prumer    |\n"
				   "----+------------+------------+------------+-------------+-------------+-------------+-------------|\n");
			a = atoi(student.test1);
			b = atoi(student.test2);
			c = atoi(student.test3);
			middle = ((a + b + c) / 3);
			printf("%3d | %10s | %10s | %10s | %10s%% | %10s%% | %10s%% | %10d%% |\n", i, student.name,student.surname, student.faculty, student.test1, student.test2, student.test3, middle);
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

int file_scan(const char* word) // kontrola existuje takovy student nebo ne
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
	int j, k;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (j = 0; j < 10; j++)
		printf("\n");
	printf("%50c ", ' ');

	SetConsoleTextAttribute(hConsole, 240);
	printf("Program pro interaktivní testy ");
	SetConsoleTextAttribute(hConsole, 15);
	printf("\n%56c ", ' ');
	SetConsoleTextAttribute(hConsole, 15);
	printf("\n%23c ", ' ');
	SetConsoleTextAttribute(hConsole, 240);
	printf("Cilem tohoto projektu je vytvorit program pro vyplnovani a vyhodnocovani interaktivnich testu.\n");
	SetConsoleTextAttribute(hConsole, 15);
	printf("%23c ", ' ');
	SetConsoleTextAttribute(hConsole, 240);
	printf("Jedna se o testy ze studentem zvoleneho oboru podane interaktivni(a zabavnou) formou.\n");
	SetConsoleTextAttribute(hConsole, 12);
	printf("\nZakladne parametre programu:");
	SetConsoleTextAttribute(hConsole, 15);
	printf("\n%10c. Po spusteni programu bude uzivatel vyzvan k vyplneni jmena a zakladnich udaju (vek, pohlaví apod.),\n%10c dale bude mozno zvolit test z nekolika oboru. ", '1', ' ');
	printf("\n%10c. Kazdy test bude obsahovat jiny zpusob interakce s clověkem (napr. zvoleni z mozností a,b,c,d ci odpoved textem)"".", '2');
	printf("\n%10c. Vsechny testy se budou nacitat ze souboru a stejne tak jejich vysledky budou archivovany pro moznostnasledneho\n%10c vyhodnoceni. ", '3', ' ');
	printf("\n%10c. Po ukonceni testu budou zobrazeny statistiky daneho testu - napríklad pocet spravne zodpovezenych otazek,\n%10c doba trvaní apod.  ", '4', ' ');
	printf("\n%10c. Po kazdem vyplneni testu budou ulozena statisticka data, ktera se budou prumerovat ze vsech testu zestejne\n%10c skupiny(delenych dle zakladnich udaju apod).\n\n", '5');

	SetConsoleTextAttribute(hConsole, 240);
	printf("Bonusovy ukol:");
	SetConsoleTextAttribute(hConsole, 15);
	printf("\nImplementujte do testu jeden z nasledujicich zpusobu interakce: “hra riskuj”, odkryvani “tajne” informace spravnymi odpovedmi. \n\n\n\t");

	SetConsoleTextAttribute(hConsole, 155);
	printf("Autori:");
	SetConsoleTextAttribute(hConsole, 15);
	printf(" Denis Jalovecky    - BPC-IBE - BPC_PC1T - 2020/2021 - xjalov05@vutbr.cz\n \
	        Yaroslav Panfyorov - BPC-IBE - BPC_PC1T - 2020/2021 - xpanfy00@vutbr.cz\n\n\n%60c(ESC)\n", ' ');

	_getch();
	navigace();




}

int hra_riskuj(const char* body, FILE* questions_file) {

	
	char answer[255];
	char input_answer[255];
	int counter;
	int i = 0;
	riskuj question_info, questions[100]; //struktura kde sa ulozia data o uzivatelovi
	int code = 0;
	int pocet_otazek = 0;
	int a ;
	



	while (!feof(questions_file))
	{
		counter = fscanf(questions_file, "Q: #%254[^#]# Pocet_bodev: #%254[^#]#  A: #%254[^#]#\n",  question_info.qustion, question_info.body, question_info.answer);
		if (counter == EOF) {
			strcpy(question_info.body, "CHYBA"); 
		}
		if (strcmp(question_info.body, "CHYBA")) { 
			questions[i] = question_info;
			i++;
			pocet_otazek++;
		}
	}
	for (int i = 0; i < pocet_otazek; i++) {
		if (!strcmp(questions[i].body, body))
		{
			printf("%s", questions[i].qustion);
		}
	}

	printf("odpoved\n");
	printf("------> ");
	scanf("%s", input_answer);



	if (!strcmp(question_info.answer, input_answer))// vraci body 
	{
		system("cls");
		a = atoi(body);
		return a;
	}

	{
		system("cls");
		a = atoi(body);
		return -a;
	}
	


}

int navigace_riskuj()
{
	char word[255];
	system("cls");
	int pozice_case_5 = 1;
	int zmacknuteTlacitko_case_5 = 0;
	int body = 0;
	char question_file;
	
	while (zmacknuteTlacitko_case_5 != 13)
	{
		system("cls");
		klavesTady(1, pozice_case_5); printf("  IT\n");
		klavesTady(2, pozice_case_5); printf("  fyzika\n");
		klavesTady(3, pozice_case_5); printf("  matika\n");
		klavesTady(4, pozice_case_5); printf("  <-----\n");
		zmacknuteTlacitko_case_5 = _getch();


		if (zmacknuteTlacitko_case_5 == 80 && pozice_case_5 != 4)
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
		
		return 1;
	}
	else if (pozice_case_5 == 2)
	{
	
		return 2;
	}
	else if (pozice_case_5 == 3)
	{
		
		return 3;
	}
	else if (pozice_case_5 == 4)
	{
		navigace();
	}
	
}

int navigace_body()
{
	char word[255];
	system("cls");
	int pozice_case_5 = 1;
	int zmacknuteTlacitko_case_5 = 0;
	while (zmacknuteTlacitko_case_5 != 13)
	{
		system("cls");
		klavesTady(1, pozice_case_5); printf("  100\n");
		klavesTady(2, pozice_case_5); printf("  200\n");
		klavesTady(3, pozice_case_5); printf("  300\n");
		klavesTady(4, pozice_case_5); printf("  500\n");
		klavesTady(5, pozice_case_5); printf("  <-----\n");
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
		//100
		return 100;
	}
	else if (pozice_case_5 == 2)
	{
		//200
		return 200;
	}
	else if (pozice_case_5 == 3)
	{
		//300
		return 300;
	}
	else if (pozice_case_5 == 4)
	{
		//500
		return 500;
	}
	else
	{
		navigace();
	}

}

void show_all_users_fiskuj() {

	FILE* seznam_riskuj;
	int counter;
	int i = 0;
	riskuj  student_riskuj, studenti[100];
	int code = 0;
	int pocet_uzivatelov = 0;
	int sum, a, b, c;
	seznam_riskuj = fopen("seznam_riskuj.txt", "r");

	while (!feof(seznam_riskuj))
	{
		counter = fscanf(seznam_riskuj, "Jmeno: #%254[^#]# Prijmeni: #%254[^#]# ID: #%254[^#]# Result1: #%254[^#]# Result2: #%254[^#]# Result3: #%254[^#]#\n", student_riskuj.name, student_riskuj.surname, student_riskuj.ID, student_riskuj.result1, student_riskuj.result2, student_riskuj.result3);
		if (counter == EOF) {
			strcpy(student_riskuj.name, "CHYBA"); //ak sa nepodarilo vsetko nacitat, do mena sa ulozi error, aby sme vedeli ze nastala chyba
		}
		if (!strcmp(student_riskuj.result1, "0") && !strcmp(student_riskuj.result2, "0") && !strcmp(student_riskuj.result3, "0")) {
			strcpy(student_riskuj.name, "CHYBA");
		}
		if (strcmp(student_riskuj.name, "CHYBA")) {  //ak nenastal error ulozi ho do pola uzivatelov
			studenti[i] = student_riskuj;
			i++;
			pocet_uzivatelov++;
		}
		//vrati strukturu hrad
	}
	printf("  #  |   Jmeno    |  Prijmeni  |   Riskuj    |   Riskuj     |   Riskuj     |             |\n"
		   "     |            |            |   Body-IT   | Body-fyzika  | Body-Matika  |   celkem    |\n"
		   "-----+------------+------------+-------------+--------------+--------------+-------------|\n");
	for (int i = 0; i < pocet_uzivatelov; i++) {  //vypise nazvy vsetkych nacitanych uzivatelov
		a = atoi(studenti[i].result1);
		b = atoi(studenti[i].result2);
		c = atoi(studenti[i].result3);
		sum = (a + b + c);
		printf(" % 3d | %10s | %10s | %11s | %12s | %12s | %11d | \n", i, studenti[i].name, studenti[i].surname, studenti[i].result1, studenti[i].result2, studenti[i].result3, sum);
	}
	fclose(seznam_riskuj);

}

