#include <stdio.h>
#pragma hdrstop
#include <tchar.h>
#include <conio.h>
#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long long numb, i = 1, CompareMask, MainMask, count;
	printf("Your number:");
	scanf("%llu",&numb);  // max ����� ��� �����: 4 294 967 295
	MainMask = CompareMask =  0x3;

 while (MainMask < numb) {
		count = i;
//���������� ���� do while ��� ������ ������ ����� � �������� �������:
   do {
		if ((CompareMask & MainMask) && (i % 2 == 0)) {
//���� ����� ��� ��������� ���� �� 0 � ����� ����� � ������������������ ������:
		 printf("00");
		 CompareMask = CompareMask << 2;
	   }
//� ���� ����� ����� ��������:
		else if (CompareMask & MainMask) {
		 printf("11");
		 CompareMask = CompareMask << 2;
	   }
//���� ����� ��� ��������� ���� 0 � ����� ����� � ������������������ ������:
		else if ((!(CompareMask & MainMask)) && (i % 2 == 0)) {
		 printf("11");
		 CompareMask = CompareMask << 2;
	   }
		else {
		 printf("00");
		 CompareMask = CompareMask << 2;
	   }
		count--;

	  }   while (count != 0) ;
//��������������� ����� ��������� � �������������� ��������� 0x3:
		CompareMask = CompareMask >> i*2;
		printf (" - %llu\n", MainMask);

		MainMask = MainMask << 2;
		i++;
		if (i % 2 == 0) {
		  MainMask += 0x0;
		}
		else {
		MainMask += 0x3;
		}
	}
	getch();
	return 0;
}

