	// Deklarasi Master Kasir
	
	char *StatusKasir[]={"Aktif","Tidak Aktif"};
	typedef struct {int ID;
					int Status;
					char NIK[20];
					char Telp[20];
					char Nama[50];
					char Asal[50];
					char Username[20];
					char Password[20];
					char TTL[50];
					}DataKasir;
	DataKasir MKasir, MKasir1;
	FILE *ArsKasir;
	FILE *ArsKasir1;

	// Deklarasi Master Paket
	typedef struct{	int idpaket;
				int deskripsi;
				char nama[20];
				char kodepk[50];
				int harga;
	}paket;
	FILE *temp;
	FILE *ArsPaket;
	FILE *ArsPaket1;
	paket PKT,PKT1;
	
	// Deklarasi Transaksi
	FILE *ArsTransaksi;
	FILE *ArsTransaksi1;
	FILE *Temp;
	
	// Deklarasi Login
	char username[20], password[20];
	
	//deklarasi tipe data boolean
	typedef enum 	{false=0,
					true=1
					}booleann;	
boolean found;

	//Deklarasi Transaksi
	typedef struct {int ID,IDkas;
				char kdtr[100];
				char paket[100];
				char jenis[100];
				char namaCust[50];
				char kode[20];
				int status,Totbayar,pembayaran;
				int harga,dpel,mpel,ypel;
				int durasi;
				int bulan,tahun;
				}DaftarTransaksi;
DaftarTransaksi Transaksi;

typedef struct {
	int tgl, bulan, tahun, hour, min, sec;
} DateTime;
DateTime Now;
