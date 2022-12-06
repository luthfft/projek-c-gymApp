/* Program Fitnes */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "Header/deklarasii.h"
#include "Header/interfaceee.h"
#include "Header/libb.h"
#include "Header/BersihBagian.h"
#include "Header/crudKasirrr.h"
#include "Header/CRUDPaket.h"
#include "Header/Transaksi.h"
#include "Header/Laporan.h"
#include "Header/loginn.h"


main()
{
	/* Deklaration */
	
	/* Algoritma */
	fullscreen();
	PrintFile("txt/meal.txt",56,2);							
	system("color F9");
	loading(70, 36);
	gotoxy(70,39); printf("Tekan apapun untuk mulai aplikasi!");
	getch();
	system("cls");
	MenuLogin();
}
