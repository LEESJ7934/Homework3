#include <iostream>
#include <vector>
#include <queue>
#include "Dijkstra.h"

using namespace std;

#define VERTEX 10000 // 최대 정점의 개수를 10000개로 설정하였다.
#define Init 100000 

//main함수 선언문 

int main()
{
    int x, y;

    cout << "Number of Vertex : "; //정점의 개수를 입력하는 문자 출력
    cin >> x; //정점의 개수를 입력하는 문자 입력

    cout << "Number of Trunk : "; //간선의 개수를 입력하는 문자 출력
    cin >> y; //간선의 개수를 입력하는 문자 입력

    vector<pair<int, int> > queue[VERTEX];

    for (int i = 0; i < y; i++) {
        int come, arrive, cost;

        cout << "Enter graph Vertex Vertex Trunk: ";
        cin >> come >> arrive >> cost;

        queue[come].push_back(make_pair(arrive, cost));
        queue[arrive].push_back(make_pair(come, cost));
    }

    vector<int> distance = Dijkstra(0, x, queue); //거리를 나타낸다. 

    for (int i = 0; i < x; i++) { // 0부터 정점개수 까지 
        printf("0 to %d shortest pash : %d\n", i, distance[i]);
    }
    return 0;
}
