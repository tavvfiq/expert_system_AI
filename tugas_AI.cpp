#include <iostream>
#include <string.h>

using namespace std;

#define banyak_penyakit 15
#define banyak_symptom 52 //ada di sheet
#define prob_penyakit 0.6666667 //1 banding 15

int penyakit [15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int clues[15] ={3,9,5,3,7,6,3,6,5,4,3,4,7,4,5};
int A[15][9]={{20,21,23},
	{1,2,5,9,10,18,23,24,25},
	{11,19,26,27,52},
	{1,12,52},
	{1,21,28,30,31,32,33},
	{1,3,4,6,8,34},
	{9,35,36},
	{9,37,38,39,40,41},
	{4,6,14,42,43},
	{1,4,5,6},
	{44,45,46},
	{3,13,47,48},
	{3,5,6,15,16,43,49},
	{1,7,12,50},
	{5,3,9,17,51}};

string msg_gejala[52] = {"Mata nyeri hebat",
"Mata menonjol",
"Penglihatan kabur",
"Peka terhadap cahaya",
"Mata merah",
"mata berair",
"mata perih",
"mata gatal",
"kelopak mata membengkak",
"mata ungu",
"mata sakit",
"air mata berlebihan",
"mata tegang",
"mata meradang",
"mata kering",
"mata iritasi",
"mata nyeri bila ditekan",
"demam",
"menekan kedipan berlebihan",
"sel batang retina sulit beradaptasi diruang yang remang-remang",
"pada siang hari penglihatan menurun",
"tidak dapat melihat pada lingkungan yang kurang bercahaya",
"pergerakan mata terbatas",
"mata tampak mengkilat",
"bola mata membengkak dan tampak berkabut",
"sumber cahaya akan berwarna pelangi bila memandang lampu neon",
"penglihatan yang tadinya kabur lama-kelamaan menjadi normal",
"malam hari kesulitan melihat",
"siang hari ketajaman mata menurun",
"mata silau akan cahaya",
"sering ganti kacamata",
"penglihatan ganda pada salah satu sisi mata",
"lensa mata membengkak",
"berbentuk keropeng pada kelopak mata ketika bangun pada siang hari",
"penglihatan menurun pada ruang gelap",
"penglihatan menurun pada malam hari",
"keluarnya cairan kotoran dari mata",
"berbaliknya bulu mata",
"pembengkakan kelenjar getah bening didepan telinga",
"munculnya garis parutan pada kornea",
"komplikasi pada telinga, hidung, dan tenggorokan",
"mata mempersempit, perubahan bentuk",
"benjolan pada mata bagian atas atau bawah",
"gangguan penglihatan pada salah satu mata",
"garis mata lurus terlihat bergelombang",
"mata tidak nyeri",
"mata terlihat melayang-layang",
"mata melihat kilatan cahaya",
"seperti ada benda asing di mata",
"sakit kepala",
"riwayat penyakit menular seksual pada ibu",
"mata membengkak"};

int kesimpulan[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
float temp1;
float temp2;

float bobot_symptom[52];
float bobot_penyakit[15];
int gejala;
int input;

float hitung_bobot_symptom(float array[], int size){
	float temp = array[0];
	for (int i = 1;i<size;i++){
		temp = temp * array[i];
	}
	return temp;
}

void print_gejala(){
	for (int i=0;i<banyak_symptom;i++){
		cout << i+1 << ". "<< msg_gejala[i] <<"\n";
	}
}

int main(){
	print_gejala();
	cout << "Masukkan banyaknya gejala (max 52): ";
	cin >> gejala;
	int input_user[gejala];
	cout << "\n";
	for (int i=0;i<gejala;i++){
		cout << "gejala ke-"<<i+1<<" : ";
		cin >> input;
		input_user[i] = input;
	}
	for (int i=0;i<banyak_penyakit;i++){
			int j=0;
			int k=0;
			while(j<gejala){
					if(input_user[j] == A[i][k]){
						bobot_symptom[j] = ((1 + banyak_symptom) * prob_penyakit)/(1 + banyak_symptom);
						j++;
						k=0;
					} else {
						k++;
					}
					if (k==clues[i]){
						bobot_symptom[j] = ((0 + banyak_symptom) * prob_penyakit)/(1 + banyak_symptom);
						j++;
						k=0;
					}
			}
			bobot_penyakit[i] = prob_penyakit * hitung_bobot_symptom(bobot_symptom,gejala);
	}
	
	for(int i=0; i<banyak_penyakit; i++){
       for(int j=i; j<banyak_penyakit; j++){
          if(bobot_penyakit[i] < bobot_penyakit[j]){
              temp1 = bobot_penyakit[j];
              temp2 = kesimpulan[j];
              bobot_penyakit[j] = bobot_penyakit[i];
              kesimpulan[j] = kesimpulan[i];
              bobot_penyakit[i] = temp1;
              kesimpulan[i] = temp2;
          }
       }
	}
	cout << "\n";

	for(int i=0;i<3;i++){
		if(i==0){
			cout << "Paling Memungkinkan: ";
		} else if(i==1){
			cout << "Memungkinkan: ";
		} else if(i==2){
			cout << "Kecil kemungkinan: ";
		} 
		switch(kesimpulan[i]){
			case 0:
				cout << "Menderita penyakit Xerophtalmania"<<endl;
				break;
			case 1:
				cout << "Menderita penyakit Selulitis Orbitalitas"<<endl;
				break;
			case 2:
				cout << "Menderita penyakit Glaukoma"<<endl;
				break;
			case 3:
				cout << "Menderita penyakit Dakriosistitis"<<endl;
				break;
			case 4:
				cout << "Menderita penyakit Katarak"<<endl;
				break;
			case 5:
				cout << "Menderita penyakit Konjungtivitis"<<endl;
				break;
			case 6:
				cout << "Menderita penyakit Retinitis Pigmentosa"<<endl;
				break;
			case 7:
				cout << "Menderita penyakit Trakoma"<<endl;
				break;
			case 8:
				cout << "Menderita penyakit Oveitis"<<endl;
				break;
			case 9:
				cout << "Menderita penyakit Hordeolum"<<endl;
				break;
			case 10:
				cout << "Menderita penyakit Degenerasi Makula"<<endl;
				break;
			case 11:
				cout << "Menderita penyakit Ablasio Retina"<<endl;
				break;
			case 12:
				cout << "Menderita penyakit Pterygium"<<endl;
				break;
			case 13:
				cout << "Menderita penyakit Miopi"<<endl;
				break;
			case 14:
				cout << "Menderita penyakit Oftalmia Neonatorium"<<endl;
				break;
		}
  }
}
