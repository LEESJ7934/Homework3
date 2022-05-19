#include <iostream>
#include <vector>
#include <queue>

#ifndef Dijkstra_H
#define Dijkstra_H

using namespace std;

#define VERTEX 10000 // 최대 정점의 개수를 10000개로 설정하였다.
#define Init 100000 

//Dijkstra’s shortest pash 알고리즘 함수를 헤더파일에 구현하였다.

vector<int> Dijkstra(int Start, int V, vector<pair<int, int> > list[]) {
    vector<int> distance(V, Init);    //변수를 전부 초기화한다.
    priority_queue<pair<int, int> > queue; //큐 우선순위를 정한다.

    distance[Start] = 0; //시작하는 지점을 0으로 초기화한다.
    queue.push(make_pair(0, Start));    // 시작하는 정점을 방문한다.

    while (!queue.empty()) {
        int expanse = -queue.top().first;    // 방문한 정점의 dist 값 을 expanse의 변수로 선언한다.

        int cur = queue.top().second;    // 현재 방문한 정점을 cur이라는 변수로 선언한다.
        queue.pop();

        for (int i = 0; i < list[cur].size(); i++) {    // 현재 방문한 정점의 주변 정점을 확인한다.
            int next = list[cur][i].first;    // 다음 정점을 입력한다.

            int nexpanse = expanse + list[cur][i].second;    // 현재 방문한 정점을 거쳐서 다음 정점을 갈때의 시간을 계산한다. 

            if (nexpanse < distance[next]) {     // 기존 값 보다 현재 방문한 정점을 거친 값이 더 크면 갱신하는 조건문을 선언한다.
                distance[next] = nexpanse;
                queue.push(make_pair(-nexpanse, next));    // queue에 저장 
            }
        }
    }

    return distance;
}

#endif
