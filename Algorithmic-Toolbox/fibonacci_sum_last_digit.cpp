#include <iostream>

// int fibonacci_sum_naive(long long n) {
//     if (n <= 1)
//         return n;
//
//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;
//
//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current;
//     }
//
//     return sum % 10;
// }


int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum = (sum + current) % 10;
    }

    return sum;
}


int fibonacci_sum_huge(long long n) {
    if (n <= 1)
        return n;

    int period = 0;
    int previous = 0;
    int current = 1;
    int sum = 0;

    for (long long i = 0; i < n - 1; ++i) {
        sum = (sum + current) % 10;
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;

        if (previous == 0 && current == 1) {
            period = i + 1;
            break;
        }
    }
    if (period == 0) return fibonacci_sum_fast(n);
    return ((n * sum  / period) % 10 + fibonacci_sum_fast(n % period)) % 10;
}

int fibonacci_sum_huge_simplify(long long n) {
    // period = 60 and F0 + F1 + ... + F59 = 0
    int period = 60;
    return fibonacci_sum_fast(n % period) % 10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_huge_simplify(n);
}
