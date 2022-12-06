#include <windows.h>
/* Global Deklaration */
	
// Prosedure 
	void MasterKasir();
	void TambahDataKasir();
	void LihatDataKasir();
	void HapusDataKasir();
	void UbahDataKasir();
	void MenuAdmin();
	void TampilanUbahDataKasir();

void MasterKasir()
{
	/* Deklaration */
	int menu;
	/* Algoritma */
	BersihKiri();
	gotoxy(15,22); printf(" MASTER KASIR ");
	gotoxy(15,24); printf(" [1] Tambah ");
	gotoxy(15,25); printf(" [2] Lihat ");
	gotoxy(15,26); printf(" [3] Hapus ");
	gotoxy(15,27); printf(" [4] Ubah ");
	gotoxy(15,28); printf(" [5] Kembali");
	kembali:
	gotoxy(24,37); printf(" "); gotoxy(16,37); printf(" Pilih [ ]");
	gotoxy(24,37); getnum(&menu,1);
	fflush(stdin);
	switch(menu)
	{
		case 1:
			TambahDataKasir();
		break;
		case 2:
			LihatDataKasir();
			getch();
			BersihTengah();
			MasterKasir();
		break;
		case 3:
			HapusDataKasir();
		break;		
		case 4:
			UbahDataKasir();
		break;
		case 5:
			MenuAdmin();
		break;
		default : goto kembali ;
	}
}

void TambahDataKasir()
{
	/* Deklaration */
	char keluar;
	char formattedID[5];
	char usr[16];
	/* Algoritma */
	fflush(stdin);
	LihatDataKasir();
	ArsKasir = fopen("dat/Kasir.dat", "ab+");
	while(!feof(ArsKasir))
	{
		fflush(stdin); //Agar semua perintah tereksekusi
		fread(&MKasir.ID,sizeof(MKasir),1,ArsKasir);
	}
	MKasir.ID++;
	gotoxy(133,22);formatID("ID Kasir: KSR", MKasir.ID, formattedID);
	printf("%s", formattedID);
	// Untuk kembali ke menu jika tidak jadi menginputkana nik sama akan mengulangi lagi
	gotoxy(133,24); printf("Nama    : "); getletter(MKasir.Nama, 8);
	gotoxy(133,25); printf("Asal    : "); getteks(MKasir.Asal, 16);
	gotoxy(133,26); printf("Tlp     : "); getteksnum(MKasir.Telp, 13);
	Usr:
	gotoxy(133,27); printf("                            ");	
	gotoxy(133,27); printf("Username: "); gets(usr);
		ArsKasir1 = fopen("dat/Kasir.dat","rb");
		fread(&MKasir1,sizeof(MKasir1),1,ArsKasir1);
		while(!feof(ArsKasir1))
		{
			if(strcmp(MKasir1.Username,usr)==0)
			{
				MessageBox(NULL, "Username telah digunakan","ATTENTION",MB_OK);
				goto Usr;
			}
			fread(&MKasir1,sizeof(MKasir1),1,ArsKasir1);
		}
		fclose(ArsKasir1);
	strcpy(MKasir.Username,usr);
	gotoxy(133,28); printf("Password: "); getpass(MKasir.Password, 10);
	MKasir.Status=0;	
	fwrite(&MKasir, sizeof(MKasir), 1, ArsKasir);
	fclose(ArsKasir);
	LihatDataKasir();
	MessageBox(NULL, "Data Berhasil Disimpan","ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	// Untuk konfirmasi menambahkan data
	konfir:
	BersihKanan();
	BersihTengah();
	LihatDataKasir();
	gotoxy(138,26); printf("Ingin Tambah Lagi?");
	gotoxy(142,27); printf("[y/t] [ ]");
	gotoxy(149,27); getteks(&keluar,1);
	if (keluar=='y'){
		BersihKanan();
		TambahDataKasir();
	}else if(keluar=='t'){
		BersihKanan();
		BersihTengah();
		MasterKasir();
		}
}

void LihatDataKasir()
{
	/* Deklaration */
	int Baris=16, Kolom=38, Next=0;

	/* Algoritma */
	fflush(stdin);
	ArsKasir = fopen("dat/Kasir.dat", "rb");
	//Data Kosong
	if(ArsKasir == NULL)
	{
		gotoxy(70,20); printf("Belum Ada Data");
		getch();
	}
	// Header Data Kasir
	for (x=Kolom; x<=129; x++)
	{ 
		gotoxy(x,14);printf("%c",205);
		gotoxy(x,16);printf("%c",205);	
	}
	gotoxy(Kolom,15);printf(" ID Kasir   Nama \t\t       Asal \t\t      Telephone \t   Status  ");
	// Mencari Data di ArsKasir
	fread(&MKasir, sizeof(MKasir),1 , ArsKasir);
	while (!feof(ArsKasir))
	{	
		Baris++; Next++;
		if(Baris%2==0)
		{
			gotoxy(Kolom,Baris);
		}
		else{
			gotoxy(Kolom,Baris); 
		}
	   	for(i=1;i<=Kolom+54;i++) 
		{
			printf(" ");
		}
		gotoxy(Kolom,Baris);  printf(" KSR%.3d", MKasir.ID);
		gotoxy(Kolom+12,Baris); puts(MKasir.Nama);
		gotoxy(Kolom+33,Baris); puts(MKasir.Asal);
		gotoxy(Kolom+56,Baris); puts(MKasir.Telp);
		gotoxy(Kolom+77,Baris); puts(StatusKasir[MKasir.Status]);
		fflush(stdin);
		fread(&MKasir, sizeof(MKasir),1 , ArsKasir);
	}
	fclose(ArsKasir);
}

void HapusDataKasir()
{
	/* Deklaration */
//	typedef enum {false=0,true=1}boolean;
	int KodeID;
	boolean found;
	char keluar, konfirmasi;
	
	/* Algoritma */	
	LihatDataKasir();
	fflush(stdin);	
//	gotoxy(135,44); printf(" ketik '0' untuk kembali");
	gotoxy(133,22); printf("ID Kasir : KSR"); getnum(&KodeID,3);
	//
	if (KodeID==0)
	{
		MasterKasir();
	}
	//
	ArsKasir = fopen("dat/Kasir.dat","rb"); 
	Temp   = fopen("dat/Temp.dat","wb"); 
	found = false;
	fread(&MKasir,sizeof(MKasir),1,ArsKasir);
	while((!found)&&(!feof(ArsKasir)))
	{	
		if(MKasir.ID == KodeID){
			found = true;
			break;
		} else {
			fwrite(&MKasir, sizeof(MKasir), 1, Temp);
		}
		fread(&MKasir, sizeof(MKasir), 1, ArsKasir);
	}				
	if(found)
	{
		// Menampilkan Data Kasir yang akan dihapus
		gotoxy(134,24); printf("Nama : %s",MKasir.Nama);
		gotoxy(134,25); printf("Asal : %s",MKasir.Asal);
		fread(&MKasir,sizeof(MKasir),1,ArsKasir);
		while(!feof(ArsKasir))
		{
			fwrite(&MKasir,sizeof(MKasir),1,Temp);
			fread(&MKasir,sizeof(MKasir),1,ArsKasir);
		}
	}else{
		// jika ID Kasir yang dicari tidak ditemukan
		cari:
		gotoxy(133,24); printf("ID KSR%.3d tidak ditemukan ", KodeID);
		gotoxy(138,26); printf("Ingin Cari Lagi?");
		gotoxy(142,27); printf("[y/t] [ ]");
		gotoxy(149,27); getteks(&konfirmasi, 1);
		if (konfirmasi=='y')
		{
			BersihKanan();
			HapusDataKasir();
		}else if(konfirmasi=='t'){
			BersihKanan();
			BersihTengah();
			MasterKasir();
			}else{
				goto cari;
			}
	}
	fclose(ArsKasir);
	fclose(Temp);

	//Konfirmasi apakah data tersebut ingin dihapus
	konfir:
	gotoxy(135,27); printf("Yakin data akan dihapus?"); 
	gotoxy(142,28); printf("[y/t] [ ]");
	gotoxy(149,28); getteks(&konfirmasi, 1);
	if (konfirmasi=='y')
	{
		Temp = fopen("dat/Temp.dat","rb");
		ArsKasir = fopen("dat/Kasir.dat","wb"); 
		fread(&MKasir,sizeof(MKasir),1,Temp);
		while(!feof(Temp))
		{
			fwrite(&MKasir,sizeof(MKasir),1,ArsKasir);
			fread(&MKasir,sizeof(MKasir),1,Temp);
		} 
		fclose(ArsKasir);
		fclose(Temp);
		MessageBox(NULL,"Data dihapus","ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		LihatDataKasir();
		BersihKanan();
	}else if (konfirmasi=='t'){
		BersihKanan();
		BersihTengah();
		MasterKasir();		
		}else{
			goto konfir;
		}
	LihatDataKasir();
	// Untuk konfirmasi menambahkan data
		out:
		gotoxy(138,28); printf("Ingin Hapus Lagi?"); 
		gotoxy(142,29); printf("[y/t] [ ]"); 
		gotoxy(149,29); getteks(&keluar, 1);
		if (keluar=='y'){
			BersihKanan();
			BersihTengah();
			LihatDataKasir();
			HapusDataKasir();
		}else if (keluar=='t'){
			BersihKanan();
			BersihTengah();
			MasterKasir();
			}else{
				goto out;
			}
}

void UbahDataKasir()
{
	/* Deklaration */
	typedef enum {false=0,true=1}boolean;
	boolean found;
	int KodeID, menu, pilih;
	char Telp[20], Nama[25], Asal[25], Username[25], Password[25], keluar, konfirmasi;
	
	/* Algoritma */
	fflush(stdin);
	LihatDataKasir();
	//gotoxy(135,44); printf("ketik '0' untuk kembali");
	gotoxy(133,22); printf("ID Kasir : KSR"); getnum(&KodeID,3);
	if (KodeID==0)
	{
		BersihKanan();
		BersihTengah();
		MasterKasir();
	}
	//
	ArsKasir = fopen("dat/Kasir.dat","rb"); 
	Temp   = fopen("dat/Temp.dat","wb"); 
	found = false;
	fread(&MKasir,sizeof(MKasir),1,ArsKasir);
	while((!found)&&(!feof(ArsKasir)))
	{
		if(MKasir.ID == KodeID){
			found = true;
			break;
		} else {
			fwrite(&MKasir, sizeof(MKasir), 1, Temp);
		}
		fread(&MKasir, sizeof(MKasir), 1, ArsKasir);
	}				
	// Data Ditemukan
	if(found)
	{
		// Tampilan Data yang dicari
		awal:
		BersihTengah();
		BersihKanan();
		BersihKiri();
		TampilanUbahDataKasir();
		
		// Data yang akan diubah
		gotoxy(133,23); printf("DATA KASIR");
		gotoxy(133,25); printf("[1] Nama");
		gotoxy(133,26); printf("[2] Asal");
		gotoxy(133,27); printf("[3] Telp");
		gotoxy(133,28); printf("[4] Username");
		gotoxy(133,29); printf("[5] Password");
		gotoxy(133,30); printf("[6] Status");
		gotoxy(133,31); printf("[7] Kembali ke Menu");
		kembali:
		gotoxy(133,33); printf(" Pilihan [ ]"); 
		gotoxy(143,33); getnum(&menu,1);
		fflush(stdin);
		switch(menu)
		{
			case 1:
				gotoxy(133,36); printf("Masukkan Nama Baru : ");
				nama:
				gotoxy(133,37); getletter(Nama,16);
				if (strcmp(Nama, MKasir.Nama)==0)
				{
					gotoxy(134,39); printf("Data Tidak Boleh Sama");
					getch();
					gotoxy(134,39); printf("                         ");
					gotoxy(133,37); printf("                         ");
					goto nama;
				}
				strcpy(MKasir.Nama , Nama);	
			break;
			
			case 2:
				gotoxy(133,36); printf("Masukkan Asal Baru : ");
				asal:
				gotoxy(133,37); getteks(Asal,16);
				if (strcmp(Asal, MKasir.Asal)==0)
				{
					gotoxy(134,39); printf("Data Tidak Boleh Sama");
					getch();
					gotoxy(134,39); printf("                         ");
					gotoxy(133,37); printf("                         ");
					goto asal;
				}	
				strcpy(MKasir.Asal , Asal);
			break;
			case 3:
				gotoxy(133,36); printf("Masukkan Telepon Baru : ");
				telp:
				gotoxy(133,37); getteksnum(Telp,13);
				if (strcmp(Telp, MKasir.Telp)==0)
				{
					gotoxy(134,39); printf("Data Tidak Boleh Sama");
					getch();
					gotoxy(134,39); printf("                         ");
					gotoxy(133,37); printf("                         ");
					goto telp;
				}
				strcpy(MKasir.Telp, Telp);
			break;
			
			case 4:
				gotoxy(133,36); printf("Masukkan Username Baru : "); 
				username:
				gotoxy(133,37); getteks(Username,16);
				if (strcmp(Username, MKasir.Username)==0)
				{
					gotoxy(134,39); printf("Data Tidak Boleh Sama");
					getch();
					gotoxy(134,39); printf("                         ");
					gotoxy(133,37); printf("                         ");
					goto username;
				}
				strcpy(MKasir.Username , Username);
			break;
			case 5:
				gotoxy(133,36); printf("Masukkan Password Baru : ");
				gotoxy(133,37); getpass(Password, 10);
				password:				
				if (strcmp(Password, MKasir.Password)==0)
				{
					gotoxy(134,39); printf("Data Tidak Boleh Sama");
					getch();
					gotoxy(134,39); printf("                         ");
					gotoxy(133,37); printf("                         ");
					goto password;
				}
				strcpy(MKasir.Password , Password);
			break;
			
			case 6:
				gotoxy(133,36); printf("[1] Aktif");
				gotoxy(133,37); printf("[2] Tidak Aktif");
				pilihan:
				gotoxy(141,39); printf("Menu [ ]"); 
				gotoxy(147,39); getnum(&pilih,1);
				
				if(pilih==1)
				{
					MKasir.Status=0;
				}else if (pilih==2){
					MKasir.Status=1;
					}else{
						goto pilihan;
					}
			break;
			
			case 7:
				BersihKanan();
				BersihTengah();
				MasterKasir();
			break;
			default : goto kembali;
		}
		fwrite(&MKasir,sizeof(MKasir),1,Temp);
		fread(&MKasir,sizeof(MKasir),1,ArsKasir);
		while(!feof(ArsKasir))
		{
			fwrite(&MKasir,sizeof(MKasir),1,Temp);
			fread(&MKasir,sizeof(MKasir),1,ArsKasir);
		}
	}else{
		gotoxy(133,24); printf("ID KSR%.3d tidak ditemukan ", KodeID);
		konfir:
		gotoxy(138,26); printf(" Ingin Cari Lagi? ");
		gotoxy(142,27); printf(" [y/t] [ ]"); 
		gotoxy(150,27); getteks(&konfirmasi, 1);
		if (konfirmasi=='y')
		{
			BersihKanan();
			BersihTengah();
			UbahDataKasir();
		}else if (konfirmasi=='t'){
			BersihKanan();
			BersihTengah();
			MasterKasir();
			}else{
				goto konfir;
			}
	}
	fclose(ArsKasir);
	fclose(Temp);
	// mengubah data dari temp ke arskasir
	Temp = fopen("dat/Temp.dat","rb");
	ArsKasir = fopen("dat/Kasir.dat","wb");
	fread(&MKasir,sizeof(MKasir),1,Temp);
	while(!feof(Temp))
	{
		fwrite(&MKasir,sizeof(MKasir),1,ArsKasir);
		fread(&MKasir,sizeof(MKasir),1,Temp);
	} 
	fclose(ArsKasir);
	fclose(Temp);
	LihatDataKasir();
	// Untuk konfirmasi mengubah data lagi
		out:
		BersihTengah();
		BersihKanan();
		LihatDataKasir();
		gotoxy(135,28); printf(" Ingin Ubah Data Lagi?"); 
		gotoxy(140,29); printf(" [y/t] [ ]"); 
		gotoxy(148,29); getteks(&keluar, 1);
		if (keluar=='y'){
			BersihKanan();
			BersihTengah();
			UbahDataKasir();
		}else if (keluar=='t'){
			BersihKanan();
			BersihTengah();
			MasterKasir();
			}else{
				goto out;
			}
}

void TampilanUbahDataKasir()
{
		DesainUbahData();
		gotoxy(74,21); printf(" 	UBAH DATA ");
		gotoxy(65,26); printf(" ID KASIR : KSR%.3d",MKasir.ID);
		gotoxy(65,28); printf(" Nama     : %s",MKasir.Nama);
		gotoxy(65,29); printf(" Asal     : %s",MKasir.Asal);
		gotoxy(65,30); printf(" Tlp      : %s",MKasir.Telp);
		gotoxy(65,31); printf(" Username : %s",MKasir.Username);
		gotoxy(65,32); printf(" Password : %s",MKasir.Password);
		gotoxy(65,33); printf(" Status   : %s",StatusKasir[MKasir.Status]);
}
