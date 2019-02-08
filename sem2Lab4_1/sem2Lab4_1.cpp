// sem2Lab4_1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct stek
	{
		char value;
		struct stek *next; // ��������� �� ��������� ������� ������ (�����)
	};

	void push(stek* &NEXT, const char VALUE)
	{
		stek *MyStack = new stek; // ��������� ����� ������������ ���������� ���� stek
		MyStack->value = VALUE; // ���������� ��������, ������� ���������� � ����
		MyStack->next = NEXT; // ��������� ����� ������� ����� � ����������
		NEXT = MyStack; // ����� ������� ����� ���������� ��� ��������
	}

	void pop(stek* &NEXT)
	{
		char temp = NEXT->value; // ��������� � ���������� temp �������� � ������� �����
		stek *MyStack = NEXT; // ���������� ��������� �� ������� �����, ����� �����
		// ���������� ���������� ��� ���� ������
		NEXT = NEXT->next; // �������� ���������� �������������� top �������
		delete MyStack; // ����������� ������, ��� ����� ������� �������
	}

	char top(stek* &NEXT)
	{
		char temp = NEXT->value; // ��������� � ���������� temp �������� � ������� �����
		return temp; // ���������� ��������, ������� ���� � �������
	}
	
	void main()
	{
		stek *stack1 = 0;
		stek *stack2 = 0;
		char mas[250];
		int k = 0;
		bool simmetr = true;

		puts("vvod stroki");
		gets_s(mas);

		k = strlen(mas);
		if (k == 0){
			cout << "stroka pusta" << endl;
			system("pause");
			exit(0);
		}

		for (int i = 0; i < k; i++)
		{
			push(stack1,mas[i]);
		}

		if (top(stack1) == '.'){
			pop(stack1);
			k--;
		}

		for (int i = 0; i < k / 2; i++){
			push(stack2, top(stack1));
			pop(stack1);
		}

		if (k % 2 != 0){
			pop(stack1);
		}

		for (int i = 0; i < k / 2; i++)
		{
			if (top(stack1) != top(stack2)){
				simmetr = false;
				break;
			}
			else
			{
				pop(stack1);
				pop(stack2);
			}
		}

		if (simmetr)
		{
			cout << "simmetr TRUE" << endl;
		}
		else
		{
			cout << "simmetr FALSE" << endl;
		}
		
		system("pause");
}
