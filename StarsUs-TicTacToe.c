//////////////////////////
//   GAME TIC TAC TOE   //
//////////////////////////

//Oleh:
//ASRI HUSNUL ROSADI
//JEIHAN ILHAM K
//NAIA SITI AZ-ZAHRA

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

//Modul Utama
void tampilMenuAwal(); //menu 
void tampilMain(); //
void buatPlayer(); //
void tampilCaraBermain(); //
void tampilMenuKeluar(); //
void pilihUkuranPapan(); //

void buatPapan3x3();
char cekPemenang3x3();
void bermain3x3();

void buatPapan5x5();
char cekPemenang5x5();
void bermain5x5();



void buatPapan7x7();
char cekPemenang7x7();
void bermain5x5();



//Variable global 
const char Pemain1 = 'X';
const char Pemain2 = 'O';


//Modul Bermain
void resetPapan();
int cekRuangKosong();
void giliranPemain1();
void giliranPemain2();
void cetakPemenang(char pemenang);

//Variabel global
char nama[2][10];
int hasilPapan;
char papan[10][10];


int main(){
	tampilMenuAwal();
	
	return 0;
}

// menu awal program
void tampilMenuAwal(){
	system("cls");
	
	int pilMenu;
//	system("color F1");
	printf("\n\n\n\n");
	printf("\t\t _____________________________ \n");
	printf("\t\t\xb3                             \xb3\n");
	printf("\t\t\xb3   TIC   \xb3    O    \xb3   TOE   \xb3\n");
	printf("\t\t\xb3 ___________________________ \xb3\n");
	printf("\t\t\xb3                             \xb3\n");
	printf("\t\t\xb3    X    \xb3   TAC   \xb3    X    \xb3\n");
	printf("\t\t\xb3 ___________________________ \xb3\n");
	printf("\t\t\xb3                             \xb3\n");
	printf("\t\t\xb3   TIC   \xb3    O    \xb3   TOE   \xb3\n");
	printf("\t\t\xb3_____________________________\xb3\n\n");
    printf("\t\t[1] Main\n");
    printf("\t\t[2] Cara Bermain dan Aturan Bermain\n");
    printf("\t\t[3] Keluar\n\n");
	printf("\t Pilih yang mana? : "); scanf("%d",&pilMenu);
	switch(pilMenu){
   		case 1:
   			tampilMain();
   			break;
        case 2:
        	system("cls");
   			tampilCaraBermain();
			
   			break;
		case 3:
   			tampilMenuKeluar();	
   			break;	
   		default:
   			printf("\t\t\t\t\xaf\xaf\xaf Pilihanmu salah, pilih lagi!");
      		getch();
      		tampilMenuAwal();
		}
}

void tampilMain(){
	buatPlayer();
	pilihUkuranPapan();
}

void buatPlayer(){
	system("cls");
	//system("color F1");
   	printf("\n\n\n\n");
	printf("\t\t _________________________________ \n");
	printf("\t\t\xb3                                 \xb3\n");
	printf("\t\t\xb3    X    \xb3      O      \xb3    X    \xb3\n");
	printf("\t\t\xb3 _______________________________ \xb3\n");
	printf("\t\t\xb3                                 \xb3\n");
	printf("\t\t\xb3         \xb3   Player 1   \xb3        \xb3\n");
	printf("\t\t\xb3    O    \xb3              \xb3   O    \xb3\n");	
	printf("\t\t\xb3         \xb3   Player 2   \xb3        \xb3\n");
	printf("\t\t\xb3 _______________________________ \xb3\n");
	printf("\t\t\xb3                                 \xb3\n");
	printf("\t\t\xb3    X    \xb3      O      \xb3    X    \xb3\n");
	printf("\t\t\xb3_________________________________\xb3\n\n");
	printf("\t\t\t Input Nama Player \n\n");
    printf("\t\t Player 1 : ");
    scanf("%s",&nama[0][0]);
    printf("\t\t Player 2 : ");
    scanf("%s",&nama[1][0]);
}

void tampilCaraBermain(){
	int kembali;
	FILE*the_file = fopen("CaraBermain.txt", "r");
	if(the_file == NULL){
		perror("tidak ada file");
		exit(1);
	}
 
	char line[100];
	while(fgets(line, sizeof(line), the_file)){
		printf("%s", line);
	}
	printf("Ketik angka 1 : "); 
	scanf("%d",&kembali);
    switch(kembali){
   		case 1:
   			tampilMenuAwal();
   			break;
	}
}

void tampilMenuKeluar(){
	system("cls");
	int pilih;
	printf("\n\n\n");
	printf("\t\t\tYakin mau keluar?\n\n");
    printf("\t\t[1] Gak jadi deh, mau main lagi\n");
    printf("\t\t[2] Yakin\n\n");
    printf("\tMasukkan Pilihanmu: "); 
	scanf("%d",&pilih);
    switch(pilih){
   		case 1:tampilMenuAwal();
   		}
}

void pilihUkuranPapan(){
	int ukuran;
	char pemenang = ' ';
	system("cls");
   	printf("\n\n\n");
   	printf("				PILIH PAPAN					\n\n");
	printf("\t\t _______         _______         _______ \n");
	printf("\t\t\xb3       \xb3       \xb3       \xb3       \xb3       \xb3\n");
	printf("\t\t\xb3 3 x 3	\xb3	\xb3 5 x 5	\xb3	\xb3 7 x 7	\xb3\n");
	printf("\t\t\xb3_______\xb3       \xb3_______\xb3       \xb3_______\xb3\n\n");
	printf("\t\t   [1]\t\t   [2]\t\t   [3]\n\n");
    printf("\t Pilih yang mana? "); 
	scanf("%d",&ukuran);
	system("cls");
	switch(ukuran){
		case 1:
			hasilPapan=5;
			bermain3x3();
			break;
		case 2:
			hasilPapan=7;
			bermain5x5();
			break;
		case 3:
			hasilPapan=9;
			buatPapan7x7();
			break;
		default:
			printf("\t\t\t\t\xaf\xaf\xaf Pilihanmu salah, pilih lagi!");
      		system("pause");
      		pilihUkuranPapan();
	}
}

void resetPapan(){
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			papan[i][j] = ' ';
		}	
	}	
}

int cekRuangKosong(){
	int ruangKosong = 49;
	
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			if (papan[i][j] != ' '){
				ruangKosong--;
			}
		}
	}
	return ruangKosong;
}


void giliranPemain1(){
	int x;
	int y;
	
	do{
		printf("Giliran Pemain 1 !\n");
		printf("Masukkan Baris #(1-3): ");
	scanf("%d", &x);
	x--;
	printf("Masukkan Kolom #(1-3): ");
	scanf("%d", &y);
	y--;
	//system("cls");
	if(papan[x][y] != ' '){
		printf("Pilihan Tidak Valid!\n");
	}
	else {
		papan[x][y] = Pemain1;
		break;
		}	
	} while (papan[x][y] != ' ');
}

void giliranPemain2(){
	int x;
	int y;
	
	do{
		printf("Giliran Pemain 2 !\n");
		printf("Masukkan Baris #(1-3): ");
	scanf("%d", &x);
	x--;
	printf("Masukkan Kolom #(1-3): ");
	scanf("%d", &y);
	y--;
	system("cls");
	if(papan[x][y] != ' '){
		printf("Pilihan Tidak Valid!\n");
	}
	else {
		papan[x][y] = Pemain2;
		break;
		}	
	} while (papan[x][y] != ' ');
}

int StartTime()
{
	clock_t startInput;
	startInput = clock();
	return startInput;
}

int EndTime()
{
	clock_t endInput;
	endInput = clock();
	return endInput;
}

void buatPapan3x3(){
	printf("\n\n\n\n\n\t\t\t   1	 2     3\n");
	printf("\t\t\t___________________\n");
	printf("\t\t     1\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[0][0], papan[0][1], papan[0][2]);
	printf("\n\t\t\t\xb3_____\xb3_____\xb3_____\xb3\n");
	printf("\t\t     2\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[1][0], papan[1][1], papan[1][2]);
	printf("\n\t\t\t\xb3_____\xb3_____\xb3_____\xb3\n");
	printf("\t\t     3\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[2][0], papan[2][1], papan[2][2]);
	printf("\n\t\t\t\xb3_____\xb3_____\xb3_____\xb3\n\n\n\n\n");
}

void buatPapan5x5(){
	printf("\n\n\n\n\n\t\t\t   1     2     3     4     5\n");
	printf("\t\t\t_______________________________\n");
	printf("\t\t     1\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[0][0], papan[0][1], papan[0][2], papan[0][3], papan[0][4]);
	printf("\n\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
	printf("\t\t     2\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[1][0], papan[1][1], papan[1][2], papan[1][3], papan[1][4]);
	printf("\n\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
	printf("\t\t     3\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[2][0], papan[2][1], papan[2][2], papan[2][3], papan[2][4]);
	printf("\n\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
	printf("\t\t     4\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[3][0], papan[3][1], papan[3][2], papan[3][3], papan[3][4]);
	printf("\n\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n");
	printf("\t\t     5\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[4][0], papan[4][1], papan[4][2], papan[4][3], papan[4][4]);
	printf("\n\t\t\t\xb3_____\xb3_____\xb3_____\xb3_____\xb3_____\xb3\n\n\n\n\n");
}
void buatPapan7x7(){
	printf("\n\n\n\n\n\t\t\t  1    2    3    4    5    6    7\n");
	printf("\t\t\t____________________________________\n");
	printf("\t\t     1\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[0][0], papan[0][1], papan[0][2], papan[0][3], papan[0][4], papan[0][5], papan[0][6]);
	printf("\n\t\t\t\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3\n");
	printf("\t\t     2\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[1][0], papan[1][1], papan[1][2], papan[1][3], papan[1][4], papan[1][5], papan[1][6]);
	printf("\n\t\t\t\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3\n");
	printf("\t\t     3\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[2][0], papan[2][1], papan[2][2], papan[2][3], papan[2][4], papan[2][5], papan[2][6]);
	printf("\n\t\t\t\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3\n");
	printf("\t\t     4\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[3][0], papan[3][1], papan[3][2], papan[3][3], papan[3][4], papan[3][5], papan[3][6]);
	printf("\n\t\t\t\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3\n");
	printf("\t\t     5\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[4][0], papan[4][1], papan[4][2], papan[4][3], papan[4][4], papan[4][5], papan[4][6]);
	printf("\n\t\t\t\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3\n");	
	printf("\t\t     6\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[5][0], papan[5][1], papan[5][2], papan[5][3], papan[5][4], papan[5][5], papan[5][6]);
	printf("\n\t\t\t\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3\n");	
	printf("\t\t     7\t\xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3  %c  \xb3", papan[6][0], papan[6][1], papan[6][2], papan[6][3], papan[6][4], papan[6][5], papan[6][6]);
	printf("\n\t\t\t\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3____\xb3\n\n\n\n\n");	
}

char cekPemenang3x3(){
	//cek baris
	for (int i = 0; i < 3; i++){
		if(papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2]){
			return papan[i][0];
		}
	}
	//cek kolom
	for (int i = 0; i < 3; i++){
		if(papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i]){
			return papan[0][i];
		}
	}
	//cek diagonal 
	if(papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2]){
			return papan[0][0];
	}	
	if(papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0]){
			return papan[0][2];
	}
	return ' ';
}

char cekPemenang5x5(){
	//cek baris
	for (int i = 0; i < 5; i++){
		if(papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2] && papan[i][0] == papan[i][3]){
			return papan[i][0];
		}
		if(papan[i][1] == papan[i][2] && papan[i][1] == papan[i][3] && papan[i][1] == papan[i][4]){
			return papan[i][1];
		}	
	}
	//cek kolom
	for (int i = 0; i < 5; i++){
		if(papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i] && papan[0][i] == papan[3][i]){
			return papan[0][i];
		}
		if(papan[1][i] == papan[2][i] && papan[1][i] == papan[3][i] && papan[1][i] == papan[4][i]){
			return papan[1][i];
		}
	}
	//cek diagonal 
	if(papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2] && papan[0][0] == papan[3][3]){
			return papan[0][0];
	}
	if(papan[1][0] == papan[2][1] && papan[1][0] == papan[3][2] && papan[1][0] == papan[4][3]){
	 		return papan[1][0];
	}
	if(papan[0][1] == papan[1][2] && papan[0][1] == papan[2][3] && papan[0][1] == papan[3][4]){
			return papan[0][1];
	}	
	if(papan[1][1] == papan[2][2] && papan[1][1] == papan[3][3] && papan[1][1] == papan[4][4]){
			return papan[1][1];
	}
	if(papan[1][3] == papan[2][2] && papan[1][3] == papan[3][1] && papan[1][3] == papan[4][0]){
			return papan[1][3];
	}
	if(papan[0][3] == papan[2][1] && papan[0][3] == papan[1][2] && papan[0][3] == papan[3][0]){
			return papan[0][3];
	}
	if(papan[1][4] == papan[2][3] && papan[1][4] == papan[3][2] && papan[1][4] == papan[4][1]){
			return papan[1][4];
	}
	if(papan[0][4] == papan[1][3] && papan[0][4] == papan[2][2] && papan[0][4] == papan[3][1]){
			return papan[0][4];
	}
	return ' ';
}



void bermain3x3(){
	char pemenang = ' ';
	
	resetPapan();
			
			
			while (pemenang == ' ' && cekRuangKosong() != 0){
				buatPapan3x3();
				
				giliranPemain1();
				pemenang = cekPemenang3x3();
				if (pemenang != ' ' || cekRuangKosong() == 0){
					break;
				}
				buatPapan3x3();
				giliranPemain2();
				pemenang = cekPemenang3x3();
				if (pemenang != ' ' || cekRuangKosong() == 0){
					break;
				}
			}
			
			buatPapan3x3();
			cetakPemenang(pemenang);
}

void bermain5x5(){
		char pemenang = ' ';
	
	resetPapan();
			
			
			while (pemenang == ' ' && cekRuangKosong() != 0){
				buatPapan5x5();
				
				giliranPemain1();
				pemenang = cekPemenang5x5();
				if (pemenang != ' ' || cekRuangKosong() == 0){
					break;
				}
				buatPapan5x5();
				giliranPemain2();
				pemenang = cekPemenang5x5();
				if (pemenang != ' ' || cekRuangKosong() == 0){
					break;
				}
			}
			
			buatPapan5x5();
			cetakPemenang(pemenang);
}

void cetakPemenang(char pemenang){
	if(pemenang == Pemain1){
		printf ("player1 menang!");
	}
	else if(pemenang == Pemain2){
		printf("player2 menang!");
	}
	else{
		printf("IT'S A TIE!");
	}
}
