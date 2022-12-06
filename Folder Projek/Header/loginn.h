/*Prodcedure*/
void FirstLogin();
void MenuAdmin();
void MenuKasir();
void MenuManager();
void MenuLogin();

char nmkasir[15];

void MenuLogin()
{
	/* deklarasi */
	int sukses;
	
	/* Algoritma */
	DesainLogin();
	FirstLogin();
	fflush(stdin);
	ArsKasir = fopen("dat/Kasir.dat", "rb");
	// Username dan Password Kasir
	while(fread(&MKasir, sizeof(MKasir),1 , ArsKasir))
	{
		if((strcmp(MKasir.Username,username)==0) && (strcmp(MKasir.Password,password)==0))
		{	
			if (MKasir.Status==0)
			{
				MessageBox(NULL, "Selamat Datang Kasir"," Welcome",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
				sukses=1;
				break;
			}
			MessageBox(NULL, " Kasir Sudah Tidak Aktif "," Perhatian", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			gotoxy(86,31); printf("                      ");
			gotoxy(86,35); printf("                      ");
			MenuLogin();
		}
	}
		if (sukses==1)
		{
			system("cls");
			strcpy(nmkasir,MKasir.Nama);
			MenuKasir();
		// username dan password manager
		}else if((strcmp(username,"manager")==0) && (strcmp(password,"manager")==0))
				{
					MessageBox(NULL, " Selamat Datang MANAGER ", " Welcome",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		    	   	system("cls");
		       		MenuManager();
		       	// username dan password admin
		    	}else if((strcmp(username,"admin")==0) && (strcmp(password,"admin")==0))
						{
							MessageBox(NULL, " Selamat Datang ADMIN ", " Welcome",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		      	 			system("cls");
		       				MenuAdmin();
		    			}else{
		    				MessageBox(NULL, " Username/Password salah! ", "Perhatian", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
			    			gotoxy(86,31); printf("                      ");
			    			gotoxy(86,35); printf("                      ");
			    			MenuLogin();
						}
}

void FirstLogin()
{
	/* Deklarasi */
	int pilih;
	
	/* Algoritma */
	gotoxy(86,31); getteks(username,22);
	gotoxy(86,35); getpass(password,22);
}

void MenuAdmin()
{
	/* Deklaration */
	int menu;
	
	/* Algoritma */
	DesainAdmin();
	gotoxy(19,10); printf("ADMIN");
	gotoxy(15,22); printf("  MENU ADMIN  ");
	gotoxy(14,25); printf("[1] Paket");
	gotoxy(14,26); printf("[2] Kasir");
	gotoxy(14,27); printf("[3] LogOut");
	kembali :
	gotoxy(17,37); printf(" Pilih [ ] ");
	gotoxy(25,37); getnum(&menu, 1);
	switch(menu)
	{
		case 1:
			Mastermain();
		break;
		case 2:
			MasterKasir();
		break;
		case 3:
			system("cls");
			MenuLogin();	
		break;
		default : goto kembali;
	}
}

void MenuKasir()
{
	/* Deklaration */
	int menu;
	
	/* Algoritma */
	KasirMenu();
	gotoxy(15,10); printf("KASIR.%s",nmkasir);
	gotoxy(15,22); printf("  MENU KASIR  ");
	gotoxy(14,25); printf("[1] Pembayaran");
	gotoxy(14,26); printf("[2] Riwayat ");
	gotoxy(14,27); printf("[3] Log Out");
	kembali :
	gotoxy(17,35); printf(" Pilih [ ] ");
	gotoxy(25,35); getnum(&menu, 1);
	switch(menu)
	{
		case 1:
			BuatTransaksi();
		break;
		case 2:
			LaporanTransaksi();
		break;
		case 3:
			system("cls");
			MenuLogin();
		break;
		default : goto kembali;
	}
}

void MenuManager()
{
	/* Deklaration */
	int menu;
	
	
	/* Algoritma */
	DesainManager();
	gotoxy(18,10); printf("MANAGER");
	gotoxy(15,22); printf(" MENU MANAGER ");
	gotoxy(14,25); printf("[1] Laporan");
	gotoxy(14,26); printf("[2] Paket");
	gotoxy(14,27); printf("[3] Kasir");
	gotoxy(14,28); printf("[4] LogOut");
	kembali :
	gotoxy(16,37); printf(" Pilih [ ] ");
	gotoxy(24,37); getnum(&menu, 1);
	switch(menu)
	{
		case 1:
			Laporan();
		break;
		case 2:
			ReadDataPAKET();
			getch();
			system("cls");
			MenuManager();
		break;
		case 3:
			LihatDataKasir();
			gotoxy(24,37);  getch();
			system("cls");
			MenuManager();
		break;
		case 4:
			system("cls");
			MenuLogin();
		break;
		default : goto kembali;
	}
}
