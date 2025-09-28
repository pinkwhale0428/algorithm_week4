#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

// 학생 정보를 담는 구조체 
struct Student {
    std::string name;
    int score;
    int id; // 학생의 고유 번호
};

// 이름순으로 정렬하기 위한 비교 함수
bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

// 점수순으로 내림차순 정렬하기 위한 비교 함수
bool compareByScoreDesc(const Student& a, const Student& b) {
    return a.score > b.score;
}

// 학생 데이터를 출력하는 함수
void printStudents(const std::string& title, const std::vector<Student>& students) {
    std::cout << "--- " << title << " ---" << std::endl;
    for (const auto& s : students) {
        std::cout << "ID: " << s.id << ", 이름: " << s.name << ", 점수: " << s.score << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // 1. 초기 학생 데이터 생성
    std::vector<Student> students = {
        {"거북이", 85, 101},
        {"망아지", 92, 102},
        {"호랑이", 85, 103},
        {"고양이", 78, 104},
        {"강아지", 92, 105},
        {"송아지", 95, 106}
    };

    printStudents("초기 학생 명단", students);

    // 2. std::sort와 커스텀 비교 함수 사용
    // 이름을 기준으로 정렬. 동점자(score 85, 92)의 순서는 보장되지 않음.
    std::sort(students.begin(), students.end(), compareByName);
    printStudents("이름순 정렬 (std::sort)", students);

    // 3. std::stable_sort와 커스텀 비교 함수 사용
    // 점수를 기준으로 정렬하되, 동점자의 순서(ID)를 유지.
    // Eva(92, ID: 105)와 Bob(92, ID: 102)은 초기 순서가 Eva-Bob이므로 정렬 후에도 이 순서를 유지함.
    std::stable_sort(students.begin(), students.end(), compareByScoreDesc);
    printStudents("점수 내림차순 정렬 (std::stable_sort)", students);

    // 4. std::partial_sort를 사용하여 상위 3명만 정렬
    // 전체 학생 중 점수 상위 3명만 정렬하고, 나머지는 정렬하지 않음.
    // 이 방법은 전체를 정렬하는 것보다 빠르다.
    std::partial_sort(students.begin(), students.begin() + 3, students.end(), compareByScoreDesc);
    printStudents("상위 3명만 점수순 정렬 (std::partial_sort)", students);

    // 이 외에도 std::nth_element를 사용하면 N번째 원소만 찾아서 제 위치에 놓고,
    // 다른 원소들은 N번째 원소를 기준으로 나눌 수 있습니다.

    return 0;
}
