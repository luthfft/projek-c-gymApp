FILE *TempRiwayat;
void Laporan();
void RiwayatSort();
void LaporanTransaksiBln();
void LaporanTransaksiThn();


void Laporan()
{
	//Deklarasi
	int menu;
	//Algorithm
	fflush(stdin);
	BersihKiri();
	BersihTengahTransaksi();
	gotoxy(15,22); 	printf("	Laporan 	");
	gotoxy(15,25);	printf("[1] Tahunan");
	gotoxy(15,26); 	printf("[2] Bulanan ");
	gotoxy(15,27);	printf("[3] Kembali ");
	gotoxy(24,37); 	printf(" ");
	gotoxy(16,37);	printf("Pilih [ ]");
	gotoxy(23,37);	getnum(&menu,1);
	fflush(stdin);
	switch(menu){
		case 1:
				LaporanTransaksiThn();
				BersihTengahTransaksi();
				BersihKiri();
				break;
		case 2:
				LaporanTransaksiBln();
				BersihTengahTransaksi();
				BersihKiri();
				break;
		case 3:
				BersihKiri();
				BersihTengahTransaksi();
				MenuManager();	
	}
}
	
void RiwayatSort()
{
// Deklarasi //
	int TotalTransaksi;
	TotalTransaksi = 0;
	int j,i;
	char rp[25];

	int count=1, baris=14, kolom=49;
	
	//Algorithm	
	underline(kolom, baris+5, "DAFTAR TRANSAKSI");
	for(x=kolom; x<=148;x++)
	{
		gotoxy(x,20);	printf("%c",205);
		gotoxy(x,22);	printf("%c",205);
	}
    gotoxy(kolom, baris+7);printf("No.   Kode Transaksi       Nama Customer     Paket            Tanggal Transaksi 	  Total Harga");
	TempRiwayat = fopen("dat/sortingriwayat.dat", "rb");
	fread(&Transaksi, sizeof(Transaksi), 1, TempRiwayat);
	while(!feof(ArsTransaksi))
	{
		count++;
		baris++;
		gotoxy(kolom, baris+8);
		printf("%i", Transaksi.ID);
		//menampilkan Nomor
		
		gotoxy(kolom+9, baris+8);
		printf("%s", Transaksi.kdtr);
		//menampilkan kode transaksi
		
		gotoxy(kolom+29, baris+8);
		printf("%s", Transaksi.namaCust);
		
		//menampilkan nama customer
		gotoxy(kolom+45, baris+8);
		printf("%s", Transaksi.jenis);
		//menampilkan nama paket
			
		gotoxy(kolom+65, baris+8);
		printf("%i - %i - %i ", Transaksi.dpel, Transaksi.mpel, Transaksi.ypel);
		//menampilkan tanggal
		
		gotoxy(kolom+89, baris+8);
		rupiah(Transaksi.Totbayar, rp);
		printf("Rp %s", rp);
		//menampilkan total harga
		TotalTransaksi = TotalTransaksi + Transaksi.Totbayar;
		fread(&Transaksi, sizeof(Transaksi), 1, TempRiwayat);
	}
	fclose(TempRiwayat);
	textbox(1,41,43,50,82);
	rupiah(TotalTransaksi, rp);
	gotoxy(51,42);printf("Total Pendapatan :");	printf("Rp. %s", rp);
	gotoxy(51,44);printf("Tekan apa saja untuk kembali...");
	getch();
	Laporan();
}

void LaporanTransaksiBln()
{
	// Deklarasi //
	#define Nmaks 100
	int CekBulan;
	int CekTahun;
	int hari;
		int dd,mm,yy;
	time_t rawtime;
	struct tm *info;
	int baris = 14, kolom = 49;
		
	struct hasil
	{
	       int tahun;
	       int bulan;
	       int hari;
	       int jam;
	       int menit;
	       int detik;
	}waktu;
	time_t t1 = time(0);
	struct tm * now = localtime( & t1 );
	
	waktu.tahun=now->tm_year+1900;
	waktu.bulan=now->tm_mon+1;
	waktu.hari=now->tm_mday;
	waktu.jam=now->tm_hour;
	waktu.menit=now->tm_min;
	waktu.detik=now->tm_sec;

	// Algoritma //
	underline(kolom, baris+1, "LIHAT LAPORAN TRANSAKSI BULANAN");
	gotoxy(kolom, baris+3);printf("Masukkan Bulan : "); getnum(&CekBulan,2);
	gotoxy(kolom+40, baris+3);printf("Masukkan Tahun : "); getnum(&CekTahun,4);
	
	ArsTransaksi = fopen("dat/arsTransaksi.dat", "rb");
	TempRiwayat = fopen("dat/sortingriwayat.dat", "wb");
	
	fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi);
	hari = Transaksi.dpel - waktu.hari;
	while(!feof(ArsTransaksi))
	{
		if((CekBulan == Transaksi.mpel) && (CekTahun == Transaksi.ypel))
		{
			fwrite(&Transaksi, sizeof(Transaksi), 1, TempRiwayat);
		}
		fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi);
	}
	
	fclose(ArsTransaksi);
	fclose(TempRiwayat);
	RiwayatSort();
}

void LaporanTransaksiThn()
{
	// Deklarasi //
	#define Nmaks 100
	int CekBulan;
	int CekTahun;
	int hari;
		int dd,mm,yy;
	time_t rawtime;
	struct tm *info;
	int baris = 14, kolom = 49;
		
	struct hasil
	{
	       int tahun;
	       int bulan;
	       int hari;
	       int jam;
	       int menit;
	       int detik;
	}waktu;
	time_t t1 = time(0);
	struct tm * now = localtime( & t1 );
	
	waktu.tahun=now->tm_year+1900;
	waktu.bulan=now->tm_mon+1;
	waktu.hari=now->tm_mday;
	waktu.jam=now->tm_hour;
	waktu.menit=now->tm_min;
	waktu.detik=now->tm_sec;

	// Algoritma //
	underline(kolom, baris+1, "LIHAT LAPORAN TRANSAKSI TAHUNAN");
	gotoxy(kolom, baris+3);printf("Masukkan Tahun : "); getnum(&CekTahun,4);
	
	ArsTransaksi = fopen("dat/arsTransaksi.dat", "rb");
	TempRiwayat = fopen("dat/sortingriwayat.dat", "wb");
	
	fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi);
	hari = Transaksi.dpel - waktu.hari;
	while(!feof(ArsTransaksi))
	{
		if(CekTahun == Transaksi.ypel)
		{
			fwrite(&Transaksi, sizeof(Transaksi), 1, TempRiwayat);
		}
		fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi);
	}
	fclose(ArsTransaksi);
	fclose(TempRiwayat);
	RiwayatSort();
}
