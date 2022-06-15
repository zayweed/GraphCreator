/*

*/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int main() {
  int matrix[20][20];
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      matrix[i][j] = 0;
    } 
  }
  map<char, int> mp;
  int size = 0;

  bool stillPlaying = true;
  while (stillPlaying == true) {
    cout << "Would you like to add or remove a vertex(AV)/(RV), add or remove an edge(AE)/(RE), find the shortest path(PATH), print the adjacency matrix(PRINT), or quit(QUIT)?" << endl;
    char input[100];
    cin >> input;
    if (strcmp(input, "AV") == 0) {
      size++;
      cout << "Enter the name of the vertex(has to be a character):" << endl;
      char c; cin >> c;
      mp[c] = size-1;
    }
    
    if (strcmp(input, "RV") == 0) {
      cout << "Enter the name of the vertex(has to be a character):" << endl;
      char c; cin >> c;
      for (int i = 0; i < size; i++) {
        matrix[mp[c]][i] = -1;
        matrix[i][mp[c]] = -1;
      }
      mp.erase(c);
    }

    if (strcmp(input, "AE") == 0) {
      cout << "Enter the two vertices and the weight seperated by spaces:" << endl;
      char a, b; cin >> a >> b;
      int n; cin >> n;
      matrix[mp[a]][mp[b]] = n;
    }
    
    if (strcmp(input, "RE") == 0) {
      cout << "Enter the two vertices seperated by a space:" << endl;
      char a, b; cin >> a >> b;
      matrix[mp[a]][mp[b]] = 0;
    }

    if (strcmp(input, "PATH") == 0) {

    }

    if (strcmp(input, "PRINT") == 0) {
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          cout << matrix[i][j] << "\t";
        } 
        cout << endl;
      }
    }
    
    if (strcmp(input, "QUIT") == 0) {
      stillPlaying = false;
    }
  }
}
