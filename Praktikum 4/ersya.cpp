#include <iostream>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

// Fungsi untuk memeriksa apakah posisi tranversing lewat dari ketentuan matrix atau ga
bool isValidPosition(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Fungsi untuk menjelajahi pulau
void exploreIsland(int matrix[][COLS], int row, int col) {

    if (isValidPosition(row, col) && matrix[row][col] == 1) {
        // Menandai posisi saat ini sebagai bagian dari pulau
        matrix[row][col] = -1;

        // Menjelajahi posisi 
        exploreIsland(matrix, row - 1, col); // Atas
        exploreIsland(matrix, row + 1, col); // Bawah
        exploreIsland(matrix, row, col - 1); // Kiri
        exploreIsland(matrix, row, col + 1); // Kanan
    }
}

// Fungsi untuk menghitung jumlah pulau dalam matriks
int countIslands(int matrix[][COLS]) {
    int count = 0;

    // Melakukan pencarian pulau di seluruh matriks
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Jika elemen saat ini adalah daratan, maka menjelajahi pulau
            if (matrix[i][j] == 1) {
                count++;
                exploreIsland(matrix, i, j);
            }
        }
    }

    return count;
}

int main() {
    int matrix[ROWS][COLS];

    for(int i =0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>matrix[i][j];
        }
    }

    // for(int i =0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int islandCount = countIslands(matrix);
    cout << islandCount << endl;

    return 0;
}