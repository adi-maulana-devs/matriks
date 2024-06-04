#include <iostream>  
using namespace std;

// Tugas Algoritma Pemrograman II - Array
// Operasi Matriks
// Adi Maulana Amin - 23552011199
// Hilwa Khazimah Khoerunisa - 23552011399
// Ramdan Abdul Latif Hapidin - 23552011184

int baris, kolom;
int pilihan;

int** matriks1; 
int** matriks2;
int** hasil;

void printMenu() { 
	cout << endl << "Menu Operasi Matriks:" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "0. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
}

int** inputMatriks( int n, int baris, int kolom) {
    // Alokasi baris x kolom untuk setiap baris pada matriks yang diinputkan
	int** matriks = new int*[baris]; 
    for (int i = 0; i < baris; i++) {
        matriks[i] = new int[kolom];
    }
    
    cout << endl << "Masukkan elemen matriks ke-" << n << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Input Baris " << i + 1 << " Kolom " << j + 1 << " : ";
            cin >> matriks[i][j];
        }
    }
    return matriks;
}

void printMatriks(int** matriks, int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

int** penjumlahanMatriks(int** matriks1, int** matriks2, int baris, int kolom) {
    // Alokasi baris x kolom untuk setiap baris pada matriks hasil
	int** hasil = new int*[baris]; 
    for (int i = 0; i < baris; i++) {
        hasil[i] = new int[kolom];
    }
	// Logic Penjumlahan matriks
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
        }
    }
    return hasil;
}

int** penguranganMatriks(int** matriks1, int** matriks2, int baris, int kolom) {
    // Alokasi baris x kolom untuk setiap baris pada matriks hasil
	int** hasil = new int*[baris]; 
    for (int i = 0; i < baris; i++) {
        hasil[i] = new int[kolom];
    }
	// Logic Pengurangan matriks
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
        }
    }
    return hasil;
}

int** perkalianMatriks(int** matriks1, int** matriks2, int baris, int kolom) {
    // Alokasi baris x kolom untuk setiap baris pada matriks hasil
	int** hasil = new int*[baris]; 
    for (int i = 0; i < baris; i++) {
        hasil[i] = new int[kolom];
    }
	// Logic Perkalian matriks
     for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < kolom; k++) {
                hasil[i][j] += matriks1[i][k] * matriks2[k][j];
            }
        }
    }
    return hasil;
}

int main() {	
    do {
        printMenu();
        cin >> pilihan;

		if (pilihan == 1) {
			baris = 2;
            kolom = 2;
            matriks1 = inputMatriks(1, baris, kolom);
			matriks2 = inputMatriks(2, baris, kolom);
          	hasil = penjumlahanMatriks(matriks1, matriks2, baris, kolom);
                
            cout << endl << "Penjumlahan Matriks" << endl;
          	printMatriks(matriks1, baris, kolom);
    		cout << " + " << endl;
    		printMatriks(matriks2, baris, kolom);
			cout << " = " << endl;
			printMatriks(hasil, baris, kolom);

		} else if (pilihan == 2) {
			baris = 3;
            kolom = 3;
            matriks1 = inputMatriks(1, baris, kolom);
			matriks2 = inputMatriks(2, baris, kolom);
          	hasil = penguranganMatriks(matriks1, matriks2, baris, kolom);
            
            cout << endl << "Pengurangan Matriks" << endl;
          	printMatriks(matriks1, baris, kolom);
    		cout << " - " << endl;
    		printMatriks(matriks2, baris, kolom);
			cout << " = " << endl;
			printMatriks(hasil, baris, kolom);
			
		} else if (pilihan == 3) {
			baris = 3;
            kolom = 3;
            matriks1 = inputMatriks(1, baris, kolom);
			matriks2 = inputMatriks(2, baris, kolom);
          	hasil = perkalianMatriks(matriks1, matriks2, baris, kolom);
                
            cout << endl << "Perkalian Matriks" << endl;
          	printMatriks(matriks1, baris, kolom);
    		cout << " - " << endl;
    		printMatriks(matriks2, baris, kolom);
			cout << " = " << endl;
			printMatriks(hasil, baris, kolom);
			
		} else if (pilihan == 0) {
			cout << "Terima kasih telah menggunakan program ini." << endl;
            break;
            
		} else {
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		} 	
    } while (pilihan != 0);

    return 0;
}

