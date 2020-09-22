#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	int d1, m1, y1;
	int d2, m2, y2;
	
	//����� ���
	printf("������� ����\n");
	printf("����: ");
	scanf("%d", &d1);
	printf("�����: ");
	scanf("%d", &m1);
	printf("���: ");
	scanf("%d", &y1);
	printf("������� ������� ����\n");
	printf("����: ");
	scanf("%d", &d2);
	printf("�����: ");
	scanf("%d", &m2);
	printf("���: ");
	scanf("%d", &y2);
	
	int month[12] = { 31,28,31,30,31,30, 31,31,30,31,30,31 };
	int month_leap[12] = { 31,29,31,30,31,30, 31,31,30,31,30,31 };
	
	int day_count = 0;
	
	//���������� ���������� �� ��� ������� �����
	bool leap = false;
	if (y1%4==0 && y1%100!=0){
		leap = true;
	}
	if (y1%4==0 && y1%100==0 && y1%400==0){
		leap = true;
	}
	//���� ������� � ������� ���
	if(y1==y2){
		if (leap){
			day_count -= 366;
		}else{
			day_count -= 365;
		}
	}
	//������� ���-�� ���� �� ����� ������
	if (leap){
		day_count += month_leap[m1-1] - d1;
		printf("�� �������� � ���������� ���\n");
	}else{
		day_count += month[m1-1] - d1;
		printf("�� �������� �� � ���������� ���\n");
	}
	//������� ���-�� ���� �� ����� ������, �� ����� ����
	for(int i = m1; i<12; i++){
		if (leap){
		day_count += month_leap[i];
		}else{
			day_count += month[i];
		}
	}
	//������� ���-�� ���� �� ����� �����
	
	for(int i=y1+1; i<y2; i++){
		leap = false;
		if (i%4==0 && i%100!=0){
			leap = true;
		}
		if (i%4==0 && i%100==0 && i%400==0){
			leap = true;
		}
		if(leap){
			day_count+=366;
		}else{
			day_count+=365;
		}
	}
	
	//������� ���-�� ���� �� ������ ����, �� ������� ����
	leap = false;
	if (y2%4==0 && y2%100!=0){
		leap = true;
	}
	if (y2%4==0 && y2%100==0 && y2%400==0){
		leap = true;
	}
	//������� ���-�� ���� � ������
	day_count += d2;

	//������� ���-�� ���� �� ������ ����, �� ������ ������
	for(int i = 0; i<m2-1; i++){
		if (leap){
		day_count += month_leap[i];
		}else{
			day_count += month[i];
		}
	}
	
	printf("���-�� ���� %d\n", day_count);
	
	//����������� ����� �������
	printf("��� ���� ������� ");
	switch(m1){
		case 1:
			if(d1<=20){
				printf("�������");
			}else{
				printf("�������");
			}
			break;
		case 2:
			if(d1<=18){
				printf("�������");
			}else{
				printf("����");
			}
			break;
		case 3:
			if(d1<=20){
				printf("����");
			}else{
				printf("����");
			}
			break;
		case 4:
			if(d1<=20){
				printf("����");
			}else{
				printf("�����");
			}
			break;
		case 5:
			if(d1<=20){
				printf("�����");
			}else{
				printf("��������");
			}
			break;
		case 6:
			if(d1<=21){
				printf("��������");
			}else{
				printf("���");
			}
			break;
		case 7:
			if(d1<=22){
				printf("���");
			}else{
				printf("���");
			}
			break;
		case 8:
			if(d1<=23){
				printf("���");
			}else{
				printf("����");
			}
			break;
		case 9:
			if(d1<=23){
				printf("����");
			}else{
				printf("����");
			}
			break;
		case 10:
			if(d1<=23){
				printf("����");
			}else{
				printf("��������");
			}
			break;
		case 11:
			if(d1<=22){
				printf("��������");
			}else{
				printf("�������");
			}
			break;
		case 12:
			if(d1<=21){
				printf("�������");
			}else{
				printf("�������");
			}
			break;
	}
	
}
