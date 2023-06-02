#include <iostream>
using namespace std;

int ROWS,COLS;

int luas=0;
// Fungsi untuk memeriksa apakah posisi tranversing lewat dari ketentuan matrix atau ga
bool isValidPosition(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Fungsi untuk menjelajahi pulau
void exploreIsland(char** matrix, int row, int col) {

    if (isValidPosition(row, col) && matrix[row][col] == '.') {
        // Menandai posisi saat ini sebagai bagian dari pulau
        matrix[row][col] = '0';

    if(matrix[row-1][col] == '#')
        luas++;    
    if(matrix[row+1][col] == '#')
        luas++; 
    if(matrix[row][col-1] == '#')
        luas++; 
    if(matrix[row][col+1] == '#')
        luas++; 
    
        // Menjelajahi posisi 
        exploreIsland(matrix, row - 1, col); // Atas
        exploreIsland(matrix, row + 1, col); // Bawah
        exploreIsland(matrix, row, col - 1); // Kiri
        exploreIsland(matrix, row, col + 1); // Kanan
    }
}

// Fungsi untuk menghitung jumlah pulau dalam matriks
void countIslands(char** matrix, int y, int x) {
     
    // Melakukan pencarian pulau di seluruh matriks
    for (int i = y; i < ROWS; i++) {
        for (int j = x; j < COLS; j++) {
            // Jika elemen saat ini adalah daratan, maka menjelajahi pulau
            if (matrix[i][j] == '.') {
                exploreIsland(matrix, i, j);
                return;
            }
        }
    }
}

int main() {
    int n;
    cin>>ROWS>>COLS>>n;
    int point_x,point_y;
    char main_matrix[ROWS][COLS];

    char** matrix = new char*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = new char[COLS];
    }

    for(int i =0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            cin>>main_matrix[i][j];
        }
    }

    for(int k=0;k<n;k++){
        cin>>point_x>>point_y;

        //ngopy matrix
        for(int i =0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                matrix[i][j] = main_matrix[i][j];
            }
        }

        countIslands(matrix,point_x-1,point_y-1);
        cout<<luas<<endl;
        luas=0;
    }
    // int islandCount = countIslands(matrix);
    // cout << islandCount << endl;

    //     //print
    // for(int i =0;i<ROWS;i++){
    //     for(int j=0;j<COLS;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}