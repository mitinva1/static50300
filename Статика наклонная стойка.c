#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	system("chcp 1251 > nul");
	int C43 = 710000, IND1, IND2;//модуль юнга алюминий
	float C44, C45, C455, C46, C47, C48, C50, C55, C56=0.0025, C60, C68, C69, C70=0.8, C80;
	float D50, D54, D59, D62, D71, D74, D76=0.01302, D77, D78, h_build;
	char terrain_type_ch, I='I', V='V';
	float timer, x;
	timer = time( 0 );
	if (timer/3600/8760 >=50)
	printf("\nлицензия до 2020года, обратитесь по адресу mitinva1@gmail.com\n");
	else
	{/*ыбор коэффициента, учитывающего изменение 
	ветрового давления по высоте (табл. 6 СНиП 2.01.07-85*)*/
	float nums [12][3] = {{0.75, 0.5, 0.4},//
		  {1.0, 0.65, 0.4},
		  {1.25, 0.85, 0.55},
		  {1.5, 1.1, 0.8},
		  {1.7, 1.3, 1},
		  {1.85, 1.45, 1.15},
		  {2, 1.6, 1.25},
		  {2.25, 1.9, 1.55},
		  {2.45, 2.1, 1.8},
		  {2.65, 2.3, 2},
		  {2.75, 2.5, 2.2},
		  {2.75, 2.75, 2.35},};	
	   //start
    printf("mitinva1@gmail.com\n");
	printf("\nвведите длину наклонной стойки в миллиметрах: ");
	fflush(stdin);
	scanf("%f", &C44);
	C44 = C44/10;
	printf("\nвведите угол наклона стойки к гризонтальной поверхности (град): ");
	fflush(stdin);
	scanf("%f", &C45);
	C46 =cos(C45*M_PI/180);
	//printf("C46 %f", C46);
	C47 = C46*C46;
	//printf("C47 %f", C47);
	D50 = C44/300;
	//printf("D50 %f", D50);
	printf("\nвведите шаг стоек в миллиметрах: ");
	fflush(stdin);
	scanf("%f", &C48);
	C48 = C48/10;
	printf("\nвведите толщину стекла в миллиметрах: ");
	fflush(stdin);
	scanf("%f", &C55);
	C55 = C55/10;
	D54 = C55*C56;
	printf("\nрасчетное значение веса cнегового покрова на 1 м2 горизонтальной поверхности"
	       "\nМинск: 80, Одесса: 120, Москва: 180, Казань: 240, Норильск: 320, Камчатск: 400\n"
		   "введите подходящее значение: ");
    fflush(stdin);
	scanf("%f", &C60);
	if(C45 > 60)
	D62 = 0;
	else if(C45 < 25)
	D62 = 1;
	else
	D62 = (60-C45)/35;
	D59 = C60*D62*0.0001;
	printf("\nнормативное значение ветрового давления"
	       "\nМосква: 23, Питер: 30, Астрахань: 38, Сочи: 48, Пятигорск: 60, Находка:73\n"
           "Введите подходящее значение по региону: ");
    fflush(stdin);
	scanf("%f", &C68);
	printf("\nтип местности");
	printf("\n1. А -открытые побережья морей, озер и водохра нилищ, степи.\n"
	"2. В - городские территории, лесные массивы, равномерно покрытые препятствиями высотой более 10 м.\n"
	"3. С -городские районы с застройкой зданиями высотой более 10 м .\n"
	"ввести цифру : ");
	fflush(stdin);
    scanf("%d", &IND1);
    if (IND1 == 1)
        terrain_type_ch = 'A';
    else if(IND1 == 2)
        terrain_type_ch = 'B';
    else
        terrain_type_ch = 'C';
    
    IND1 = IND1 - 1;
    printf("введите высоту здания в метрах: ");
    fflush(stdin);
    scanf("%f", &h_build);
    
    if (h_build <= 5)
    IND2 = 0;
    else if(h_build > 5 && h_build <= 10)
    IND2 = 1;
    else if(h_build > 10 && h_build <= 20)
    IND2 = 2;
    else if(h_build > 20 && h_build <= 40)
    IND2 = 3;
    else if(h_build > 40 && h_build <= 60)
    IND2 = 4;
    else if(h_build > 60 && h_build <= 80)
    IND2 = 5;
    else if(h_build > 80 && h_build <= 100)
    IND2 = 6;
    else if(h_build > 100 && h_build <= 150)
    IND2 = 7;
    else if(h_build > 150 && h_build <= 200)
    IND2 = 8;
    else if(h_build > 200 && h_build <= 250)
    IND2 = 9;
    else if(h_build > 250 && h_build <= 300)
    IND2 = 10;
    else
    IND2 = 11;
    
    C69 = nums[IND2][IND1];
    //printf("C69 %f", C69); //check table
    D71 = C68*C69*C70/10000;
    //printf("D71 %f", D71);
    D74 = (D71+D59*C47)*0.9+D54*C46;
    //printf("D74 %f", D74);
    D77 = C44*C44*C44*C44*D74*C48;
    //printf("D77 %f", D77);
    D78 = C43*D50;
    //printf("D78 %f", D78);
    C80 = D76*D77/D78;
    
    //print end
    printf("\n\nИтого:\n");
    printf("Тип местности: ");
    if (C68 <= 23)
    printf("%c", I);
    else if(C68 > 23 && C68 <= 30)
        printf("%c%c", I,I);
    else if(C68 > 30 && C68 <= 38)
        printf("%c%c%c", I,I,I);
    else if(C68 > 38 && C68 <= 48)
        printf("%c%c", I,V);
    else if (C68 > 48 && C68 <= 60)
        printf("%c", V);
    else if (C68 > 60 && C68 <= 73)
        printf("%c%c", V,I);
    else
        printf("%c%c%c", V,I,I);
    printf("%c\n", terrain_type_ch);
    printf("длина наклонной стойки %0.0f мм.\n", C44*10);
    printf("Угол наклона стойки %0.2f град.\n", C45);
    printf("шаг стоек %0.0f мм.\n", C48*10);
    printf("толщина стекла %0.0f мм.\n", C55*10);
    printf("высота здания %0.0f м.\n", h_build);
    printf("Необходимый момент инерции стойки Jx =  %0.1f см.4\n", C80);
    printf("Рекомендуемый момент инерции стойки (+40%%) Jx =  %0.0f см.4\n", C80*1.4);
    printf("\n\nmitinva1@gmail.com\n");
}

	
	
	//С46 = cos( C455 );
	//printf("cos_a = %f, C47 = %f\n", C46,C47);
	//printf("%d, %d\n", IND1,IND2);
	system("pause");
	return 0;
}
