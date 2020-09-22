#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	int d1, m1, y1;
	int d2, m2, y2;
	
	//ввтод дат
	printf("Введите дату\n");
	printf("День: ");
	scanf("%d", &d1);
	printf("Месяц: ");
	scanf("%d", &m1);
	printf("Год: ");
	scanf("%d", &y1);
	printf("Введите текущую дату\n");
	printf("День: ");
	scanf("%d", &d2);
	printf("Месяц: ");
	scanf("%d", &m2);
	printf("Год: ");
	scanf("%d", &y2);
	
	int month[12] = { 31,28,31,30,31,30, 31,31,30,31,30,31 };
	int month_leap[12] = { 31,29,31,30,31,30, 31,31,30,31,30,31 };
	
	int day_count = 0;
	
	//определяем високосный ли год который ввели
	bool leap = false;
	if (y1%4==0 && y1%100!=0){
		leap = true;
	}
	if (y1%4==0 && y1%100==0 && y1%400==0){
		leap = true;
	}
	//если родился в текущий год
	if(y1==y2){
		if (leap){
			day_count -= 366;
		}else{
			day_count -= 365;
		}
	}
	//находим кол-во дней до конца месяца
	if (leap){
		day_count += month_leap[m1-1] - d1;
		printf("Вы родились в високосный год\n");
	}else{
		day_count += month[m1-1] - d1;
		printf("Вы родились не в високосный год\n");
	}
	//находим кол-во дней от конца месяца, до конца года
	for(int i = m1; i<12; i++){
		if (leap){
		day_count += month_leap[i];
		}else{
			day_count += month[i];
		}
	}
	//находим кол-во дней по целым годам
	
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
	
	//находим кол-во дней от начала года, до текущей даты
	leap = false;
	if (y2%4==0 && y2%100!=0){
		leap = true;
	}
	if (y2%4==0 && y2%100==0 && y2%400==0){
		leap = true;
	}
	//находим кол-во дней в месяце
	day_count += d2;

	//находим кол-во дней от начала года, до начала месяца
	for(int i = 0; i<m2-1; i++){
		if (leap){
		day_count += month_leap[i];
		}else{
			day_count += month[i];
		}
	}
	
	printf("Кол-во дней %d\n", day_count);
	
	//определение знака задиака
	printf("Ваш знак зодиака ");
	switch(m1){
		case 1:
			if(d1<=20){
				printf("Козерог");
			}else{
				printf("Водолей");
			}
			break;
		case 2:
			if(d1<=18){
				printf("Водолей");
			}else{
				printf("Рыбы");
			}
			break;
		case 3:
			if(d1<=20){
				printf("Рыбы");
			}else{
				printf("Овен");
			}
			break;
		case 4:
			if(d1<=20){
				printf("Овен");
			}else{
				printf("Телец");
			}
			break;
		case 5:
			if(d1<=20){
				printf("Телец");
			}else{
				printf("Близнецы");
			}
			break;
		case 6:
			if(d1<=21){
				printf("Близнецы");
			}else{
				printf("Рак");
			}
			break;
		case 7:
			if(d1<=22){
				printf("Рак");
			}else{
				printf("Лев");
			}
			break;
		case 8:
			if(d1<=23){
				printf("Лев");
			}else{
				printf("Дева");
			}
			break;
		case 9:
			if(d1<=23){
				printf("Дева");
			}else{
				printf("Весы");
			}
			break;
		case 10:
			if(d1<=23){
				printf("Весы");
			}else{
				printf("Скорпион");
			}
			break;
		case 11:
			if(d1<=22){
				printf("Скорпион");
			}else{
				printf("Стрелец");
			}
			break;
		case 12:
			if(d1<=21){
				printf("Стрелец");
			}else{
				printf("Козерог");
			}
			break;
	}
	
}
