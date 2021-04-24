//v1sion
//KEL�ME OYUNU

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<string.h>

void kayit();//Al�nan puan� puantablo.txt dosyas�na yazd�ran fonksiyon.
void oku();//E�er kullan�c� puan tablosunu g�rmek isterse puan tablosunu puantablo.txt dosyas�ndan �ekip ekrana yans�tan fonksiyon.
void soru();//Sorular� �a��ran ve oyun bittikten sonra kullan�c�ya puan�n� g�steren fonskiyon.
void dortharf();//4 harfli kelimelerin tan�mland��� ve harf alma ile kontrol fonksiyonuna g�nderen yer.
void besharf();//5 harfli kelimelerin tan�mland��� ve harf alma ile kontrol fonksiyonuna g�nderen yer.
void altiharf();//6 harfli kelimelerin tan�mland��� ve harf alma ile kontrol fonksiyonuna g�nderen yer.
void yediharf();//7 harfli kelimelerin tan�mland��� ve harf alma ile kontrol fonksiyonuna g�nderen yer.
void sekizharf();//8 harfli kelimelerin tan�mland��� ve harf alma ile kontrol fonksiyonuna g�nderen yer.
void harfal(char kelime[10]);//Harf alman�n ger�ekle�tirildi�i yer.
void kontrol(char kontrol[10], char kelime[10]);//Yaz�lan tahminin do�ru ya da yanl�� oldu�unun kontrol edildi�i fonksiyondur.
void kurallar();//Kurallar�n yaz�ld��� fonksiyondur.
void hazirlayan();//Haz�rlayan�n ismi yazan fonksiyon.

int al = 0, k = 1, puan = 3000, i = 0, s = 0, p = 0, s1, s2, s3, s4, s5, q = 4, c=0;
char kullanici[12];
char alma[] = { '_','_','_','_','_','_','_','_' };
FILE* dosya;
clock_t baslangic;
clock_t son;

int main() 
{
	
setlocale(LC_ALL,"Turkish");//T�rk�e karakterlerin kullan�lmas� i�in gerekli olan locale.h k�t�phanesi fonksiyonudur.

int menuno=0;

bn:
srand(time(NULL));
s1=rand()%5;//4 harfli sorular�n aras�ndan bir tanesinin se�ilmesi i�in 0 ile 5 aras� rastgele bir say� �retir.
s1++;
s2=rand()%5;//5 harfli sorular�n aras�ndan bir tanesinin se�ilmesi i�in 0 ile 5 aras� rastgele bir say� �retir.
s2++;
s3=rand()%5;//6 harfli sorular�n aras�ndan bir tanesinin se�ilmesi i�in 0 ile 5 aras� rastgele bir say� �retir.
s3++;
s4=rand()%5;//7 harfli sorular�n aras�ndan bir tanesinin se�ilmesi i�in 0 ile 5 aras� rastgele bir say� �retir.
s4++;
s5=rand()%5;//8 harfli sorular�n aras�ndan bir tanesinin se�ilmesi i�in 0 ile 5 aras� rastgele bir say� �retir.
s5++;

printf("\n\n\n                                                  ## KEL�ME OYUNU ##                                   \n\n                                                 --- HO� GELD�N�Z ---                                  \n\n                             _________________________________________________________\n                            |             ### L�TFEN SE��M YAPINIZ ###                |\n                            |      Kullan�c� ad�n� girmek isterseniz 1'e bas�n�z.     |\n                            |        Puan tablosunu g�rmek i�in 2'ye bas�n�z.         |\n                            |   Kullan�c� ad� olmadan devam etmek i�in 3'e bas�n�z.   |\n                            |             Kurallar� g�rmek i�in 4'e bas�n�z.          |\n                            |             Yap�mc�y� g�rmek i�in 5'e bas�n�z.          |\n                            |               ��kmak i�in 6'ya bas�n�z.                 |\n                            |_________________________________________________________|\n          ");


scanf("%d",&menuno);


	switch (menuno)
	{
	case 1:
		    system("CLS"); //Bu fonksiyon ekrandaki yaz�lar� siler.
		    printf("L�tfen kullan�c� ad�n�z� giriniz(Tek Kelime Olmal�)= ");
		    scanf("%s",&kullanici);
		    system("CLS");
		    baslangic = clock();
		    soru();
		break; 
	case 2: oku();
		break; 
	case 3: system("CLS");
	        c++;
		    baslangic = clock();
		    soru();
		break; 
	case 4: kurallar();
	    break;
	case 5: hazirlayan();
	    break;
	case 6: goto cik;
	    break;
	default:system("CLS");
		    printf("Yanl�� i�lem girdiniz. Ana men�ye tekrar y�nlendiriliyorsunuz. L�tfen bekleyiniz.");
		    Sleep(2000);
		    system("CLS");
		    goto bn;
	}
cik:

	return 0;
}

void kayit(char kullanici[12], int puann, double zaman)
{

	dosya = fopen("puantablosu.txt", "a");
	fprintf(dosya, "Kullanici adi :%s  Puan: %d  Harcanan Zaman: %f(sn)\n\n", kullanici, puann,zaman);
	fclose(dosya);

}

void oku()
{
	int geri1;
	int i = 0, puan[50];
	int bufferLength = 255;
	double sure[50];
    char buffer[255];
    char path[40]="puantablosu.txt";
    char kuladi[50][30];
    
    dosya = fopen(path, "r");
    
    bas:
	system("CLS");
	if ((dosya = fopen("puantablosu.txt", "r")) != NULL)
	{
    while (fgets(buffer, bufferLength, dosya))
	 { 
        char delim[] = "";

        char* ptr = strtok(buffer, delim);

        while (ptr != NULL)
        {
            printf("%s", ptr);

            ptr = strtok(NULL, delim);
        }
    }
    
	}
	
	printf("\n");
	printf("Program� kapatmak i�in herhangi bir tu�a bas�n�z.");
	getch();
	exit(0);
	
}

void soru()
{
         int geri;

	switch (k)
	{
	case 1:dortharf();
		break;
	case 2:besharf();
		break;
	case 3:altiharf();
		break;
	case 4:yediharf();
		break;
	case 5:sekizharf();
		break;
	case 6:
		   son = clock();
		   double harcanan_zaman = (double)(son - baslangic) / CLOCKS_PER_SEC;
		   harcanan_zaman = harcanan_zaman - 20;
		   printf("%s puan =%d Harcanan Zaman: %f(sn)", kullanici, puan,harcanan_zaman);
		   
		   if(c==1)// E�er kullan�c� Ana Men�m�zde 3'e basarak kullan�c� ad� kullanmadan giri� yapt�ysa puan�n� kaydetmemesi i�in yaz�lm�� �art yap�s�.
		   {
		   	goto git;
		   }
		   
		   else
		   {
		   	kayit(kullanici, puan, harcanan_zaman);//al�nan puan� kay�t etmek i�in kay�t fonksiyonuna y�nlendiriyor.
		   }
		   
		   git:
		   printf("\n\n ==> Puan Tablosunu g�rmek i�in 0'a bas�n�z.\n ==> ��kmak i�in 2'ye bas�n�z.\n");
           scanf("%d", &geri);
        
		   if (geri == 0)
		   { 
		   system("cls");
		   oku();
		   }
		 
		   if(geri==2)
		   {
		 	exit(0);//Kaynaklar� tamamen temizleyerek fonksiyonu normal bir �ekilde sonland�r�r.
		   }
		break;
	}
}

void dortharf()
{

	char kelime[4];
	char dortharfli[5] = { 'h','e','c','e','\0' };

	if (s1 == 1)
	{
		if (al == 0)
		{
			printf("\nSorumuz: Tek seferde s�ylenen ses birli�i?\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')//Kullan�c� 1'e basarsa harf almas�n� e�er basmazsa girilen tahminin kontrol�ne y�nlendiren ko�ul yap�s�.
		{
			al = 1;
			harfal(dortharfli);
		}
		else
		{
			kontrol(dortharfli, kelime);
		}
	}

	else if (s1 == 2)
	{
		char dortharfli[5] = { 'a','o','r','t','\0' };

		if (al == 0)//Bir daha soruyu yazd�rmamas� i�in
		{
			printf("\nSorumuz: Kalbin sol kar�nc���ndan ��kan ve v�cuda k�rm�z� kan da��tan b�y�k atardamar\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(dortharfli);
		}
		else
		{
			kontrol(dortharfli, kelime);
		}
	}

	else if (s1 == 3)
	{
		char dortharfli[5] = { 'a','f','e','t','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Do�an�n sebep oldu�u y�k�m\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(dortharfli);
		}
		else
		{
			kontrol(dortharfli, kelime);
		}

	}

	else if (s1 == 4)
	{
		char dortharfli[5] = { 'a','b','e','s','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Akla ve ger�e�e ayk�r�,gereksiz, l�zumsuz, yersiz, bo�.\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(dortharfli);
		}
		else
		{
			kontrol(dortharfli, kelime);
		}

	}

	else if (s1 == 5)
	{

		char dortharfli[5] = { 'c','i','l','a','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Bir �eyi parlatmak i�in kullan�lan kimyasal bile�ik\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(dortharfli);
		}
		else
		{
			kontrol(dortharfli, kelime);
		}

	}

}

void besharf()
{
	char kelime[5];

	if (s2 == 1)
	{
		char besharfli[6] = { 'k','a','b','u','k','\0' };

		if (al == 0)
		{
			printf("\nSorumuz: Bir �eyin �st�n� kaplayan koruyucu b�l�m\n\n");

		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(besharfli);
		}
		else
		{
			kontrol(besharfli, kelime);
		}

	}

	else if (s2 == 2)
	{
		char besharfli[6] = { 'a','b','o','n','e','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: �nceden �demede bulunarak s�reli yay�nlara al�c� olma i�i\n\n");
		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(besharfli);
		}
		else
		{
			kontrol(besharfli, kelime);
		}

	}

	else if (s2 == 3)
	{
		char besharfli[6] = { 'm','e','s','u','t','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Genelde b�y�klerimizin kulland���, mutlu anlam�na gelen, erkek ismi olarak da kullan�lan kelime\n\n");
		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
			if (kelime[0] == '1')
		{
			al = 1;
			harfal(besharfli);
		}
		else
		{
			kontrol(besharfli, kelime);
		}

	}

	else if (s2 == 4)
	{
		char besharfli[6] = { 's','e','m','i','h','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Eski milli futbolcumuz. H�rvatistan'a son dakika gol� ile bilinir.\n\n");
		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
			if (kelime[0] == '1')
		{
			al = 1;
			harfal(besharfli);
		}
		else
		{
			kontrol(besharfli, kelime);
		}

	}

	else if (s2 == 5)
	{
		char besharfli[6] = { 'e','v','h','a','m','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Kuruntular anlam�na gelen Arap�a k�kenli s�z\n\n");
		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(besharfli);
		}
		else
		{
			kontrol(besharfli, kelime);
		}

	}
}

void altiharf()
{
	char kelime[6];
	if (s3 == 1)
	{
		char altiharfli[7] = { 'b','a','d','a','n','a','\0' };

		if (al == 0)
		{
			printf("\nSorumuz: Duvar boyamada kullan�lan suland�r�lm�� kire� ya da plastik boya\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(altiharfli);
		}
		else
		{
			kontrol(altiharfli, kelime);
		}
	}
	else if (s3 == 2)
	{
		char altiharfli[7] = { 'k','a','b','i','l','e','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Birlikte ya�ayan, konup g��en, bir s�l�leden t�remi� insanlar\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(altiharfli);
		}
		else
		{
			kontrol(altiharfli, kelime);
		}

	}

	else if (s3 == 3)
	{
		char altiharfli[7] = { 't','e','s','c','i','l','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Herhangi bir �eyi resmi olarak kaydetme, belirleme\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(altiharfli);
		}
		else
		{
			kontrol(altiharfli, kelime);
		}

	}
	else if (s3 == 4)
	{
		char altiharfli[7] = { 'p','r','o','m','i','l','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Kandaki alkol miktar�n� g�steren birim\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(altiharfli);
		}
		else
		{
			kontrol(altiharfli, kelime);
		}

	}
	else if (s3 == 5)
	{
		char altiharfli[7] = { 'a','n','g','o','r','a','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Bir kedi, bir ke�i ve bir tav�an t�r�n�n ortak ad�\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(altiharfli);
		}
		else
		{
			kontrol(altiharfli, kelime);
		}

	}
}

void yediharf()
{
	char kelime[7];
	if (s4 == 1)
	{
		char yediharfli[8] = { 'a','d','i','s','y','o','n','\0' };

		if (al == 0)
		{
			printf("\nSorumuz: Lokanta, gazino, otel gibi yerlerde hesap pusulas� ya da hesap\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(yediharfli);
		}
		else
		{
			kontrol(yediharfli, kelime);
		}
	}
	else if (s4 == 2)
	{
		char yediharfli[8] = { 'a','n','a','t','o','m','i','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: �nsan, hayvan ve bitkilerin yap�s�n� ve bu yap�y� olu�turan t�rl� organlar aras�ndaki ili�kileri ara�t�ran, inceleyen bilim\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(yediharfli);
		}
		else
		{
			kontrol(yediharfli, kelime);
		}

	}

	else if (s4 == 3)
	{
		char yediharfli[8] = { 'f','i','l','i','n','t','a','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Bir silah�n ince, uzun boylu, gen� delikanl�lara da yak��t�r�lan ad�\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(yediharfli);
		}
		else
		{
			kontrol(yediharfli, kelime);
		}

	}
	else if (s4 == 4)
	{
		char yediharfli[8] = { 'f','a','m','i','l','y','a','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Biyolojide ortak �zellikleri ayn� olan yak�n cinsler toplulu�u, fasile, aile\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(yediharfli);
		}
		else
		{
			kontrol(yediharfli, kelime);
		}

	}
	else if (s4 == 5)
	{
		char yediharfli[8] = { 'f','r','u','k','t','o','z','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Meyve �ekeri\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(yediharfli);
		}
		else
		{
			kontrol(yediharfli, kelime);
		}

	}
}

void sekizharf()
{
	char kelime[8];
	if (s5 == 1)
	{
		char sekizharfli[9] = { 'm','a','r','t','a','v','a','l','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Uydurma s�z, bo� konu�ma, palavra\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(sekizharfli);
		}
		else
		{
			kontrol(sekizharfli, kelime);
		}
	}
	else if (s5 == 2)
	{
		char sekizharfli[9] = { 'k','u','r','a','m','s','a','l','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Frans�zca k�kenli teorik s�z�n�n T�rk�e kar��l���\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(sekizharfli);
		}
		else
		{
			kontrol(sekizharfli, kelime);
		}

	}

	else if (s5 == 3)
	{
		char sekizharfli[9] = { 'p','a','n','o','r','a','m','a','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Y�ksek bir yerden bak�ld���nda g�z �n�ne serilen geni� g�r�n��\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(sekizharfli);
		}
		else
		{
			kontrol(sekizharfli, kelime);
		}

	}
	else if (s5 == 4)
	{
		char sekizharfli[9] = { 'n','a','f','t','a','l','i','n','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Kuma�, elbise, hal� gibi e�yalar� korumakta kullan�lan antiseptik bir hidrokarbon\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(sekizharfli);
		}
		else
		{
			kontrol(sekizharfli, kelime);
		}

	}
	else if (s5 == 5)
	{
		char sekizharfli[9] = { 'p','a','n','s','u','m','a','n','\0' };
		if (al == 0)
		{
			printf("\nSorumuz: Yara temizli�i ve bak�m�\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak i�in 1 e bas�n�z= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')
		{
			al = 1;
			harfal(sekizharfli);
		}
		else
		{
			kontrol(sekizharfli, kelime);
		}

	}
}

void harfal(char kelime[10])
{
	printf("\n---------------\n");

	int i = 0,
		b,
		f = strlen(kelime);//Karakter dizisinin uzunlu�unu, dizi sonundaki bo� karakter hari� olmak �zere, hesaplar.

	s++;
	if (s == q)//T�m harf alma hakk�n� dolduran kullan�c�ya verilen ��kt�.
	{
		puan -= 100;
		system("CLS");
		printf("Daha fazla harf alamazs�n�z. Di�er soruya ge�iyorsunuz l�tfen bekleyiniz.\n\nDo�ru Cevap= ");
		for (i = 0; i < f; i++)
		{
			printf("%c", kelime[i]);
		}
			
		k++;
		q++;
		printf("\nDi�er soruya ge�mek i�in l�tfen bekleyiniz.");
		Sleep(4000);
		system("CLS");
		s = 0;
		al = 0;
		for (i = 0; i < f; i++)
		{
			alma[i] = '_';
		}
		soru();
	}
	else //As�l harf alman�n d�n��� kod blo�u.
	{
		puan -= 100;
		p++;
		srand(time(NULL));
		b = rand() % q;
	back:
		b = b % q;
		if (alma[b] == kelime[b] && alma[b] != '_')
		{
			b = rand() % q;
			goto back;
		}
		alma[b] = kelime[b];
		for (i = 0; i < q; i++)
		{
			printf("%c", alma[i]);
			printf(" ");
		}
		printf("\n");
		soru();
	}
}

void kontrol(char kontrol[10], char kelime[10])
{
	int i = 0, btest = 0, karaktersayisi = 0;
	
	karaktersayisi = strlen(kontrol);//Girilen cevab�n �nce harf say�s�n�n tutup tutmad��� kontrol ediliyor.
	if (strlen(kontrol) > 8)
	{
		karaktersayisi = 8;
	}
	
	if (strlen(kelime) > karaktersayisi)//String de�erinin uzunlu�unu karakter say�s� ile kar��la�t�r�yor.
	{
		goto yanlis;
	}
	
	if (karaktersayisi > strlen(kelime))//String de�erinin uzunlu�unu karakter say�s� ile kar��la�t�r�yor.
	{
	yanlis:
		system("CLS");
		s = 0;
		al = 0;
		puan = (puan - (karaktersayisi) * 100) + p * 100;
		p = 0;
		for (i = 0; i < 9; i++)
		{
			alma[i] = '_';
		}
		printf("\nYanl�� bildiniz. Di�er soru y�kleniyor l�tfen bekleyiniz...");
		printf("\n\nDo�ru Cevap= ");
		for (i = 0; i < q; i++)
		{
			printf("%c", kontrol[i]);
		}
		
		Sleep(5000);
		q++;
		system("CLS");
		k++;
		soru();
	}
	
	for (i = 0; i < karaktersayisi; i++)
	{
		if (kontrol[i] == kelime[i])
		{
			btest++;
		}
	}
	
	if (btest == karaktersayisi)
	{
		system("CLS");
		s = 0;
		al = 0;
		for (i = 0; i < 10; i++)
		{
			alma[i] = '_';
		}
		k++;
		q++;
		printf("\nDo�ru bildiniz! Di�er soru y�kleniyor l�tfen bekleyiniz...");
		Sleep(4000);
		system("CLS");
		soru();
	}
	
	else {
		system("CLS");
		s = 0;
		al = 0;
		puan = (puan - (karaktersayisi) * 100) + p * 100;
		p = 0;
		for (i = 0; i < 9; i++)
		{
			alma[i] = '_';
		}
		printf("\nYanl�� bildiniz. Di�er soru y�kleniyor l�tfen bekleyiniz... ");
		printf("\n\nDo�ru Cevap= ");
		for (i = 0; i < q; i++)
		{
				printf("%c", kontrol[i]);
		}
		
		Sleep(5000);
		q++;
		system("CLS");
		k++;
		soru();
	}
}

void kurallar()
{
	char geri2[1];
	char buffer[255];
	int bufferLength = 255;
    char path[40]="kurallar.txt";
    FILE* dosya2;
    
    dosya2 = fopen(path, "r");
    
    bas:
	system("CLS");
	if ((dosya = fopen("kurallar.txt", "r")) != NULL)
	{
    while (fgets(buffer, bufferLength, dosya2)) 
	   { 
        char delim[] = "";

        char* ptr = strtok(buffer, delim);

        while (ptr != NULL)
         {
            printf("%s", ptr);

            ptr = strtok(NULL, delim);
         }
      }
    
	}
	
	printf("\n");
	
	printf(" ==> Anasayfaya d�nmek i�in 0'a bas�n�z.\n ==> Kapatmak ��in 2'e bas�n�z.\n");
        scanf("%d", &geri2);
        
		if (geri2[0] == 0)
		 { 
		  system("cls");
		  main();
		 }
		 
		 else if (geri2[0]==2)
		 {
		 	exit(0);//Kaynaklar� tamamen temizleyerek fonksiyonu normal bir �ekilde sonland�r�r.
		 }
		 
		 else if (geri2[0] != 2 && geri2[0] != 0)
		 {
		 	printf("Yanl�� say� girdiniz! L�tfen bekleyiniz...");
		 	Sleep(3000);
		 	system("CLS");
		 	goto bas;
		 }
}

void hazirlayan()
{
	int geri4;
	
	bas:
	system("cls");
	printf("Kodun ve program�n yarat�c�s�: ");
	printf("Metehan S�zen\n\n");
	
	printf("Oynay�p inceledi�iniz i�in �ok te�ekk�r ederim.\n-Metehan S�zen");
	
	printf("\n\n");
	
	printf(" ==> Anasayfaya d�nmek i�in 0'a bas�n�z.\n ==> Kapatmak ��in 2'e bas�n�z.\n");
        scanf("%d", &geri4);
        
		if (geri4 == 0)
		 { 
		  system("cls");
		  main();
		 }
		 
		 else if (geri4==2)
		 {
		 	exit(0);//Kaynaklar� tamamen temizleyerek fonksiyonu normal bir �ekilde sonland�r�r.
		 }
		 
		 else if (geri4 != 2 && geri4 != 0)
		 {
		 	printf("Yanl�� say� girdiniz! L�tfen bekleyiniz...");
		 	Sleep(3000);
		 	system("CLS");
		 	goto bas;
		 }
}


