#include <iostream>
#include <vector>

using namespace std;

int n, m;
int houseCnt;
int chickenHouseCnt;
int minCityChickenDis = 999999999;
int map[101][13];
pair<int, int> chosenChickenHouse[14];
vector<pair<int, int>> house;
vector<pair<int, int>> chickenHouse;


void Initialize() { // 초기화 함수a
    int input;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;

            if (input == 1) {
                house.push_back({ i, j });
            }
            else if (input == 2) {
                chickenHouse.push_back({ i, j });
            }
        }
    }

    houseCnt = house.size();
    chickenHouseCnt = chickenHouse.size();

    cout << "집 개수: " << houseCnt << '\n';
    cout << "치킨집 개수: " << chickenHouseCnt << '\n';
}

void ChooseAlgorithm(int _level, int _rootIdx) { // DFS 원리 _pivot: 탐색을 시작할 인덱스
    if (_level >= m) { // 재귀의 끝
        // 도시의 치킨 거리 저장
        int temp = 0;

        for (int i = 0; i < houseCnt; i++) {
            for (int j = 0; j < m; j++) {
                // m개의 치킨집 중 가장 가까운 치킨집의 치킨거리를 temp에 더하기
                if (map[i][j] != 0) { // 저장된 값이 있다면 재사용
                }
            }
        }
        // house에서 각 치킨집까지의 거리를 저장해두기
        return;
    }

    chosenChickenHouse[_rootIdx] = chickenHouse[_rootIdx]; // 현재까지 선택한 치킨집 저장

	for (int i = _rootIdx + 1; i < chickenHouseCnt - m + _level; i++) { // 다음 치킨집 선택
        ChooseAlgorithm(_level + 1, i);
	}
}

int main(void) {

	return 0;
}


//#include <iostream>
//#include <cmath>
//#include <cstdlib>
//#include <vector>
//
//using namespace std;
//
//int n, m;
//int chickenDis;
//int cityChickenDis;
//int chickenHouseCnt = 0;
//pair<int, int> curChickenHouse;
//vector<pair<pair<int, int>, int>> house;
//vector<pair<int, int>> chickenHouse;
//
//void Initialize() { // 초기화 함수a
//    int input;
//    cin >> n >> m;
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> input;
//
//            if (input == 1) {
//                house.push_back({ {i, j}, 0 });
//            }
//            else if (input == 2) {
//                chickenHouse.push_back({ i, j });
//                chickenHouseCnt++;
//            }
//        }
//    }
//
//    cout << "\n집 개수: " << house.size() << '\n';
//    cout << "치킨집 개수: " << chickenHouseCnt << '\n';
//}
//
//void InitChickenDis() {
//    for (int i = 0; i < house.size(); i++) {
//        house[i].second = 0;
//    }
//}
//
//// 함수) 치킨 거리를 구하고 배열에 저장
//void CalChickenDis(int _exceptedChickenHouse) {
//    int tempDis;
//    InitChickenDis();
//
//    for (int i = 0; i < house.size(); i++) {
//        for (int j = 0; j < chickenHouse.size(); j++) {
//            if (_exceptedChickenHouse < 14 && _exceptedChickenHouse == j) { // 임의의 치킨집 제외
//                continue;
//            }
//
//            tempDis = abs(house[i].first.first - chickenHouse[j].first)
//                + abs(house[i].first.second - chickenHouse[j].second);
//
//            if (house[i].second == 0) {
//                house[i].second = tempDis;
//                cout << "초기 계산: house[" << i << "].second = " << house[i].second << '\n';
//            }
//            else if (house[i].second > tempDis) {
//                house[i].second = tempDis;
//                cout << "기존 치킨 거리: " << house[i].second << "   더 가까운 치킨 거리: " << tempDis << "\n    ===> " << "house[" << i << "].second = " << house[i].second << '\n';
//            }
//        }
//    }
//}
//
//// 함수) 도시의 치킨거리를 구하는 함수
//void CalCityChickenDis() {
//    cityChickenDis = 0;
//
//    for (int i = 0; i < house.size(); i++) {
//        cityChickenDis += house[i].second;
//    }
//}
//
//// 함수) 도시의 치킨거리가 가장 변하지 않는 치킨집을 고르는 함수
//void ChooseUselessChickenHouse() {
//    int tempCityChickenDis = 0;
//    int uselessChickenHouseIdx = 0;
//
//    for (int i = 0; i < chickenHouse.size(); i++) {
//        CalChickenDis(i);
//        CalCityChickenDis();
//
//        if (tempCityChickenDis == 0) {
//            tempCityChickenDis = cityChickenDis;
//            uselessChickenHouseIdx = i;
//            cout << "폐업 치킨집 인덱스 초기 설정: uselessChickenHouseIdx = " << uselessChickenHouseIdx << '\n';
//        }
//        else if (tempCityChickenDis > cityChickenDis) {
//            tempCityChickenDis = cityChickenDis;
//            uselessChickenHouseIdx = i;
//            cout << "    ===> " << "uselessChickenHouseIdx = " << uselessChickenHouseIdx << '\n';
//        }
//
//        cout << i << "번째 치킨집을 제외한 도시의 치킨거리 값: " << cityChickenDis << '\n';
//    }
//
//    // 치킨집 목록 벡터에서 삭제하기
//    chickenHouse.erase(chickenHouse.begin() + uselessChickenHouseIdx);
//    cout << uselessChickenHouseIdx << "번째 치킨집을 폐업합니다." << '\n';
//}
//
//int main(void) {
//    Initialize();
//    CalChickenDis(15);
//
//    for (int i = 0; i < chickenHouseCnt - m; i++) {
//        cout << "---- " << i << "차 치킨집 폐업----\n";
//        ChooseUselessChickenHouse();
//    }
//
//    CalCityChickenDis();
//    cout << cityChickenDis;
//    return 0;
//}