/*
Zayeed Saffat
6/15/2022
This project makes a weighted directed graph that is represented by a two dimensional array.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int matrix[100][100]; //adjacency matrix
  for (int i = 0; i < 100; i++) { //fill with 0s
    for (int j = 0; j < 100; j++) {
      matrix[i][j] = 0;
    } 
  }
  map<char, int> indexes; //name to index in matrix
  char names[20]; //index in matrix to name(only used for labels when printing matrix)
  set<int> deleted; //indexes of vertexs that were deleted
  int size = 0; //total size of matrix

  bool stillPlaying = true;
  while (stillPlaying == true) {
    cout << "Would you like to add or remove a vertex(AV)/(RV), add or remove an edge(AE)/(RE), find the shortest path(PATH), print the adjacency matrix(PRINT), or quit(QUIT)?" << endl;
    char input[100];
    cin >> input;
    
    if (strcmp(input, "AV") == 0) { //add vertex
      size++; //update size
      cout << "Enter the name of the vertex(has to be a character):" << endl;
      char c; cin >> c;
      
      indexes[c] = size-1; //records index of vertex
      names[size-1] = c; //records name of vertex
    }
    
    if (strcmp(input, "RV") == 0) { //remove vertex
      cout << "Enter the name of the vertex(has to be a character):" << endl;
      char c; cin >> c;
      
      if (indexes.count(c) == 1) { //if there is a vertex with the inputted name
        deleted.insert(indexes[c]); //record index of removed vertex
        names[indexes[c]] = ' '; //replace name of vertex with blank space to indicate deleted vertex
        indexes.erase(c); //remove from map
      }
      else {
        cout << "Vertex does not exist!" << endl;
      }
    }

    if (strcmp(input, "AE") == 0) { //add edge
      cout << "Enter the two vertices and the weight seperated by spaces:" << endl;
      char a, b; cin >> a >> b;
      int n; cin >> n;
      
      matrix[indexes[a]][indexes[b]] = n; //add edge to matrix
    }

    if (strcmp(input, "RE") == 0) { //remove edge
      cout << "Enter the two vertices seperated by a space:" << endl;
      char a, b; cin >> a >> b;

      if (indexes.count(a) == 1 && indexes.count(b) == 1) { //if there are vertices with the inputted names
        matrix[indexes[a]][indexes[b]] = 0; //remove edge edge matrix
      }
      else {
        cout << "At least one of the two vertices does not exist!" << endl;
      }
    }

    if (strcmp(input, "PATH") == 0) { //shortest path using Dijkstra's Algorithm

    }

    if (strcmp(input, "PRINT") == 0) { //print matrix
      cout << "\t";
      for (int i = 0; i < size; i++) { //print labels for ending vertex
        if (names[i] != ' ') {
          cout << names[i] << "\t";
        }
      }
      cout << endl;
      
      for (int i = 0; i < size; i++) {
        if (deleted.count(i) != 1) {
          cout << names[i] << "\t"; //print labels for starting vertex
          for (int j = 0; j < size; j++) {
            if (deleted.count(j) != 1) {
              cout << matrix[i][j] << "\t";
            }
          }
          cout << endl;
        }
      }
    }
    
    if (strcmp(input, "QUIT") == 0) { //quit
      stillPlaying = false;
    }
  }
}
