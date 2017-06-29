#include <stdio.h>
#include <iostream>
#define STRLEN 80
#define WORDLEN 15
#define WORDNUMB 20
void foo(char* slovo);
using namespace std;
int main()
{
	int count[WORDLEN]; //Массив для подсчёта встречаемости слов
	int i, j, k, l, m, p;
	char str[STRLEN];  //Введенная строка
	char word[WORDLEN]; //Текущее слово
	char dict[WORDNUMB][WORDLEN]; //Словарь
	printf("Please , input words");
	for (i = 0; ((str[i] = getchar()) != '\n'); i++); //Читаем строку

	str[i] = '\0'; //Добавляем в конец символ завершения строки
	i = 0; // Счетчик по символам введёной строки
	k = 0; // Счетчик найденных слов
	while (str[i] != '\0') { // Цикл до конца введённой строки

		for (; str[i] != '\0' && str[i] == ' '; i++); //Пропуск пробелов
		j = 0; //Счетчик по символам текущего слова
		for (; str[i] != '\0' && str[i] != ' '; i++) //Если не конец введёной строки и не пробел (конец слова)
		{

			word[j] = str[i]; //Копируем символи из строки в текущее слово
			j++; //Следующий символ 
		}
		word[j] = '\0'; //Добавляем символ конца строки текущему слову
		l = 0; // Счетчик для просмотра словаря
		p = 1; // Признак добавления слова
		while (l<k) { // Цикл просмотра словаря
			for (m = 0; dict[l][m] != '\0'; m++); // m - счетчик по символам текущего слова в словаре. Цикл определяет длину
			if (m == j) { //Если длина текущего слова совпадает со словарным - проверяем дальше
				for (m = 0; m<j; m++) // Цикл сравнения текущего и словарного слова
					if (word[m] != dict[l][m]) break; //Если символы не совпадают прерываем цикл
				if (m == j) {
					count[l]++; //Если все символы совпали (не было прерывания цикла) значит такое слово в словаре есть, увеличиваем встречаемость
					p = 0; //Текущее слово добавлять не нужно
				}
			}
			if (p == 0) break;//Если текущее слово встретили в словаре, разрываем цикл  
			l++;
		}
		if (p == 1) { // Если нужно добавить слово
			for (m = 0; m<j; m++) //Копируем слово в словарь используя счетчик найденных слов k
				dict[k][m] = word[m];
			dict[k][m] = '\0'; //Добавляем символ конца строки
			count[k] = 1; //Встречаемость нового слова 1
			k++; // Увеличиваем счетчик найденных слов

		}
	}
	int max_word = count[0], index = 0, l1;
	printf("Words and the frequency of their occurrence in the sentence:\n");
	for (i = 0; i<k; i++) { //Вывод встречаемости найденных слов
		printf("%3d - %s \n", count[i], dict[i]);
	}
	for (i = 1; i<k; i++) {
		//	if (count[i + 1] == k+1)
		//	continue;
		if (count[i] > max_word) {
			max_word = count[i]; index = i;
		}
		else
			continue;
	}
	printf("The most used word :");
	char  *slovo = dict[index];

	printf("%3d -  \n", max_word); foo(slovo);
	return 0;
}


void foo(char* slovo)
{
	for (int i = 0; i != strlen(slovo); i++)
	{
		slovo[i] = slovo[i] - 32;
	}
	puts(slovo);
}