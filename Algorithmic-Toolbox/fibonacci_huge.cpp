#include <iostream>

// long long get_fibonacci_huge_naive(long long n, long long m) {
//     if (n <= 1)
//         return n;
//
//     long long previous = 0;
//     long long current  = 1;
//
//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }
//
//     return current % m;
// }


long long get_fibonacci_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;
    
    long long previous = 0;
    long long current  = 1;
    int period = 0;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        if (previous == 0 && current == 1) {
            period = i + 1;
            break;
        }
    }
    if (period == 0) return current;
    return get_fibonacci_fast(n % period, m);
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
