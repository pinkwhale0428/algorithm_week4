#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

// �л� ������ ��� ����ü
struct Student {
    std::string name;
    int score;
    int id; // �л��� ���� ��ȣ
};

// �̸������� �����ϱ� ���� �� �Լ�
bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

// ���������� �������� �����ϱ� ���� �� �Լ�
bool compareByScoreDesc(const Student& a, const Student& b) {
    return a.score > b.score;
}

// �л� �����͸� ����ϴ� �Լ�
void printStudents(const std::string& title, const std::vector<Student>& students) {
    std::cout << "--- " << title << " ---" << std::endl;
    for (const auto& s : students) {
        std::cout << "ID: " << s.id << ", �̸�: " << s.name << ", ����: " << s.score << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // 1. �ʱ� �л� ������ ����
    std::vector<Student> students = {
        {"�ź���", 85, 101},
        {"������", 92, 102},
        {"ȣ����", 85, 103},
        {"�����", 78, 104},
        {"������", 92, 105},
        {"�۾���", 95, 106}
    };

    printStudents("�ʱ� �л� ���", students);

    // 2. std::sort�� Ŀ���� �� �Լ� ���
    // �̸��� �������� ����. ������(score 85, 92)�� ������ ������� ����.
    std::sort(students.begin(), students.end(), compareByName);
    printStudents("�̸��� ���� (std::sort)", students);

    // 3. std::stable_sort�� Ŀ���� �� �Լ� ���
    // ������ �������� �����ϵ�, �������� ����(ID)�� ����.
    // Eva(92, ID: 105)�� Bob(92, ID: 102)�� �ʱ� ������ Eva-Bob�̹Ƿ� ���� �Ŀ��� �� ������ ������.
    std::stable_sort(students.begin(), students.end(), compareByScoreDesc);
    printStudents("���� �������� ���� (std::stable_sort)", students);

    // 4. std::partial_sort�� ����Ͽ� ���� 3�� ����
    // ��ü �л� �� ���� ���� 3�� �����ϰ�, �������� �������� ����.
    // �� ����� ��ü�� �����ϴ� �ͺ��� ������.
    std::partial_sort(students.begin(), students.begin() + 3, students.end(), compareByScoreDesc);
    printStudents("���� 3�� ������ ���� (std::partial_sort)", students);

    // �� �ܿ��� std::nth_element�� ����ϸ� N��° ���Ҹ� ã�Ƽ� �� ��ġ�� ����,
    // �ٸ� ���ҵ��� N��° ���Ҹ� �������� ���� �� �ֽ��ϴ�.

    return 0;
}