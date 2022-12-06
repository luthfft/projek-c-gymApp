/* Procedure */
	void CreateData();
	void ReadDataPAKET();
	void ReadData();
	void UpdateData();
	void DeleteData();
	void Mastermain();
	
void Mastermain(){
	//Deklarasi
	int menu;
	//Algorithm
	fflush(stdin);
	BersihKiri();
	gotoxy(14,22); 	printf("	Master Paket	");
	gotoxy(15,25);	printf("[1] Tambah");
	gotoxy(15,26); 	printf("[2] Lihat ");
	gotoxy(15,27);	printf("[3] Ubah ");
	gotoxy(15,28);	printf("[4] Hapus ");
	gotoxy(15,29);	printf("[5] Kembali ");
	kembali:
	gotoxy(23,37); 	printf(" ");
	gotoxy(16,37);	printf("Pilih [ ]");
	gotoxy(23,37);	getnum(&menu,1);
	fflush(stdin);
	switch(menu){
		case 1:
				CreateData();
				break;
		case 2:
				ReadDataPAKET();
				getch();
				BersihTengah();
				Mastermain();
				break;
		case 3:
				UpdateData();
				break;
		case 4:
				DeleteData();
				break;	
		case 5:
				MenuAdmin();
				break;
		default	: goto kembali;	
	}
}
	
void CreateData(){
	//Deskripsi 
	char Kode[5], code[25],namabaru[20];
	int lastid = 0;
	//Algorithm
	ReadData();
	BersihKanan();
	ArsPaket = fopen("dat/arspaket.dat","ab+"); //buka file 
	while(!feof(ArsPaket))
	{
		fflush(stdin);
		fread(&PKT.idpaket,sizeof(PKT),1,ArsPaket);
		lastid=PKT.idpaket;
	}
	lastid++;
	sprintf(Kode,"%i",lastid);
	strcpy(code,"PK");
	strcpy(Kode,strcat(code,Kode));
	gotoxy(135,24);	printf("	Data Paket	");
	gotoxy(133,25);	printf("ID Paket	: "); printf("%s",Kode); PKT.idpaket=lastid; strcpy(PKT.kodepk,Kode);fflush(stdin);
	nama:
	gotoxy(133,26); printf("                            ");	
	gotoxy(133,26);	printf("Nama Paket	: "); gets(namabaru);
		ArsPaket1 = fopen("dat/arspaket.dat","rb");
		fread(&PKT1,sizeof(PKT1),1,ArsPaket1);
		while(!feof(ArsPaket1))
		{
			if(strcmp(PKT1.nama,namabaru)==0)
			{
				MessageBox(NULL, "Nama telah digunakan","ATTENTION",MB_OK);
				goto nama;
			}
			fread(&PKT1,sizeof(PKT1),1,ArsPaket1);
		}
		fclose(ArsPaket1);
	strcpy(PKT.nama,namabaru);
	gotoxy(133,27);	printf("Masa Aktif	: "); printf("  Hari"); 
	gotoxy(146,27); getnum(&PKT.deskripsi,2);
	gotoxy(133,28);	printf("Harga	: Rp.");	getRp(&PKT.harga,1,20,149,28);
	
	fwrite(&PKT,sizeof (PKT),1,ArsPaket);
	
	fclose(ArsPaket);
	MessageBox(NULL, "Data Berhasil Disimpan","ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	BersihKanan();
	BersihTengah();
	getch(); //meminta inputan user tanpa menampilkan di layar
	Mastermain();
}
void ReadDataPAKET(){
	//Deklarasi
	int Baris=26, Kolom=55, i;
	int Next=0;
	char Harga[10];
	int x;
	
	//Algorithm
	ArsPaket = fopen("dat/arspaket.dat","rb");
	if(ArsPaket == NULL)
	{
		gotoxy(50,20);	printf("Belum ada data");
		Mastermain();
	}
	textbox(1,19,21,86,99);
	gotoxy(88,20); printf("DATA PAKET");
	for(x=Kolom; x<=130;x++)
	{
		gotoxy(x,Baris-2);	printf("%c",205);
		gotoxy(x,Baris);	printf("%c",205);
	}
	gotoxy(Kolom,Baris-1);	printf(" ID Paket	Nama Paket		Masa Aktif		Harga");
	fread(&PKT, sizeof(PKT), 1, ArsPaket);
	while(!feof(ArsPaket)){
		Baris++;
		if(Baris%2==0){
			gotoxy(Kolom,Baris);
		}else{
			gotoxy(Kolom,Baris);
		}
		for(i=1;i<=Kolom+37;i++){
			printf(" ");
		}
		gotoxy(Kolom+3,Baris);	printf("%s",PKT.kodepk);
		gotoxy(Kolom+17,Baris);	printf("%s",PKT.nama);
		gotoxy(Kolom+42,Baris);	printf("%d",PKT.deskripsi); gotoxy(Kolom+44,Baris); printf(" Hari");
		gotoxy(Kolom+62,Baris);	rupiah(PKT.harga,Harga);	printf("RP. %s",Harga);
		fflush(stdin);
		fread(&PKT, sizeof(PKT), 1, ArsPaket);
	}
	fclose(ArsPaket);
}
void ReadData(){
	//Deklarasi
	int Baris=16, Kolom=38, i;
	int Next=0;
	char Harga[10];
	int x;
	
	//Algorithm
	ArsPaket = fopen("dat/arspaket.dat","rb");
	if(ArsPaket == NULL)
	{
		gotoxy(50,20);	printf("Belum ada data");
		Mastermain();
	}
	for(x=Kolom; x<=125;x++)
	{
		gotoxy(x,14);	printf("%c",205);
		gotoxy(x,16);	printf("%c",205);
	}
	gotoxy(Kolom,15);	printf(" ID Paket		Nama Paket		Masa Aktif		Harga");
	fread(&PKT, sizeof(PKT), 1, ArsPaket);
	while(!feof(ArsPaket)){
		Baris++;
		if(Baris%2==0){
			gotoxy(Kolom,Baris);
		}else{
			gotoxy(Kolom,Baris);
		}
		for(i=1;i<=Kolom+37;i++){
			printf(" ");
		}
		gotoxy(Kolom+1,Baris);	printf("%s",PKT.kodepk);
		gotoxy(Kolom+18,Baris);	printf("%s",PKT.nama);
		gotoxy(Kolom+42,Baris);	printf("%d",PKT.deskripsi); gotoxy(Kolom+44,Baris); printf(" Hari");
		gotoxy(Kolom+66,Baris);	rupiah(PKT.harga,Harga);	printf("RP. %s",Harga);
		fflush(stdin);
		fread(&PKT, sizeof(PKT), 1, ArsPaket);
	}
	fclose(ArsPaket);
}
void UpdateData(){
	//Deklarasi
	char deskripsibaru[20],namabaru[20],keluar,harga[20],konfirmasi;
	int  id,pilih,pilihulang,RpHarga[20];
	booleann found;
	
	//Algorithm
	fflush(stdin);
	ReadData();
	ArsPaket = fopen("dat/arspaket.dat","rb");
	temp = fopen("dat/arssementara.dat","wb");
	gotoxy(132,22);	printf("Masukkan ID Paket	: PK"); getnum(&id,2);
	found = false;
	fread(&PKT,sizeof(PKT),1,ArsPaket);
	while((!found) && !feof(ArsPaket))
	{
		if(PKT.idpaket == id){
			found = true;
			break;
		}
		else{
			fwrite(&PKT,sizeof(PKT),1,temp);
			fread(&PKT,sizeof(PKT),1,ArsPaket);
		}
	}
	if(found == true){
		BersihTengah();
		BersihKanan();
		DesainUbahDataPaket();
		gotoxy(74,21); printf(" 	UBAH DATA ");
		gotoxy(65,26);	printf("ID Paket		: %s",PKT.kodepk);
		gotoxy(65,28);	printf("Nama Paket		: %s",PKT.nama);
		gotoxy(65,29);	printf("Masa Aktif		: %d",PKT.deskripsi); gotoxy(93,29); printf("Hari");
		gotoxy(65,30);	rupiah(PKT.harga,harga); printf("Harga			: Rp.%s",harga);
		
		//Pilihan Data yang akan diubah
		gotoxy(133,24);	printf("[1] Nama Paket");
		gotoxy(133,25);	printf("[2] Masa Aktif");
		gotoxy(133,26);	printf("[3] Harga");
		gotoxy(133,27); printf("[4] Kembali");
		gotoxy(133,29); printf("Pilihan [ ]");
		gotoxy(142,29); getnum(&pilih,1);
		fflush(stdin);
		switch(pilih)
		{
		case 1:
			gotoxy(133,30);	printf("Nama Baru	: ");
			nama:
			gotoxy(133,31); getteks(namabaru,20); 
			if(strcmp(namabaru, PKT.nama)==0)
			{
				gotoxy(134,33); printf("Data tidak boleh sama");
				getch();
				gotoxy(134,33); printf("                         ");
				gotoxy(133,31); printf("                         ");
				getch();
				goto nama;				
			}
			strcpy(PKT.nama,namabaru);
		break;
		case 2:
			gotoxy(133,30); printf("Masa Akitf	: ") ;printf("  Hari");
			gotoxy(146,30); getnum(&PKT.deskripsi,2);
		break;
		case 3:
			gotoxy(133,30); printf("Harga Baru	: Rp."); 
			getRp(&PKT.harga,1,20,149,30);
		break;
		case 4:
			BersihKanan();
			BersihTengah();
			Mastermain();
			break;
		default :
			MessageBox(NULL, " Input Salah !!" ,"ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);			
			BersihKanan();
			BersihTengah();
			ReadData();
			Mastermain();
		}
		fwrite(&PKT,sizeof(PKT),1,temp);
		fread(&PKT,sizeof(PKT),1,ArsPaket);
			
		while(!feof(ArsPaket))
		{
			fwrite(&PKT,sizeof(PKT),1,temp);
			fread(&PKT,sizeof(PKT),1,ArsPaket);
		}
	}else{
		gotoxy(133,24); printf("Data yang dicari tidak ada");
		konfirm:
		gotoxy(138,26); printf(" Ingin Cari Lagi? ");
		gotoxy(142,27); printf(" [y/t] [ ]"); 
		gotoxy(150,27); getteks(&konfirmasi, 1);
		if (konfirmasi=='y')
		{
			BersihKanan();
			BersihTengah();
			UpdateData();
		}else if (konfirmasi=='t'){
			BersihKanan();
			BersihTengah();
			Mastermain();
			}else{
				goto konfir;
			}
	}
	fclose(ArsPaket);
	fclose(temp);
		
	temp = fopen("dat/arssementara.dat","rb");
	ArsPaket = fopen("dat/arspaket.dat","wb");
		
	fread(&PKT,sizeof(PKT),1,temp);
	while(!feof(temp)){
		fwrite(&PKT,sizeof(PKT),1,ArsPaket);
		fread(&PKT,sizeof(PKT),1,temp);
	}
	fclose(ArsPaket);
	fclose(temp);
	MessageBox(NULL, "Data berhasil diupdate","ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	konfir:
	BersihKanan();
	BersihTengah();
	ReadData();
	gotoxy(136,26); printf("Ingin Ubah Data Lagi?");
	gotoxy(142,27); printf("[y/t] [ ]");
	gotoxy(149,27); getteks(&keluar, 1);
		if (keluar=='y'){
			BersihKanan();
			BersihTengah();
			ReadData();
			UpdateData();
		}else if(keluar=='t'){
			BersihKanan();
			BersihTengah();
			Mastermain();
			}else{
				goto konfir;
			}
	}

void DeleteData(){
	booleann found;
	int id;
	char yes[100];
	
	//ALGORITHM
	ReadData();
	ArsPaket = fopen("dat/arspaket.dat","rb");
	temp = fopen("dat/arssementara.dat","wb");
	gotoxy(133,22);	printf("Masukkan ID Paket	: PK"); 
	getnum(&id,2);
	found = false;

	while(!(found) && !feof(ArsPaket))
	{
		fread (&PKT,sizeof(PKT),1,ArsPaket);
		if(PKT.idpaket == id){
			found = true;
		}else {
			fwrite(&PKT,sizeof(PKT),1,temp);
		}
	}
	
	if(found == true)
	{
		fread(&PKT,sizeof(PKT),1,ArsPaket);
		while(!feof(ArsPaket)){
			fwrite(&PKT,sizeof(PKT),1,temp);
			fread(&PKT,sizeof(PKT),1,ArsPaket);
		}
	}
	else
	{
		MessageBox(NULL, " Data tidak ada" ,"ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		BersihTengah();
		BersihKanan();
		Mastermain();
	}
	fclose(temp);
	fclose(ArsPaket);
	gotoxy(130,26);	printf("Yakin ingin menghapus data ? ");
	gotoxy(142,27);	printf("[y/n] [ ]");
	gotoxy(149,27); getteks(yes,100);
	if(strcmp ("Y",yes) == 0 || strcmp ("y",yes) == 0)
	{
		temp = fopen("dat/arssementara.dat","rb");
		ArsPaket = fopen("dat/arspaket.dat","wb");
		
		fread(&PKT, sizeof(PKT),1,temp);
		while(!feof(temp))
		{
			fwrite(&PKT,sizeof(PKT),1,ArsPaket);
			fread(&PKT,sizeof(PKT),1,temp);
		}
		fclose(ArsPaket);
		fclose(temp);
		BersihKanan();
		BersihTengah();
		MessageBox(NULL,"Data dihapus","ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		Mastermain();
	}else{
		MessageBox(NULL,"Data Tidak terhapus ","ATTENTION",MB_OK| MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		BersihKanan();
		BersihTengah();
		Mastermain();
	}
}
