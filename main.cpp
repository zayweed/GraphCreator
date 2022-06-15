/*

*/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int matrix[20][20]; //adjacency matrix
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      matrix[i][j] = 0;
    } 
  }
  map<char, int> mp; //map that returns index of node given its name
  char mpR[20]; //map that returns name of node given its index(used for printing labels of adjacency matrix)
  set<int> set; //list of the index of the removed nodes that should be ignored
  int size = 0; //current number of nodes

  bool stillPlaying = true;
  while (stillPlaying == true) {
    cout << "Would you like to add or remove a vertex(AV)/(RV), add or remove an edge(AE)/(RE), find the shortest path(PATH), print the adjacency matrix(PRINT), or quit(QUIT)?" << endl;
    char input[100];
    cin >> input;
    if (strcmp(input, "AV") == 0) {
      size++; //update size
      cout << "Enter the name of the vertex(has to be a character):" << endl;
      char c; cin >> c;
      mp[c] = size-1; //sets index of node
      mpR[size-1] = c; //records name of node given index
    }
    
    if (strcmp(input, "RV") == 0) {
      cout << "Enter the name of the vertex(has to be a character):" << endl;
      char c; cin >> c;
      set.insert(mp[c]); //record as a removed node
      mpR[mp[c]] = ' '; //
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
      cout << "\t";
      for (int i = 0; i < size; i++) {
        if (mpR[i] != ' ') {
          cout << mpR[i] << "\t";
        }
      }
      cout << endl;
      for (int i = 0; i < size; i++) {
        if (set.count(i) != 1) {
          cout << mpR[i] << "\t";
          for (int j = 0; j < size; j++) {
            if (set.count(j) != 1) {
              cout << matrix[i][j] << "\t";
            }
          }
          cout << endl;
        }
      }
    }
    
    if (strcmp(input, "QUIT") == 0) {
      stillPlaying = false;
    }
  }
}
