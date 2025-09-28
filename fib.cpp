/*
#include <iostream>

// 재귀 함수로 피보나치 수열을 계산하는 함수
long long fibonacci_recursive(int n) {
    // n이 0이거나 1일 경우, n을 그대로 반환 (종료 조건)
    if (n <= 1) {
        return n;
    }

    // 이전 두 항의 합을 재귀적으로 호출하여 반환
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int num;
    std::cout << "몇 번째 피보나치 항을 구할까요? ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "음수는 입력할 수 없습니다." << std::endl;
    }
    else {
        std::cout << num << "번째 피보나치 항은 " << fibonacci_recursive(num) << "입니다." << std::endl;
    }

    return 0;
}*/
// 재귀 함수를 사용할 시 함수를 호출할 때마다 스택에 메모리 정보 쌓여, 스택 오버플로우 발생 
// 코드의 직관성은 높지만 중복 계산이 많은 경우 적합하지 않음. -> 반복이나 동적 프로그래밍 사용


#include <iostream>

// 반복문으로 피보나치 수열을 계산하는 함수
long long fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }

    long long a = 0; // 0번째 항
    long long b = 1; // 1번째 항
    long long result = 0;

    // 2번째 항부터 n번째 항까지 반복하며 계산
    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

int main() {
    int num;
    std::cout << "몇 번째 피보나치 항을 구할까요? ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "음수는 입력할 수 없습니다." << std::endl;
    }
    else {
        std::cout << num << "번째 피보나치 항은 " << fibonacci_iterative(num) << "입니다." << std::endl;
    }

    return 0;
}

// 결과값에 200과 같이 넣으면 정수 오버클로우 발생 ( 음수값 나옴 ) / long long 은 64비트형 정수형 으로서 대충 93번까지가 한계 . 
// 더 큰 수를 계산하려면 더 큰 수를 다룰 수 있는 방법 필요 
