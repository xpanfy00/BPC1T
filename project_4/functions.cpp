#include <stdlib.h>
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
		questions1();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
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
	FILE* seznam, * chek_login;
	char login[255];
	char chek_login1[255];
	int counter;
	int value;
	int i = 0;
	chek_login = fopen("chek_login.txt", "r+");
	printf("napiste vas vutlogin\n");
	scanf("%s", login);

	while (1)
	{
		counter = fscanf(chek_login, "L: #%254[^#]#\n", chek_login1);
		value = (strcmp(chek_login1, login));
		if (counter == EOF)
			break;
		if (value == 0)
		{
			i++;
		}
	}
	if (i == 1)
	{
		printf("uz jste zapsan");
		fclose(chek_login);
		_getch();
		navigace();

	}
	else
	{

		seznam = fopen("seznam.txt", "a");
		if (seznam == NULL)
			return;
		struct Info student;
		printf("Napiste Vase jmeno (Pouzivejte jenom slovesa!) .\n");
		scanf("%s", &student.name);
		printf("Napiste Vase prijmeni (Pouzivejte jenom slovesa!) .\n");
		scanf("%s", &student.surname);
		printf("Napiste Vas Obor (Pouzivejte jenom slovesa!) .\n");
		scanf("%s", &student.faculty);
		printf("Napiste Vase Pohlavi.\n");
		scanf("%s", &student.sex);
		printf("Napiste Vas vek.\n");
		scanf("%d", &student.age);
		//VLOZENI DO DATABAZE
		fprintf(seznam, "Jmeno: #%s   #   Prijmeni: #%s   # Obor: #%s   #   Pohlavi: #%s   #   Vek:  #%d   #   VutLogin:  #%s   #\n ", &student.name, student.surname, student.faculty, student.sex, student.age, login);
		fprintf(chek_login, "L: #%s#\n", login);
		fclose(seznam);
		fclose(chek_login);
		_getch();
		navigace();
	}

}

void questions1()
{


	int i = 0;
	int reading_counter;
	clock_t t;
	char question[255];
	char answer[255];
	char input_answer[255];
	char result[255];
	int  count_good_answer = 0;
	FILE* questions_file_location, * result_file_location, * fp;
	questions_file_location = fopen("questions.txt", "r");
	fp = fopen("Info_test_1.txt", "a");
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
		while (1)
		{
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
	i = (count_good_answer * 100) / 24;
	printf("spravne jste odpovedel na %d otazek %d procent\n", count_good_answer, i);
	fclose(questions_file_location);
	_getch();
	navigace();
}

