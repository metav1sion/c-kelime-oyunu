//v1sion
//KELÝME OYUNU

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<string.h>

void kayit();//Alýnan puaný puantablo.txt dosyasýna yazdýran fonksiyon.
void oku();//Eðer kullanýcý puan tablosunu görmek isterse puan tablosunu puantablo.txt dosyasýndan çekip ekrana yansýtan fonksiyon.
void soru();//Sorularý çaðýran ve oyun bittikten sonra kullanýcýya puanýný gösteren fonskiyon.
void dortharf();//4 harfli kelimelerin tanýmlandýðý ve harf alma ile kontrol fonksiyonuna gönderen yer.
void besharf();//5 harfli kelimelerin tanýmlandýðý ve harf alma ile kontrol fonksiyonuna gönderen yer.
void altiharf();//6 harfli kelimelerin tanýmlandýðý ve harf alma ile kontrol fonksiyonuna gönderen yer.
void yediharf();//7 harfli kelimelerin tanýmlandýðý ve harf alma ile kontrol fonksiyonuna gönderen yer.
void sekizharf();//8 harfli kelimelerin tanýmlandýðý ve harf alma ile kontrol fonksiyonuna gönderen yer.
void harfal(char kelime[10]);//Harf almanýn gerçekleþtirildiði yer.
void kontrol(char kontrol[10], char kelime[10]);//Yazýlan tahminin doðru ya da yanlýþ olduðunun kontrol edildiði fonksiyondur.
void kurallar();//Kurallarýn yazýldýðý fonksiyondur.
void hazirlayan();//Hazýrlayanýn ismi yazan fonksiyon.

int al = 0, k = 1, puan = 3000, i = 0, s = 0, p = 0, s1, s2, s3, s4, s5, q = 4, c=0;
char kullanici[12];
char alma[] = { '_','_','_','_','_','_','_','_' };
FILE* dosya;
clock_t baslangic;
clock_t son;

int main() 
{
	
setlocale(LC_ALL,"Turkish");//Türkçe karakterlerin kullanýlmasý için gerekli olan locale.h kütüphanesi fonksiyonudur.

int menuno=0;

bn:
srand(time(NULL));
s1=rand()%5;//4 harfli sorularýn arasýndan bir tanesinin seçilmesi için 0 ile 5 arasý rastgele bir sayý üretir.
s1++;
s2=rand()%5;//5 harfli sorularýn arasýndan bir tanesinin seçilmesi için 0 ile 5 arasý rastgele bir sayý üretir.
s2++;
s3=rand()%5;//6 harfli sorularýn arasýndan bir tanesinin seçilmesi için 0 ile 5 arasý rastgele bir sayý üretir.
s3++;
s4=rand()%5;//7 harfli sorularýn arasýndan bir tanesinin seçilmesi için 0 ile 5 arasý rastgele bir sayý üretir.
s4++;
s5=rand()%5;//8 harfli sorularýn arasýndan bir tanesinin seçilmesi için 0 ile 5 arasý rastgele bir sayý üretir.
s5++;

printf("\n\n\n                                                  ## KELÝME OYUNU ##                                   \n\n                                                 --- HOÞ GELDÝNÝZ ---                                  \n\n                             _________________________________________________________\n                            |             ### LÜTFEN SEÇÝM YAPINIZ ###                |\n                            |      Kullanýcý adýný girmek isterseniz 1'e basýnýz.     |\n                            |        Puan tablosunu görmek için 2'ye basýnýz.         |\n                            |   Kullanýcý adý olmadan devam etmek için 3'e basýnýz.   |\n                            |             Kurallarý görmek için 4'e basýnýz.          |\n                            |             Yapýmcýyý görmek için 5'e basýnýz.          |\n                            |               Çýkmak için 6'ya basýnýz.                 |\n                            |_________________________________________________________|\n          ");


scanf("%d",&menuno);


	switch (menuno)
	{
	case 1:
		    system("CLS"); //Bu fonksiyon ekrandaki yazýlarý siler.
		    printf("Lütfen kullanýcý adýnýzý giriniz(Tek Kelime Olmalý)= ");
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
		    printf("Yanlýþ iþlem girdiniz. Ana menüye tekrar yönlendiriliyorsunuz. Lütfen bekleyiniz.");
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
	printf("Programý kapatmak için herhangi bir tuþa basýnýz.");
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
		   
		   if(c==1)// Eðer kullanýcý Ana Menümüzde 3'e basarak kullanýcý adý kullanmadan giriþ yaptýysa puanýný kaydetmemesi için yazýlmýþ þart yapýsý.
		   {
		   	goto git;
		   }
		   
		   else
		   {
		   	kayit(kullanici, puan, harcanan_zaman);//alýnan puaný kayýt etmek için kayýt fonksiyonuna yönlendiriyor.
		   }
		   
		   git:
		   printf("\n\n ==> Puan Tablosunu görmek için 0'a basýnýz.\n ==> Çýkmak için 2'ye basýnýz.\n");
           scanf("%d", &geri);
        
		   if (geri == 0)
		   { 
		   system("cls");
		   oku();
		   }
		 
		   if(geri==2)
		   {
		 	exit(0);//Kaynaklarý tamamen temizleyerek fonksiyonu normal bir þekilde sonlandýrýr.
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
			printf("\nSorumuz: Tek seferde söylenen ses birliði?\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
		scanf("%s", &kelime);
		if (kelime[0] == '1')//Kullanýcý 1'e basarsa harf almasýný eðer basmazsa girilen tahminin kontrolüne yönlendiren koþul yapýsý.
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

		if (al == 0)//Bir daha soruyu yazdýrmamasý için
		{
			printf("\nSorumuz: Kalbin sol karýncýðýndan çýkan ve vücuda kýrmýzý kan daðýtan büyük atardamar\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Doðanýn sebep olduðu yýkým\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Akla ve gerçeðe aykýrý,gereksiz, lüzumsuz, yersiz, boþ.\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Bir þeyi parlatmak için kullanýlan kimyasal bileþik\n\n");
		}
		printf("Kelimemiz 4 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Bir þeyin üstünü kaplayan koruyucu bölüm\n\n");

		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Önceden ödemede bulunarak süreli yayýnlara alýcý olma iþi\n\n");
		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Genelde büyüklerimizin kullandýðý, mutlu anlamýna gelen, erkek ismi olarak da kullanýlan kelime\n\n");
		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Eski milli futbolcumuz. Hýrvatistan'a son dakika golü ile bilinir.\n\n");
		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Kuruntular anlamýna gelen Arapça kökenli söz\n\n");
		}
		printf("Kelimemiz 5 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Duvar boyamada kullanýlan sulandýrýlmýþ kireç ya da plastik boya\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Birlikte yaþayan, konup göçen, bir sülâleden türemiþ insanlar\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Herhangi bir þeyi resmi olarak kaydetme, belirleme\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Kandaki alkol miktarýný gösteren birim\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Bir kedi, bir keçi ve bir tavþan türünün ortak adý\n\n");
		}
		printf("Kelimemiz 6 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Lokanta, gazino, otel gibi yerlerde hesap pusulasý ya da hesap\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Ýnsan, hayvan ve bitkilerin yapýsýný ve bu yapýyý oluþturan türlü organlar arasýndaki iliþkileri araþtýran, inceleyen bilim\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Bir silahýn ince, uzun boylu, genç delikanlýlara da yakýþtýrýlan adý\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Biyolojide ortak özellikleri ayný olan yakýn cinsler topluluðu, fasile, aile\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Meyve þekeri\n\n");
		}
		printf("Kelimemiz 7 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Uydurma söz, boþ konuþma, palavra\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Fransýzca kökenli teorik sözünün Türkçe karþýlýðý\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Yüksek bir yerden bakýldýðýnda göz önüne serilen geniþ görünüþ\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Kumaþ, elbise, halý gibi eþyalarý korumakta kullanýlan antiseptik bir hidrokarbon\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
			printf("\nSorumuz: Yara temizliði ve bakýmý\n\n");
		}
		printf("Kelimemiz 8 Harflidir.\nTahmin giriniz veya harf almak için 1 e basýnýz= ");
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
		f = strlen(kelime);//Karakter dizisinin uzunluðunu, dizi sonundaki boþ karakter hariç olmak üzere, hesaplar.

	s++;
	if (s == q)//Tüm harf alma hakkýný dolduran kullanýcýya verilen çýktý.
	{
		puan -= 100;
		system("CLS");
		printf("Daha fazla harf alamazsýnýz. Diðer soruya geçiyorsunuz lütfen bekleyiniz.\n\nDoðru Cevap= ");
		for (i = 0; i < f; i++)
		{
			printf("%c", kelime[i]);
		}
			
		k++;
		q++;
		printf("\nDiðer soruya geçmek için lütfen bekleyiniz.");
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
	else //Asýl harf almanýn dönüðü kod bloðu.
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
	
	karaktersayisi = strlen(kontrol);//Girilen cevabýn önce harf sayýsýnýn tutup tutmadýðý kontrol ediliyor.
	if (strlen(kontrol) > 8)
	{
		karaktersayisi = 8;
	}
	
	if (strlen(kelime) > karaktersayisi)//String deðerinin uzunluðunu karakter sayýsý ile karþýlaþtýrýyor.
	{
		goto yanlis;
	}
	
	if (karaktersayisi > strlen(kelime))//String deðerinin uzunluðunu karakter sayýsý ile karþýlaþtýrýyor.
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
		printf("\nYanlýþ bildiniz. Diðer soru yükleniyor lütfen bekleyiniz...");
		printf("\n\nDoðru Cevap= ");
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
		printf("\nDoðru bildiniz! Diðer soru yükleniyor lütfen bekleyiniz...");
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
		printf("\nYanlýþ bildiniz. Diðer soru yükleniyor lütfen bekleyiniz... ");
		printf("\n\nDoðru Cevap= ");
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
	
	printf(" ==> Anasayfaya dönmek için 0'a basýnýz.\n ==> Kapatmak Ýçin 2'e basýnýz.\n");
        scanf("%d", &geri2);
        
		if (geri2[0] == 0)
		 { 
		  system("cls");
		  main();
		 }
		 
		 else if (geri2[0]==2)
		 {
		 	exit(0);//Kaynaklarý tamamen temizleyerek fonksiyonu normal bir þekilde sonlandýrýr.
		 }
		 
		 else if (geri2[0] != 2 && geri2[0] != 0)
		 {
		 	printf("Yanlýþ sayý girdiniz! Lütfen bekleyiniz...");
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
	printf("Kodun ve programýn yaratýcýsý: ");
	printf("Metehan Sözen\n\n");
	
	printf("Oynayýp incelediðiniz için çok teþekkür ederim.\n-Metehan Sözen");
	
	printf("\n\n");
	
	printf(" ==> Anasayfaya dönmek için 0'a basýnýz.\n ==> Kapatmak Ýçin 2'e basýnýz.\n");
        scanf("%d", &geri4);
        
		if (geri4 == 0)
		 { 
		  system("cls");
		  main();
		 }
		 
		 else if (geri4==2)
		 {
		 	exit(0);//Kaynaklarý tamamen temizleyerek fonksiyonu normal bir þekilde sonlandýrýr.
		 }
		 
		 else if (geri4 != 2 && geri4 != 0)
		 {
		 	printf("Yanlýþ sayý girdiniz! Lütfen bekleyiniz...");
		 	Sleep(3000);
		 	system("CLS");
		 	goto bas;
		 }
}


