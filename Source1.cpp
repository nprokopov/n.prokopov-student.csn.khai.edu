#include <stdio.h>
#include <iostream>
#define STRLEN 80
#define WORDLEN 15
#define WORDNUMB 20
void foo(char* slovo);
using namespace std;
int main()
{
	int count[WORDLEN]; //������ ��� �������� ������������� ����
	int i, j, k, l, m, p;
	char str[STRLEN];  //��������� ������
	char word[WORDLEN]; //������� �����
	char dict[WORDNUMB][WORDLEN]; //�������
	printf("Please , input words");
	for (i = 0; ((str[i] = getchar()) != '\n'); i++); //������ ������

	str[i] = '\0'; //��������� � ����� ������ ���������� ������
	i = 0; // ������� �� �������� ������� ������
	k = 0; // ������� ��������� ����
	while (str[i] != '\0') { // ���� �� ����� �������� ������

		for (; str[i] != '\0' && str[i] == ' '; i++); //������� ��������
		j = 0; //������� �� �������� �������� �����
		for (; str[i] != '\0' && str[i] != ' '; i++) //���� �� ����� ������� ������ � �� ������ (����� �����)
		{

			word[j] = str[i]; //�������� ������� �� ������ � ������� �����
			j++; //��������� ������ 
		}
		word[j] = '\0'; //��������� ������ ����� ������ �������� �����
		l = 0; // ������� ��� ��������� �������
		p = 1; // ������� ���������� �����
		while (l<k) { // ���� ��������� �������
			for (m = 0; dict[l][m] != '\0'; m++); // m - ������� �� �������� �������� ����� � �������. ���� ���������� �����
			if (m == j) { //���� ����� �������� ����� ��������� �� ��������� - ��������� ������
				for (m = 0; m<j; m++) // ���� ��������� �������� � ���������� �����
					if (word[m] != dict[l][m]) break; //���� ������� �� ��������� ��������� ����
				if (m == j) {
					count[l]++; //���� ��� ������� ������� (�� ���� ���������� �����) ������ ����� ����� � ������� ����, ����������� �������������
					p = 0; //������� ����� ��������� �� �����
				}
			}
			if (p == 0) break;//���� ������� ����� ��������� � �������, ��������� ����  
			l++;
		}
		if (p == 1) { // ���� ����� �������� �����
			for (m = 0; m<j; m++) //�������� ����� � ������� ��������� ������� ��������� ���� k
				dict[k][m] = word[m];
			dict[k][m] = '\0'; //��������� ������ ����� ������
			count[k] = 1; //������������� ������ ����� 1
			k++; // ����������� ������� ��������� ����

		}
	}
	int max_word = count[0], index = 0, l1;
	printf("Words and the frequency of their occurrence in the sentence:\n");
	for (i = 0; i<k; i++) { //����� ������������� ��������� ����
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