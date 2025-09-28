#include <iostream>

// ������ ������ �迭�� �����մϴ�.
const int COINS[] = { 500, 100, 50, 10 };
const int NUM_COINS = sizeof(COINS) / sizeof(COINS[0]);

// ���� ���� ���� �������� �ݾ��� ����ϰ� ����ϴ� �Լ�
void get_change(int amount) {
    int coin_counts[NUM_COINS] = { 0 }; // �� ������ ������ ������ �迭
    int remaining_amount = amount; // ���� �ݾ�
    int total_coins = 0; // �� ���� ����

    // ���� �迭�� ������� ���鼭 ����մϴ�.
    for (int i = 0; i < NUM_COINS; ++i) {
        int current_coin = COINS[i];

        if (remaining_amount >= current_coin) {
            // ���� �������� �Ž��� �� �� �ִ� ������ ����մϴ�.
            int count = remaining_amount / current_coin;
            coin_counts[i] = count;
            total_coins += count;

            // ���� �ݾ��� �����մϴ�.
            remaining_amount %= current_coin;
        }
    }

    // ����� ����մϴ�.
    std::cout << amount << "���� �Ž��� �ִµ� �ʿ��� ������ ����:" << std::endl;
    for (int i = 0; i < NUM_COINS; ++i) {
        if (coin_counts[i] > 0) {
            std::cout << COINS[i] << "��: " << coin_counts[i] << "��" << std::endl;
        }
    }

    std::cout << "�� ���� ����: " << total_coins << "��" << std::endl;
}

int main() {
    int amount;
    std::cout << "�Ž��� �� �ݾ��� �Է��ϼ���: ";
    std::cin >> amount;

    get_change(amount);

    return 0;
}