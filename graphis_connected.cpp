#include <iostream>
#include <ctime>
using namespace std;
const int size=7;

bool is_connected(bool *graph[], int size){
    int old_size=0, c_size=0;
    bool* close = new bool[size];
    bool* open = new bool[size];
    for(int i=0; i<size; ++i)
        open[i] = close[i] = false;
    open[0] = true;
    while(c_size < size){
        for(int i=0; i<size; ++i){
            old_size = c_size;
            if(open[i] && (close[i] == false)){
                close[i] = true; c_size++;
            }
            for(int j=0; j<size; ++j)
                open[j] = open[j] || graph[i][j];
        }
    }
    if(c_size == size) return true;
    if(old_size == c_size) return false;
}
int main(){
    bool** graph;
    srand(time(0));
    graph = new bool*[size];
    for(int i=0; i<size; ++i)
        graph[i] = new bool[size];
    for(int i=0; i<size; ++i)
        for(int j=i; j<size; ++j)
            if(i==j) graph[i][j] = false;
            else graph[i][j] = graph[j][i] = (prob()<0.19);
}
