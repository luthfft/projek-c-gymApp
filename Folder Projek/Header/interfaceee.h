#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include <time.h>

void fullscreen();
void gotoxy(int x,int y);
void underline(int x, int y, char text[255]);
void Vline( int min, int max,int y, int a);
void Hline( int min, int max,int y, int a);
void SetColor(unsigned short color);
void PrintFile(char file[], int x, int y);
void Tanggal();
void DesainTransaksi();
void DesainUbahData();

int x,y,i;

void textbox(int last, int a, int b,int c, int d){
	int i;
	for(i=0;i<last;i++)
	{
	Vline(a,b,c,186);
	Vline(a,b,d,186);
	Hline(c,d,a,205);
	Hline(c,d,b,205);
	gotoxy(c,a);printf("%c",201);
	gotoxy(d,a);printf("%c",187);
	gotoxy(c,b);printf("%c",200);
	gotoxy(d,b);printf("%c",188);
	a+=3;
	b+=3;
	}
}

void Vline( int min, int max,int y, int a)
{
	int i;
	for(i=min;i<=max;i++)
	{
		gotoxy(y,i);printf("%c",a);
	}
}

void Hline( int min, int max,int y, int a)
{
	int i;
	for(i=min;i<=max;i++)
	{
		gotoxy(i,y);printf("%c",a);
	}
}
void underline(int x, int y, char text[255]) {
	int i;
	
	gotoxy(x, y);
	printf("%s", text);
	for(i = 0; i < strlen(text); i++) {
		gotoxy(x+i, y+1);
		printf("%c", 196);
	}
}

void gotoxy(int x,int y) 
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X=x;
	dwCursorPosition.Y=y;
	hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void SetColor(unsigned short color)
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void Tanggal1()
{
	for (x=137; x<=156; x++)
	{
		gotoxy(x,7); printf("\xcd");
		gotoxy(x,9); printf("\xcd");
	}
	
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	gotoxy(141,8); printf(" %02d-%02d-%d",  tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void Tanggal()
{
	for (x=137; x<=156; x++)
	{
		gotoxy(x,7); printf("\xcd");
		gotoxy(x,9); printf("\xcd");
	}
	
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	gotoxy(141,8); printf(" %02d-%02d-%d",  tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}


void DesainLogin()
{
	system ("color F9");						
	PrintFile("txt/rds.txt",54,4);								
	PrintFile("txt/GYM.txt",50,15);
	
	/* Desain Menu Login kiri kanan */
	for(y=28;y<=38;y++)
	{	
		gotoxy(61,y);printf("\xba");
		gotoxy(114,y);printf("\xba");
	}
	
	/* Desain Input Login atas bawah */
	for(x=61; x<=114; x++)
	{
		gotoxy(x,28); printf("\xcd");
		gotoxy(x,38); printf("\xcd");
	}
	
	/* Design username*/
	gotoxy(71,31); printf(" USERNAME : ");
	gotoxy(71,30); printf("\xc9"); //  atas kiri
	gotoxy(104,30); printf("\xbb"); //atas kanan
	for (x=72; x<=103; x++)
	{
		gotoxy(x,30); printf("%c",205);
		gotoxy(x,32); printf("%c",205);
	}
	gotoxy(104,32); printf("\xbc"); // bawah kanan
	gotoxy(71,32); printf("\xc8"); // bawah kiri
	for (y=31; y<=31; y++)
	{
		gotoxy(71,y); printf("%c",186);
		gotoxy(104,y); printf("%c",186);
	}

	
	/* Design password*/
	gotoxy(71,35); printf(" PASSWORD : ");
	gotoxy(71,34); printf("\xc9");
	gotoxy(104,34); printf("\xbb");
	for (x=72; x<=103; x++)
	{
		gotoxy(x,34); printf("%c",205);
		gotoxy(x,36); printf("%c",205);
	}
	gotoxy(104,36); printf("\xbc");
	gotoxy(71,36); printf("\xc8");
	for (y=35; y<=35; y++)
	{
		gotoxy(71,y); printf("%c",186);
		gotoxy(104,y); printf("%c",186);
	}
}

void PrintFile(char file[], int x, int y)
{
	FILE *Text;
	char Data[100];
	if((Text=fopen(file, "r")) == NULL)
	{
		system("cls");
	}
	while(fgets(Data, 100, Text))
	{
		gotoxy(x, y);
		printf("%s", Data);
		y++;
	}
	fclose(Text);
}

void DesainAdmin()
{
	system("cls");
	system("color F9");
	textbox(1,9,11,12,30);
	Tanggal1();
	PrintFile("txt/user.txt",17,5);
	
	/* Horizontal */
	for(x=7; x<=161; x++)
	{
		gotoxy(x,2); printf("%c",219);
		gotoxy(x,13); printf("%c",219);
		gotoxy(x,46); printf("%c",219);
	}
	
	/* vertical */
	for(y=3; y<=45; y++)
	{
		gotoxy(7,y); printf("%c",219);
		gotoxy(161,y); printf("%c",219);
	}
	
	/* vertical Menu */
	for(y=13; y<=45; y++)
	{
		gotoxy(35,y); printf("%c",219);
	}
	
	/* Horizontal Menu */
	for(x=12; x<=30; x++)
	{
		gotoxy(x,20); printf("%c",196);
		gotoxy(x,31); printf("%c",196);
	}
	
	/* vertical menu */
	for(y=21; y<=30; y++)
	{
		gotoxy(12,y); printf("%c",179);
		gotoxy(30,y); printf("%c",179);
	}
	PrintFile("txt/DesainPerhalaman.txt",55,5);	
}

void DesainTransaksi()
{
	system("cls");
	system("color F9");
	textbox(1,9,11,12,30);
	PrintFile("txt/user.txt",17,5);

	Tanggal();
	/* Horizontal */
	for(x=7; x<=161; x++)
	{
		gotoxy(x,2); printf("%c",219);
		gotoxy(x,13); printf("%c",219);
		gotoxy(x,46); printf("%c",219);
	}
	
	/* vertical */
	for(y=3; y<=45; y++)
	{
		gotoxy(7,y); printf("%c",219);
		gotoxy(161,y); printf("%c",219);
	}
	/* vertical Menu */
	for(y=13; y<=45; y++)
	{
		gotoxy(40,y); printf("%c",219);
	}
	PrintFile("txt/DesainPerhalaman.txt",55,5);	
}

void DesainManager()
{
	system("color F9");
	textbox(1,9,11,12,30);
	Tanggal();
	PrintFile("txt/user.txt",17,5);

	/* Horizontal */
	for(x=7; x<=161; x++)
	{
		gotoxy(x,2); printf("%c",219);
		gotoxy(x,13); printf("%c",219);
		gotoxy(x,46); printf("%c",219);
	}
	
	/* vertical */
	for(y=3; y<=45; y++)
	{
		gotoxy(7,y); printf("%c",219);
		gotoxy(161,y); printf("%c",219);
	}
	
	/* vertical Menu */
	for(y=13; y<=45; y++)
	{
		gotoxy(35,y); printf("%c",219);
	}
	
	/* Horizontal Menu */
	for(x=12; x<=30; x++)
	{
		gotoxy(x,20); printf("%c",196);
		gotoxy(x,31); printf("%c",196);
	}
	
	/* vertical menu */
	for(y=21; y<=30; y++)
	{
		gotoxy(12,y); printf("%c",179);
		gotoxy(30,y); printf("%c",179);
	}
	PrintFile("txt/DesainPerhalaman.txt",55,5);		
}

void DesainUbahData()
{
	system("color F9");
	gotoxy(14,22); printf(" MASTER KASIR ");
	gotoxy(15,25); printf(" [1] Tambah ");
	gotoxy(15,26); printf(" [2] Lihat ");
	gotoxy(15,27); printf(" [3] Hapus ");
	gotoxy(15,28); printf(" [4] Ubah ");
	gotoxy(15,29); printf(" [5] Kembali");
	
	for (x=56; x<=111; x++)
	{
		gotoxy(x,18); printf("%c",219);
		gotoxy(x,23); printf("%c",205);
		gotoxy(x,38); printf("%c",219);
	}
		for (y=19; y<=37; y++)
	{
		gotoxy(56,y); printf("%c",186);
		gotoxy(111,y); printf("%c",186);
	}	
}
void DesainUbahDataPaket()
{
	gotoxy(14,22); 	printf("	Master Paket	");
	gotoxy(15,25);	printf("[1] Tambah");
	gotoxy(15,26); 	printf("[2] Lihat ");
	gotoxy(15,27);	printf("[3] Ubah ");
	gotoxy(15,28);	printf("[4] Hapus ");
	gotoxy(15,29);	printf("[5] Kembali ");
	gotoxy(24,37); 	printf(" ");
	gotoxy(16,37);	printf("Pilih [ ]");
	system("color F9");
	
	for (x=56; x<=111; x++)
	{
		gotoxy(x,18); printf("%c",219);
		gotoxy(x,23); printf("%c",205);
		gotoxy(x,38); printf("%c",219);
	}
		for (y=19; y<=37; y++)
	{
		gotoxy(56,y); printf("%c",186);
		gotoxy(111,y); printf("%c",186);
	}	
}

void DesainUbahDataAdmin()
{
	system("color F9");
	for (x=56; x<=111; x++)
	{
		gotoxy(x,18); printf("%c",219);
		gotoxy(x,23); printf("%c",205);
		gotoxy(x,38); printf("%c",219);
	}
		for (y=19; y<=37; y++)
	{
		gotoxy(56,y); printf("%c",186);
		gotoxy(111,y); printf("%c",186);
	}	
}

void DesainPaket(){
	system("cls");
	system("color F9");
	Tanggal1();
	
	/* Horizontal */
	for(x=7; x<=161; x++)
	{
		gotoxy(x,2); printf("%c",219);
		gotoxy(x,13); printf("%c",219);
		gotoxy(x,46); printf("%c",219);
	}
	
	/* vertical */
	for(y=3; y<=45; y++)
	{
		gotoxy(7,y); printf("%c",219);
		gotoxy(161,y); printf("%c",219);
	}
	
	/* vertical Menu */
	for(y=13; y<=45; y++)
	{
		gotoxy(35,y); printf("%c",219);
	}
	
	/* Horizontal Menu */
	for(x=12; x<=30; x++)
	{
		gotoxy(x,20); printf("%c",196);
		gotoxy(x,32); printf("%c",196);
	}
	
	/* vertical menu */
	for(y=21; y<=30; y++)
	{
		gotoxy(12,y); printf("%c",179);
		gotoxy(30,y); printf("%c",179);
	}			
}

void KasirMenu()
{
	system("cls");
	system("color F9");
	textbox(1,9,11,12,30);
	Tanggal1();
	PrintFile("txt/user.txt",17,5);

	/* Horizontal */
	for(x=7; x<=161; x++)
	{
		gotoxy(x,2); printf("%c",219);
		gotoxy(x,13); printf("%c",219);
		gotoxy(x,46); printf("%c",219);
	}
	
	/* vertical */
	for(y=3; y<=45; y++)
	{
		gotoxy(7,y); printf("%c",219);
		gotoxy(161,y); printf("%c",219);
	}
	
	/* vertical Menu */
	for(y=13; y<=45; y++)
	{
		gotoxy(35,y); printf("%c",219);
	}
	
	/* Horizontal Menu */
	for(x=12; x<=30; x++)
	{
		gotoxy(x,20); printf("%c",196);
		gotoxy(x,31); printf("%c",196);

	}
	
	/* vertical menu */
	for(y=21; y<=30; y++)
	{
		gotoxy(12,y); printf("%c",179);
		gotoxy(30,y); printf("%c",179);
	}
	PrintFile("txt/DesainPerhalaman.txt",55,5);	
}
void DesainPendapatan()
{
	system("color F9");
	//kiri
	gotoxy(124,43); printf("\xc9");
	gotoxy(124,45); printf("\xc8");
	//kanan
	gotoxy(158,43); printf("\xbb");
	gotoxy(158,45); printf("\xbc");
	
	gotoxy(158,44); printf("%c",186);
	gotoxy(124,44); printf("%c",186);
	for (x=125; x<=157; x++)
	{
		gotoxy(x,43); printf("%c",205);	
		gotoxy(x,45); printf("%c",205);
	}
}
void textBox1(int x, int y, int width, int height) {
	int i, j;
	
	/* first Line */
	gotoxy(x, y);
	printf("%c", 218);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 191);
	
	/* looping for height */
	for(i = 1; i <= height; i++) {
		gotoxy(x, y + i);
		printf("%c", 179);
		
		gotoxy(x + width + 1, y + i);
		printf("%c", 179);
	}
	
	/* last line */
	printf("\n");
	gotoxy(x, y + height);
	printf("%c", 192);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 217);
}
void loading(int x, int y) {
	int i;
	
	gotoxy(x + 12, y-1);
	printf("LOADING");
	textBox1(x, y, 30, 2);
	for(i = 1; i <= 30; i++) {
		gotoxy(x + i, y + 1);
		printf("%c", 177);
		Sleep(30);
		if(i == 8 || i == 28) {
			Sleep(200);
		} else if(i == 20) {
			Sleep(200);
		}	
	}
}
