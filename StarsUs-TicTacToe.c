//////////////////////////////////////////
//////////   GAME TIC TAC TOE   /////////
////////////////////////////////////////

/*
 * NAMA FILE : StarsUs-TicTacToe.c
 *
 * DESKRIPSI : Tic Tac Toe yang dimainkan oleh 2 player
 *
 * NAMA/AUTHOR : ASRI, JEIHAN, NAIA
 *
 * GAME TIC TAC TOE
 *
 * Copyright Politeknik Negeri Bandung | JTK 22, 2022 StarsUs.  All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//================================================ Modul Utama ========================================================//
void tampilMenuAwal();
/*{Prosedur menampilkan tampilan menu awal yang berisi menu 'Main', 'Cara Bermain dan Aturan Bermain', dan Keluar'
	I.S. : Menu awal tidak tampil di layar
	F.S. : Menu awal sudah tampil di layar
}*/

void tampilMain();
/*{Prosedur menampilkan permainan tic tac toe yang telah dibuat
	I.S. : Permainan belum tampil di layar
	F.S. : Permainan sudah tampil di layar
}*/

void buatPlayer();
/*{Prosedur untuk membuat player yang terdiri dari 2 orang dengan menginputkan nama dari kedua player
	I.S. : Kedua player belum ada
	F.S. : Kedua player sudah ada
}*/

void tampilCaraBermain();
/*{Prosedur menampilkan cara bermain beserta aturan bermain pada permainan tic tac toe
	I.S. : Cara bermain dan aturan bermain belum tampil di layar
	F.S. : Cara bermain dan aturan bermain sudah tampil di layar
}*/

void tampilMenuKeluar();
/*{Prosedur menampilkan tampilan menu keluar permainan tic tac toe
	I.S. : Layar menu awal tampil di layar
	F.S. : Layar akan kosong dan keluar dari permainan
}*/

void pilihUkuranPapan();
/*{Prosedur memilih ukuran papan yang terdiri dari papan 3x3, papan 5x5, dan papan 7x7
	I.S. : Papan belum dipilih oleh player
	F.S. : Papan sudah dipilih oleh player
}*/

// int hitungSkor();

void buatPapan3x3();
/*{Prosedur untuk membuat papan 3x3
	I.S. : Papan 3x3 belum terbentuk
	F.S. : Papan 3x3 sudah terbentuk
}*/

char cekPemenang3x3();
// Fungsi mengecek siapa yang pertama berhasil membentuk deret atau menang pada papan 3x3

void bermain3x3();
/*{Prosedur mulai bermain pada papan 3x3
	I.S. : Player belum bisa mulai bermain permainan
	F.S. : Player sudah bisa bermain permainan
}*/

void buatPapan5x5();
/*{Prosedur untuk membuat papan 5x5
	I.S. : Papan 5x5 belum terbentuk
	F.S. : Papan 5x5 sudah terbentuk
}*/

char cekPemenang5x5();
// Fungsi mengecek siapa yang pertama berhasil membentuk deret atau menang papan 3x3

void bermain5x5();
/*{Prosedur mulai bermain pada papan 5x5
	I.S. : Player belum bisa mulai bermain permainan
	F.S. : Player sudah bisa bermain permainan
}*/

void buatPapan7x7();
/*{Prosedur untuk membuat papan 7x7
	I.S. : Papan 7x7 belum terbentuk
	F.S. : Papan 7x7 sudah terbentuk
}*/

char cekPemenang7x7();
// Fungsi mengecek siapa yang pertama berhasil membentuk deret atau menang papan 7x7

void bermain7x7();
/*{Prosedur mulai bermain pada papan 7x7
	I.S. : Player belum bisa mulai bermain permainan
	F.S. : Player sudah bisa bermain permainan
}*/

//================================================ Modul Bermain ========================================================//
void resetPapan();
/*{Prosedur mereset atau membersihkan papan agar menjadi kosong
	I.S. : Papan terisi dengan bidak
	F.S. : Papan kosong tidak ada bidak
}*/

int cekRuangKosong(int jumlahPapan);
// Fungsi mengecek papan dalam keadaan kosong atau tidak

void giliranPemain1();
/*{Prosedur menampilkan giliran pemain1 untuk mulai bermain
	I.S. : Pemain1 belum mulai giliran bermain
	F.S. : Pemain1 mulai giliran bermain
}*/

void giliranPemain2();
/*{Prosedur menampilkan giliran pemain2 untuk mulai bermain
	I.S. : Pemain2 belum mulai giliran bermain
	F.S. : Pemain2 mulai giliran bermain
}*/

void cetakPemenang(char pemenang);
/*{Prosedur menampilkan pemenang dari permainan yang telah dimainkan
	I.S. : Pemenang belum ditampilkan di layar
	F.S. : Pemenang sudah ditampilkan di layar
}*/

//================================================ Variabel Global ========================================================//
const char Pemain1 = 'X'; // pemain1 default bidak X
const char Pemain2 = 'O'; // pemain2 default bidak O
char nama[2][10];		  // inputan nama untuk kedua player dengan maksimal nama 10 karakter
int hasilPapan;
char papan[7][7]; // papan permainan dengan maksimal dimensi 7x7
int skorPemain1 = 0;
int skorPemain2 = 0;

// Modul waktu
int waktuAwal();
int waktuAkhir();

//================================================== Main Body ==========================================================//
int main()
{
	tampilMenuAwal();

	return 0;
}

//================================================= Main Program ========================================================//
void tampilMenuAwal()
{
	system("cls");
	int pilMenu;
	printf("\n\n\n\n");
	printf("\t\t\t\t\t _____________________________ \n");
	printf("\t\t\t\t\t\xb3                             \xb3\n");
	printf("\t\t\t\t\t\xb3   TIC   \xb3    O    \xb3   TOE   \xb3\n");
	printf("\t\t\t\t\t\xb3 ___________________________ \xb3\n");
	printf("\t\t\t\t\t\xb3                             \xb3\n");
	printf("\t\t\t\t\t\xb3    X    \xb3   TAC   \xb3    X    \xb3\n");
	printf("\t\t\t\t\t\xb3 ___________________________ \xb3\n");
	printf("\t\t\t\t\t\xb3                             \xb3\n");
	printf("\t\t\t\t\t\xb3   TIC   \xb3    O    \xb3   TOE   \xb3\n");
	printf("\t\t\t\t\t\xb3_____________________________\xb3\n\n");
	printf("\t\t\t\t\t[1] Main\n");
	printf("\t\t\t\t\t[2] Cara Bermain dan Aturan Bermain\n");
	printf("\t\t\t\t\t[3] Keluar\n\n");
	printf("\t\t\t\t Pilih yang mana? : ");
	scanf("%d", &pilMenu);
	switch (pilMenu)
	{
	case 1: // pemain memilih main dan masuk ke modul tampilMain()
		tampilMain();
		break;
	case 2: // pemain memilih untuk membaca cara bermain dan aturan bermain
		system("cls");
		tampilCaraBermain();
		break;
	case 3: // pemain memilih keluar dari program permainan tic tac toe
		tampilMenuKeluar();
		break;
	default: // jika pemain memasukkan angka selain 1,2, dan 3
		printf("\n\t\t\t\t\t\xaf\xaf\xaf Pilihanmu salah, pilih lagi!");
		getch();
		tampilMenuAwal();
	}
}

void tampilMain()
{
	buatPlayer();
	pilihUkuranPapan();
}

void buatPlayer()
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t _________________________________ \n");
	printf("\t\t\t\t\t\xb3                                 \xb3\n");
	printf("\t\t\t\t\t\xb3    X    \xb3      O      \xb3    X    \xb3\n");
	printf("\t\t\t\t\t\xb3 _______________________________ \xb3\n");
	printf("\t\t\t\t\t\xb3                                 \xb3\n");
	printf("\t\t\t\t\t\xb3         \xb3   Player 1   \xb3        \xb3\n");
	printf("\t\t\t\t\t\xb3    O    \xb3              \xb3   O    \xb3\n");
	printf("\t\t\t\t\t\xb3         \xb3   Player 2   \xb3        \xb3\n");
	printf("\t\t\t\t\t\xb3 _______________________________ \xb3\n");
	printf("\t\t\t\t\t\xb3                                 \xb3\n");
	printf("\t\t\t\t\t\xb3    X    \xb3      O      \xb3    X    \xb3\n");
	printf("\t\t\t\t\t\xb3_________________________________\xb3\n\n");
	printf("\t\t\t\t\t\t Input Nama Player \n");
	printf("\t\t\t\t\t\t Maksimal 10 Huruf \n\n");
	printf("\t\t\t\t\t Player 1 : ");
	scanf("%s", &nama[0][0]); // pemain1 menginputkan nama mulai dari baris 0 dan kolom 0 dengan maksimal 10 karakter
	printf("\t\t\t\t\t Player 2 : ");
	scanf("%s", &nama[1][0]); // pemain2 menginputkan nama mulai dari baris 1 dan kolom 0 dengan maksimal 10 karakter
}

void tampilCaraBermain()
{
	int kembali;
	FILE *the_file = fopen("CaraBermain.txt", "r");
	if (the_file == NULL)
	{
		perror("tidak ada file");
		exit(1);
	}

	char line[100];
	while (fgets(line, sizeof(line), the_file))
	{
		printf("%s", line);
	}
	printf("Ketik angka 1 : ");
	scanf("%d", &kembali);
	switch (kembali)
	{
	case 1:
		tampilMenuAwal();
		break;
	}
}

void tampilMenuKeluar()
{
	system("cls");
	int pilih;
	printf("\n\n\n");
	printf("\t\t\t\t\t\tYakin mau keluar?\n\n");
	printf("\t\t\t\t\t[1] Gak jadi deh, mau main lagi\n");
	printf("\t\t\t\t\t[Ketik Apapun] Yakin\n\n");
	printf("\t\t\t\tMasukkan Pilihanmu: ");
	scanf("%d", &pilih);
	switch (pilih)
	{
	case 1:
		tampilMenuAwal(); // ketika memilih angka 1 akan kembali ke modul tampilMenuAwal() selain itu akan keluar dari program
	}
}

void pilihUkuranPapan()
{
	int ukuran;
	char pemenang = ' '; // kondisi awal pemenang diisi kosong
	system("cls");
	printf("\n\n\n");
	printf("\t\t\t\t\t\t\tPILIH PAPAN	\n\n");
	printf("\t\t\t\t\t _______         _______         _______ \n");
	printf("\t\t\t\t\t\xb3       \xb3       \xb3       \xb3       \xb3       \xb3\n");
	printf("\t\t\t\t\t\xb3 3 x 3	\xb3	\xb3 5 x 5	\xb3	\xb3 7 x 7	\xb3\n");
	printf("\t\t\t\t\t\xb3_______\xb3       \xb3_______\xb3       \xb3_______\xb3\n\n");
	printf("\t\t\t\t\t   [1]\t\t   [2]\t\t   [3]\n\n\n");
	printf("\t\t\t\t Pilih yang mana? ");
	scanf("%d", &ukuran);
	system("cls");
	switch (ukuran)
	{
	case 1: // memilih ukuran papan 3x3
		bermain3x3();
		break;
	case 2: // memilih ukuran papan 5x5
		bermain5x5();
		break;
	case 3: // memilih ukuran papan 7x7
		bermain7x7();
		break;
	default: // jika pemain memasukkan angka selain 1,2, dan 3
		printf("\t\t\t\t\t\xaf\xaf\xaf Pilihanmu salah, pilih lagi!\n\n");
		system("pause"); // menampilkan pesan "Press any key to continue . . ." ke command prompt dan menunggu sampai pengguna menekan tombol apa pun untuk melanjutkan.
		pilihUkuranPapan();
	}
}

void resetPapan()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			papan[i][j] = ' '; // papan dikosongkan
		}
	}
}

int cekRuangKosong(int jumlahPapan)
{
	int ruangKosong = jumlahPapan*jumlahPapan;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (papan[i][j] != ' ')
			{
				ruangKosong--;
			}
		}
	}
	return ruangKosong;
}

int waktuAwal()
{
	clock_t waktu;
	waktu = clock();
	return waktu;
}

int waktuAkhir()
{
	clock_t waktu;
	waktu = clock();
	return waktu;
}

void giliranPemain1()
{
	int x; // variabel untuk menginputkan baris
	int y; // variabel untuk menginputkan kolom
	int waktu;
	double waktuMain;
	do
	{
		printf("\t\t\t\t\tGiliran %s [X]!\n", &nama[0][0]);
		printf("\t\t\t\t\tWaktu kamu cuma 10 detik!\n");
		printf("\t\t\t\t\tMasukkan Baris: ");
		waktu = waktuAwal();
		scanf("%d", &x);
		x--;
		printf("\t\t\t\t\tMasukkan Kolom: ");
		scanf("%d", &y);
		y--;
		waktu = waktuAkhir() - waktu;
		system("cls");
		if (papan[x][y] != ' ')
		{
			printf("\t\t\t\t\tPilihan Tidak Valid!\n");
		}
		else
		{
			waktuMain = ((double)waktu) / CLOCKS_PER_SEC;

			if (waktuMain > 10)
			{
				printf("Waktu telah habis, giliran %s", &nama[1][0]);
			}
			else
			{
				papan[x][y] = Pemain1;
				break;
			}
		}
	} while (papan[x][y] != ' ');
}

void giliranPemain2()
{
	int x; // variabel untuk menginputkan baris
	int y; // variabel untuk menginputkan kolom
	int waktu;
	double waktuMain;
	do
	{
		printf("\t\t\t\t\tGiliran %s [O]!\n", &nama[1][0]);
		printf("\t\t\t\t\tWaktu kamu cuma 10 detik!\n");
		printf("\t\t\t\t\tMasukkan Baris: ");
		waktu = waktuAwal();
		scanf("%d", &x);
		x--;
		printf("\t\t\t\t\tMasukkan Kolom: ");
		scanf("%d", &y);
		y--;
		waktu = waktuAkhir() - waktu;
		system("cls");
		if (papan[x][y] != ' ')
		{
			printf("\t\t\t\t\tPilihan Tidak Valid!\n");
		}
		else
		{
			waktuMain = ((double)waktu) / CLOCKS_PER_SEC;

			if (waktuMain > 10)
			{
				printf("Waktu telah habis, giliran %s", &nama[0][0]);
			}
			else
			{
				papan[x][y] = Pemain2;
				break;
			}
		} 
	} while (papan[x][y] != ' ');
}

	// int hitungSkor(){
	//	printf("%s", &nama[0][0]"	\xb3	%s\n", &nama[1][0]);
	// }

	void buatPapan3x3()
	{
		printf("\n\n\n\n\n\t\t\t\t\t\t   1	 2     3\n");
		printf("\t\t\t\t\t\t___________________\n");
		printf("\t\t\t\t\t     1\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[0][0], papan[0][1], papan[0][2]);
		printf("\n\t\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t\t     2\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[1][0], papan[1][1], papan[1][2]);
		printf("\n\t\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t\t     3\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[2][0], papan[2][1], papan[2][2]);
		printf("\n\t\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3\n\n\n\n\n");
	}

	void buatPapan5x5()
	{
		printf("\n\n\n\n\n\t\t\t\t\t\t   1     2     3     4     5\n");
		printf("\t\t\t\t\t\t_______________________________\n");
		printf("\t\t\t\t\t     1\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[0][0], papan[0][1], papan[0][2], papan[0][3], papan[0][4]);
		printf("\n\t\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t\t     2\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[1][0], papan[1][1], papan[1][2], papan[1][3], papan[1][4]);
		printf("\n\t\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t\t     3\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[2][0], papan[2][1], papan[2][2], papan[2][3], papan[2][4]);
		printf("\n\t\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t\t     4\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[3][0], papan[3][1], papan[3][2], papan[3][3], papan[3][4]);
		printf("\n\t\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t\t     5\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[4][0], papan[4][1], papan[4][2], papan[4][3], papan[4][4]);
		printf("\n\t\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n\n\n\n\n");
	}
	void buatPapan7x7()
	{
		printf("\n\n\n\n\t\t\t\t\t   1     2     3     4     5     6     7\n");
		printf("\t\t\t\t\t___________________________________________\n");
		printf("\t\t\t\t     1\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[0][0], papan[0][1], papan[0][2], papan[0][3], papan[0][4], papan[0][5], papan[0][6]);
		printf("\n\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t     2\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[1][0], papan[1][1], papan[1][2], papan[1][3], papan[1][4], papan[1][5], papan[1][6]);
		printf("\n\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t     3\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[2][0], papan[2][1], papan[2][2], papan[2][3], papan[2][4], papan[2][5], papan[2][6]);
		printf("\n\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t     4\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[3][0], papan[3][1], papan[3][2], papan[3][3], papan[3][4], papan[3][5], papan[3][6]);
		printf("\n\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t     5\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[4][0], papan[4][1], papan[4][2], papan[4][3], papan[4][4], papan[4][5], papan[4][6]);
		printf("\n\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t     6\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[5][0], papan[5][1], papan[5][2], papan[5][3], papan[5][4], papan[5][5], papan[5][6]);
		printf("\n\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
		printf("\t\t\t\t     7\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[6][0], papan[6][1], papan[6][2], papan[6][3], papan[6][4], papan[6][5], papan[6][6]);
		printf("\n\t\t\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n\n\n\n\n");
	}

	char cekPemenang3x3()
	{
		// cek baris membentuk horizontal
		for (int i = 0; i < 3; i++)
		{
			if (papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2] && papan[i][1] == papan[i][2])
			{
				return papan[i][0];
			}
		}
		
		// cek kolom membentuk vertikal
		for (int i = 0; i <= 3; i++)
		{
			if (papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i] && papan[1][i] == papan[2][i])
			{
				return papan[0][i];
			}
		}
		
		// cek diagonal
		if (papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2] && papan[1][1] == papan[2][2])
		{
			return papan[0][0];
		}
		if (papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0] && papan[1][1] == papan[2][0])
		{
			return papan[0][2];
		}

		return ' ';
	}

	char cekPemenang5x5()
	{
		// cek baris membentuk horizontal
		for (int i = 0; i < 5; i++)
		{
			if (papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2] && papan[i][0] == papan[i][3] && papan[i][0] == papan[i][4])
			{
				return papan[i][0];                                                                      
			}
			if (papan[i][1] == papan[i][2] && papan[i][1] == papan[i][3] && papan[i][1] == papan[i][4])
			{
				return papan[i][1];
			}
		}
		// cek kolom membentuk vertikal
		for (int i = 0; i < 5; i++)
		{
			if (papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i] && papan[0][i] == papan[3][i])
			{
				return papan[0][i];
			}
			if (papan[1][i] == papan[2][i] && papan[1][i] == papan[3][i] && papan[1][i] == papan[4][i])
			{
				return papan[1][i];
			}
		}
		// cek diagonal
		if (papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2] && papan[0][0] == papan[3][3])
		{
			return papan[0][0];
		}
		if (papan[1][0] == papan[2][1] && papan[1][0] == papan[3][2] && papan[1][0] == papan[4][3])
		{
			return papan[1][0];
		}
		if (papan[0][1] == papan[1][2] && papan[0][1] == papan[2][3] && papan[0][1] == papan[3][4])
		{
			return papan[0][1];
		}
		if (papan[1][1] == papan[2][2] && papan[1][1] == papan[3][3] && papan[1][1] == papan[4][4])
		{
			return papan[1][1];
		}
		if (papan[1][3] == papan[2][2] && papan[1][3] == papan[3][1] && papan[1][3] == papan[4][0])
		{
			return papan[1][3];
		}
		if (papan[0][3] == papan[2][1] && papan[0][3] == papan[1][2] && papan[0][3] == papan[3][0])
		{
			return papan[0][3];
		}
		if (papan[1][4] == papan[2][3] && papan[1][4] == papan[3][2] && papan[1][4] == papan[4][1])
		{
			return papan[1][4];
		}
		if (papan[0][4] == papan[1][3] && papan[0][4] == papan[2][2] && papan[0][4] == papan[3][1])
		{
			return papan[0][4];
		}
		return ' ';
	}

	char cekPemenang7x7()
	{
		// cek baris membentuk horizontal
		for (int i = 0; i < 7; i++)
		{
			if (papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2] && papan[i][0] == papan[i][3] && papan[i][0] == papan[i][4])
			{
				return papan[i][0];
			}
			if (papan[i][1] == papan[i][2] && papan[i][1] == papan[i][3] && papan[i][1] == papan[i][4] && papan[i][1] == papan[i][5])
			{
				return papan[i][1];
			}
			if (papan[i][2] == papan[i][3] && papan[i][2] == papan[i][4] && papan[i][2] == papan[i][5] && papan[i][2] == papan[i][6])
			{
				return papan[i][1];
			}
		}
		// cek kolom membentuk vertikal
		for (int i = 0; i < 7; i++)
		{
			if (papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i] && papan[0][i] == papan[3][i] && papan[i][0] == papan[i][4])
			{
				return papan[0][i];
			}
			if (papan[1][i] == papan[2][i] && papan[1][i] == papan[3][i] && papan[1][i] == papan[4][i] && papan[i][0] == papan[i][4])
			{
				return papan[1][i];
			}
			if (papan[2][i] == papan[i][3] && papan[i][2] == papan[i][4] && papan[i][2] == papan[i][5] && papan[i][2] == papan[i][6])
			{
				return papan[i][1];
			}
		}
		// cek diagonal
		if (papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2] && papan[0][0] == papan[3][3])
		{
			return papan[0][0];
		}
		if (papan[1][0] == papan[2][1] && papan[1][0] == papan[3][2] && papan[1][0] == papan[4][3])
		{
			return papan[1][0];
		}
		if (papan[0][1] == papan[1][2] && papan[0][1] == papan[2][3] && papan[0][1] == papan[3][4])
		{
			return papan[0][1];
		}
		if (papan[1][1] == papan[2][2] && papan[1][1] == papan[3][3] && papan[1][1] == papan[4][4])
		{
			return papan[1][1];
		}
		if (papan[1][3] == papan[2][2] && papan[1][3] == papan[3][1] && papan[1][3] == papan[4][0])
		{
			return papan[1][3];
		}
		if (papan[0][3] == papan[2][1] && papan[0][3] == papan[1][2] && papan[0][3] == papan[3][0])
		{
			return papan[0][3];
		}
		if (papan[1][4] == papan[2][3] && papan[1][4] == papan[3][2] && papan[1][4] == papan[4][1])
		{
			return papan[1][4];
		}
		if (papan[0][4] == papan[1][3] && papan[0][4] == papan[2][2] && papan[0][4] == papan[3][1])
		{
			return papan[0][4];
		}
		return ' ';
	}

	void bermain3x3()
	{
		char pemenang = ' '; // pemenang diisi kosong
		int pilih;

		resetPapan();

		while (pemenang == ' ' && cekRuangKosong(3) != 0)
		{
			buatPapan3x3();
			giliranPemain1();
			pemenang = cekPemenang3x3();
			if (pemenang != ' ' || cekRuangKosong(3) == 0)
			{
				break;
			}
			buatPapan3x3();
			giliranPemain2();
			pemenang = cekPemenang3x3();
			if (pemenang != ' ' || cekRuangKosong(3) == 0)
			{
				break;
			}
		}

		buatPapan3x3();
		cetakPemenang(pemenang);
		printf("\t\t\t\t\t\t-------------------\n");
		printf("\t\t\t\t\t\t[1] Main lagi\n");
		printf("\t\t\t\t\t\t[2] Keluar\n\n");
		printf("\t\t\t\t\t\tMasukkan Pilihanmu: ");
		scanf("%d", &pilih);
		switch (pilih)
		{
		case 1:
			system("cls");
			bermain3x3();
			break;
		case 2:
			tampilMenuKeluar();
		}
	}

	void bermain5x5()
	{
		char pemenang = ' ';
		int pilih;

		resetPapan();

		while (pemenang == ' ' && cekRuangKosong(5) != 0)
		{
			buatPapan5x5();
			giliranPemain1();
			pemenang = cekPemenang5x5();
			if (pemenang != ' ' || cekRuangKosong(5) == 0)
			{
			pemenang = cekPemenang5x5();
			}
			buatPapan5x5();
			giliranPemain2();
			pemenang = cekPemenang5x5();
			if (pemenang != ' ' || cekRuangKosong(5) == 0)
			{
				break;
			}
		}

		buatPapan5x5();
		cetakPemenang(pemenang);
		printf("\t\t\t\t\t\t--------------------\n");
		printf("\t\t\t\t\t\t[1] Main lagi\n");
		printf("\t\t\t\t\t\t[2] Keluar\n\n");
		printf("\t\t\t\t\t\tMasukkan Pilihanmu: ");
		scanf("%d", &pilih);
		switch (pilih)
		{
		case 1:
			system("cls");
			bermain5x5();
			break;
		case 2:
			tampilMenuKeluar();
		}
	}

	void bermain7x7()
	{
		char pemenang = ' ';
		int pilih;

		resetPapan();

		while (pemenang == ' ' && cekRuangKosong(7) != 0)
		{
			buatPapan7x7();
			giliranPemain1();
			pemenang = cekPemenang7x7();
			if (pemenang != ' ' || cekRuangKosong(7) == 0)
			{
				break;
			}
			buatPapan7x7();
			giliranPemain2();
			pemenang = cekPemenang7x7();
			if (pemenang != ' ' || cekRuangKosong(7) == 0)
			{
				break;
			}
		}

		buatPapan7x7();
		cetakPemenang(pemenang);
		printf("\t\t\t\t\t\t--------------------\n");
		printf("\t\t\t\t\t\t[1] Main lagi\n");
		printf("\t\t\t\t\t\t[2] Keluar\n\n");
		printf("\t\t\t\t\t\tMasukkan Pilihanmu: ");
		scanf("%d", &pilih);
		switch (pilih)
		{
		case 1:
			system("cls");
			bermain7x7();
			break;
		case 2:
			tampilMenuKeluar();
		}
	}

	void cetakPemenang(char pemenang)
	{
		if (pemenang == Pemain1)
		{
			printf("\t\t\t\t\t\t%s menang!\n", &nama[0][0]); // jika pemenang adalah pemain1 akan mencetak bahwa pemain1 yang menang
			skorPemain1 = skorPemain1 + 3;
			printf("\t\t\t\t\t\tSkor %s = %d\n", &nama[0][0], skorPemain1);
			printf("\t\t\t\t\t\tSkor %s = %d\n", &nama[1][0], skorPemain2);
			printf("\t\t\t\t\t\t-------------------\n");
			printf("\t\t\t\t\t\tHighscore = \n");
		}
		else if (pemenang == Pemain2)
		{
			printf("\t\t\t\t\t\t%s menang!\n", &nama[1][0]); // jika pemenang adalah pemain2 akan mencetak bahwa pemain2 yang menang
			skorPemain2 = skorPemain2 + 3;
			printf("\t\t\t\t\t\tSkor %s = %d\n", &nama[0][0], skorPemain1);
			printf("\t\t\t\t\t\tSkor %s = %d\n", &nama[1][0], skorPemain2);
			printf("\t\t\t\t\t\t-------------------\n");
			printf("\t\t\t\t\t\tHighscore = \n");
		}
		else
		{
			printf("\t\t\t\t\t\tIT'S A TIE!\n");
			skorPemain1 = skorPemain1 + 1;
			skorPemain2 = skorPemain2 + 1;
			printf("\t\t\t\t\t\tSkor %s = %d\n", &nama[0][0], skorPemain1);
			printf("\t\t\t\t\t\tSkor %s = %d\n", &nama[1][0], skorPemain2);
			printf("\t\t\t\t\t\t-------------------\n");
			printf("\t\t\t\t\t\tHighscore = \n");
		}
	}
