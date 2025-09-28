#include <iostream>

// 동전의 종류를 배열에 저장합니다.
const int COINS[] = { 500, 100, 50, 10 };
const int NUM_COINS = sizeof(COINS) / sizeof(COINS[0]);

// 가장 적은 수의 동전으로 금액을 계산하고 출력하는 함수
void get_change(int amount) {
    int coin_counts[NUM_COINS] = { 0 }; // 각 동전의 개수를 저장할 배열
    int remaining_amount = amount; // 남은 금액
    int total_coins = 0; // 총 동전 개수

    // 동전 배열을 순서대로 돌면서 계산합니다.
    for (int i = 0; i < NUM_COINS; ++i) {
        int current_coin = COINS[i];

        if (remaining_amount >= current_coin) {
            // 현재 동전으로 거슬러 줄 수 있는 개수를 계산합니다.
            int count = remaining_amount / current_coin;
            coin_counts[i] = count;
            total_coins += count;

            // 남은 금액을 갱신합니다.
            remaining_amount %= current_coin;
        }
    }

    // 결과를 출력합니다.
    std::cout << amount << "원을 거슬러 주는데 필요한 동전의 개수:" << std::endl;
    for (int i = 0; i < NUM_COINS; ++i) {
        if (coin_counts[i] > 0) {
            std::cout << COINS[i] << "원: " << coin_counts[i] << "개" << std::endl;
        }
    }

    std::cout << "총 동전 개수: " << total_coins << "개" << std::endl;
}

int main() {
    int amount;
    std::cout << "거슬러 줄 금액을 입력하세요: ";
    std::cin >> amount;

    get_change(amount);

    return 0;
}
