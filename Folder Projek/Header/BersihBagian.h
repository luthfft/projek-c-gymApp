//Deklarasi Global
int x,y;
int i;

void BersihKanan()
{	
	x=130; y=22;
	for (i=1; i<=23; i++)
	{
		gotoxy(x,y); printf("                              ");	
		y++;
	}
}

void BersihKiri()
{
	x=13; y=22;
	gotoxy(13,21); printf("                 ");
	for (i=1; i<=9; i++)
	{
		gotoxy(x,y); printf("                 ");
		y++;
	}
	gotoxy(13,37); printf("                    ");
}

void BersihTengah()
{
	x=38,y=14;
	
	for (i=1; i<=32; i++)
	{
		gotoxy(x,y); printf("                                                                                              ");
		y++;	
	} 
}

void CleanKiriTransaksi()
{
	x=8; y=19;
	for (i=1; i<=23; i++)
	{
		gotoxy(x,y); printf("                               ");
		y++;
	}
	gotoxy(8,44); printf("                               ");
	gotoxy(8,45); printf("                               "); 
}

void BersihTengahTransaksi()
{
	x=41; y=15;
	for (i=1; i<=31; i++)
	{
		gotoxy(x,y); printf("                                                                                                                        ");
		y++;
	}
}

void BersihTengahManager()
{
	int a,b;
	a=36; b=13;
	for (i=1; i<=33; i++)
	{
		gotoxy(a,b); printf("                                                                                                                             ");
		b++;
	}
}

void BersihKiriKasir()
{
	x=8; y=19;
	for (i=1; i<=23; i++)
	{
		gotoxy(x,y); printf("                                ");
		y++;
	}
	gotoxy(8,44); printf("                                 ");
}
