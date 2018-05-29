#include <iostream>

// int fibonacci_sum_squares_naive(long long n) {
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
//         sum += current * current;
//     }
//
//     return sum % 10;
// }

long long get_fibonacci_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}


int fibonacci_sum_squares_fast(long long n) {
    // F(0)^2 + F(1)^2 + ... + F(n)^2 = F(n) * F(n+1)
    // period = 60
    int period = 60;
    long long a = get_fibonacci_fast(n % period);
    long long b = get_fibonacci_fast((n + 1) % period);
    return (a * b) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
