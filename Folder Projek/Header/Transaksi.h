void MenuKasir();
void MenuManager();

DaftarTransaksi Transaksi;	// (peubah untuk menampung pembacaan data transaksi) 
FILE *ArsTransaksi;	
FILE *ArsPaket;	// (arsip data transaksi)

void BuatTransaksi(){
    /* DECLARATION: */
	/* all names that are used locally declared here */
    time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int lastid=0,intkode,ces;
	char Kode[25], transaksi[25],rp[25];
	char kodepkt[25];
	int baris = 16, kolom = 49;

    /* ALGORITHM: */
	/* all programs instruction are written here */
	ArsTransaksi = fopen("dat/arsTransaksi.dat", "ab+");
    while(fread(&Transaksi, sizeof(Transaksi), 1, ArsTransaksi)==1)
	{
		lastid=Transaksi.ID;
	}
    lastid++;		//id transaksi otomatis
	sprintf(Kode, "%i", lastid);
	strcpy(transaksi,"TRS");
	strcpy(Kode, strcat(transaksi, Kode));

    gotoxy(kolom,baris);printf("Kode Transaksi\t: "); printf("%s",Kode);Transaksi.ID=lastid;strcpy(Transaksi.kdtr,Kode);fflush(stdin);// rekam ID
	gotoxy(kolom,baris+3);printf ("Nama Customer\t: "); scanf("%s",&Transaksi.namaCust);	
	gotoxy(kolom,baris+6);printf("Kode Paket\t: PK");
	gotoxy(kolom,baris+9);printf ("Nama Paket\t: ");
	gotoxy(kolom,baris+12);printf ("Harga\t\t: Rp ");	
	
	do{
				if((ArsPaket = fopen("dat/arspaket.dat","rb"))==NULL)
				{
					MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
					MenuKasir();
				}
				gotoxy(kolom+19,baris+6);getnum(&intkode,1);
				sprintf(Kode,"%i",intkode);					
				strcpy(kodepkt,"PK");
				strcpy(Kode,strcat(kodepkt,Kode));	
				strcpy(Transaksi.paket, Kode);
				ces=0;
				found = false;				
				while((!found)&&(!feof(ArsPaket)))
				{
					fread(&PKT, sizeof(PKT),1,ArsPaket);
					if (strcmp(PKT.kodepk,Kode)==0)
					{
						found = true;
					}
				}				//found or EOF (ArsTransaksi)
				if(found==true)	//menampilkan Servis yang dipilih
				{					 		
						gotoxy(kolom+17,baris+9); printf ("%s",PKT.nama);
						rupiah(PKT.harga,rp);
						gotoxy(kolom+20,baris+12);printf ("%s",rp);
						strcpy(Transaksi.kode,PKT.kodepk);
						ces++;
				}
				if (ces==0){
					MessageBox(NULL, "Paket belum tersedia","Peringatan",MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
					MenuKasir();
				}
			}while(ces==0);
		fclose(ArsPaket);
		
		//------------------------------------------pembayaran start--------------------------------------------
	/* Declaration */
	int a=0,bayar,sis;
	
	/* Algorithm */
	Transaksi.harga = PKT.harga;
	strcpy(Transaksi.jenis,PKT.nama);
//---------------------------------------Tanggalan Start-----------------------------------------
	/* Declaration */
	int dd,mm,yy;
	time_t rawtime;
	struct tm *info;
		
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
	
	int valid1=0,valid2=0;

	textbox(5,baris+14,baris+16,kolom-4,100);
	gotoxy(kolom,baris+15);printf("Tanggal Transaksi  : %i - %i - %i",waktu.hari,waktu.bulan,waktu.tahun); // tanggal hari ini
	Transaksi.dpel=waktu.hari;
	Transaksi.mpel=waktu.bulan;
	Transaksi.ypel=waktu.tahun;
	Transaksi.durasi=waktu.hari+PKT.deskripsi;
	if(Transaksi.durasi>28){
		Transaksi.durasi=Transaksi.durasi-28;
		Transaksi.bulan=waktu.bulan+1;
	}else{
		Transaksi.bulan=waktu.bulan;
	}
	Transaksi.tahun=waktu.tahun;
	gotoxy(kolom,baris+18);printf("Masa Aktif         : %i - %i - %i",Transaksi.durasi,Transaksi.bulan,Transaksi.tahun);
//------------------------------------------Tanggalan end-----------------------------------------------

	Transaksi.Totbayar = Transaksi.harga;
	rupiah(Transaksi.Totbayar, rp);
	gotoxy(kolom,baris+21);printf("Total Harga     : Rp %s", rp);
	
	Bayarr:
	gotoxy(kolom+16,baris+24);printf("             ");
	gotoxy(kolom,baris+24);printf("Bayar           : Rp  ");
	gotoxy(kolom,baris+27);printf("Sisa Kembalian  : Rp  ");
	gotoxy(kolom+21,baris+24); fflush(stdin); getRp(&bayar, 1, 10, kolom+21, baris+24);
	
	fflush(stdin);
			while(1)
			{
				fflush(stdin);
				if(bayar>=Transaksi.Totbayar){
					break;
				} else {
					MessageBox(NULL, "Uang yang anda masukkan kurang !!" ,"ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);			
					goto Bayarr;
				}	
			}
			Transaksi.pembayaran = Transaksi.Totbayar-bayar;
			if(Transaksi.pembayaran>0)
			{
				rupiah(Transaksi.pembayaran,rp);
				}else{
				Transaksi.pembayaran=Transaksi.pembayaran*(-1);
				rupiah(Transaksi.pembayaran,rp);
				Transaksi.pembayaran=0;	
				}
	gotoxy(kolom+21,baris+27);printf("%s", rp);	
//-------------------------------------------------pembayaran end---------------------------------------------------

//----------------------------------------------------kasir-----------------------------------------------------
	fwrite(&Transaksi, sizeof(Transaksi),1,ArsTransaksi);fflush(stdin);
	fclose(ArsTransaksi);	// tutup arsip
	MessageBox(NULL, "Transaksi berhasil","Berhasil",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	MenuKasir();
}

void LaporanTransaksi()
{
	/* DECLARATION */
	char harga[100];
	int count = 1;
	int baris = 14, kolom = 40;
	char rp[100];
	int IDkas;
	
	/* ALGORITHM */
	strcpy(Transaksi.jenis,PKT.nama);
	underline(kolom, baris+1, "DAFTAR TRANSAKSI");
	for(x=kolom; x<=150;x++)
	{
		gotoxy(x,16);	printf("%c",205);
		gotoxy(x,18);	printf("%c",205);
	}
	gotoxy(kolom, baris+3);printf("No.\tKode Transaksi\tNama Member\tPaket\t\tTanggal Transaksi\tMasa Aktif\tTotal Harga");
	if((ArsTransaksi=fopen("dat/arsTransaksi.dat","rb"))==NULL)
	{
		MessageBox(NULL, "Data masih kosong","Peringatan",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
	}
	
	while(fread(&Transaksi, sizeof(Transaksi),1, ArsTransaksi)==1)
	{
		count++;
		baris++;
		//...........fill baris
		gotoxy(kolom, baris+4);
		if (Transaksi.ID<10);
		{
			printf(" ");
		}
		gotoxy(kolom, baris+4);
		printf("%i", Transaksi.ID);
		//menampilkan Nomor
		
		gotoxy(kolom+8, baris+4);
		printf("%s", Transaksi.kdtr);
		//menampilkan kode transaksi
		
		gotoxy(kolom+24, baris+4);
		printf("%s", Transaksi.namaCust);
		
		//menampilkan nama customer
		gotoxy(kolom+40, baris+4);
		printf("%s", Transaksi.jenis);
		//menampilkan nama paket
			
		gotoxy(kolom+60, baris+4);
		printf("%i-%i-%i ", Transaksi.dpel, Transaksi.mpel, Transaksi.ypel);
		//menampilkan tanggal
		
		gotoxy(kolom+80, baris+4);
		printf("%i-%i-%i",Transaksi.durasi,Transaksi.bulan,Transaksi.tahun);
		//Menampilkan Masa Aktif
	
		gotoxy(kolom+96,baris+4);
		rupiah(Transaksi.Totbayar, rp);
		printf("Rp %s", rp);
		//menampilkan total harga
		
	}
	gotoxy(kolom, 44); printf("Tekan apa saja untuk kembali...");
	getch();
	MenuKasir();
	fclose(ArsTransaksi);
}
