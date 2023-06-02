#include <iostream>
#include <queue>
using namespace std;

int N, M, X, Y;
int matrix[1000][1000];
bool cek[1000][1000];

bool koordinat(int i, int j) {
    return (i >= 0 && i < N && j >= 0 && j < M); // Memeriksa apakah koordinat (i, j) berada dalam batas matriks
}

//bfs
int hitungLuas() {
    int dx[] = {-1, 1, 0, 0}; //perpindahan horizontal
    int dy[] = {0, 0, -1, 1}; //perpindahan vertikal
    int luas = 0;
    
    queue<pair<int, int>> q;
    q.push(make_pair(X, Y));
    cek[X][Y] = true;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front(); 
        q.pop(); 
        int x = curr.first; //elemen pertama yang diambil
        int y = curr.second; //elemen kedua yang diambil
        
        luas++;
        
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k]; //kesebelah kanan atau kiri
            int ny = y + dy[k]; //kesebelah atas atau bawah
            
            if (koordinat(nx, ny) && !cek[nx][ny] && matrix[nx][ny] <= matrix[x][y]) {
                q.push(make_pair(nx, ny)); 
                cek[nx][ny] = true; 
            }
        }
    }
    
    return luas; 
}

int main() {
    cin >> N >> M >> X >> Y; 
    X--; 
    Y--;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j]; //masukin nilai pada matriks
        }
    }
    
    int luas = hitungLuas(); 
    cout << luas << endl;
    
    return 0;
}
