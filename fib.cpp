/*
#include <iostream>

// ��� �Լ��� �Ǻ���ġ ������ ����ϴ� �Լ�
long long fibonacci_recursive(int n) {
    // n�� 0�̰ų� 1�� ���, n�� �״�� ��ȯ (���� ����)
    if (n <= 1) {
        return n;
    }

    // ���� �� ���� ���� ��������� ȣ���Ͽ� ��ȯ
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int num;
    std::cout << "�� ��° �Ǻ���ġ ���� ���ұ��? ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "������ �Է��� �� �����ϴ�." << std::endl;
    }
    else {
        std::cout << num << "��° �Ǻ���ġ ���� " << fibonacci_recursive(num) << "�Դϴ�." << std::endl;
    }

    return 0;
}*/
// ��� �Լ��� ����� �� �Լ��� ȣ���� ������ ���ÿ� �޸� ���� �׿�, ���� �����÷ο� �߻� 
// �ڵ��� �������� ������ �ߺ� ����� ���� ��� �������� ����. -> �ݺ��̳� ���� ���α׷��� ���


#include <iostream>

// �ݺ������� �Ǻ���ġ ������ ����ϴ� �Լ�
long long fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }

    long long a = 0; // 0��° ��
    long long b = 1; // 1��° ��
    long long result = 0;

    // 2��° �׺��� n��° �ױ��� �ݺ��ϸ� ���
    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

int main() {
    int num;
    std::cout << "�� ��° �Ǻ���ġ ���� ���ұ��? ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "������ �Է��� �� �����ϴ�." << std::endl;
    }
    else {
        std::cout << num << "��° �Ǻ���ġ ���� " << fibonacci_iterative(num) << "�Դϴ�." << std::endl;
    }

    return 0;
}

// ������� 200�� ���� ������ ���� ����Ŭ�ο� �߻� ( ������ ���� ) / long long �� 64��Ʈ�� ������ ���μ� ���� 93���������� �Ѱ� . 
// �� ū ���� ����Ϸ��� �� ū ���� �ٷ� �� �ִ� ��� �ʿ� 