#include <iostream>
#include <vector>
using std::vector;

// long long get_fibonacci_partial_sum_naive(long long from, long long to) {
//     long long sum = 0;
//
//     long long current = 0;
//     long long next  = 1;
//
//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum += current;
//         }
//
//         long long new_current = next;
//         next = next + current;
//         current = new_current;
//     }
//
//     return sum % 10;
// }


// int get_fibonacci_partial_sum_fast(long long from, long long to) {
//     //time linmited out
//     int sum = 0;
//
//     int current = 0;
//     int next  = 1;
//
//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum = (sum + current) % 10;
//         }
//
//         int new_current = next;
//         next = (next + current) % 10;
//         current = new_current % 10;
//     }
//
//     return sum;
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

int get_fibonacci_partial_sum_fast(long long from, long long to) {
    // period : 60;
    // F0 + F1 + ... + F59 = 0
    int period = 60;
    int sum_from = 0;
    //int sum_to = 0;
    if (from > 0) sum_from = fibonacci_sum_fast((from - 1 ) % period) % 10;
    int sum_to = fibonacci_sum_fast(to % period) % 10;
    if (sum_to >= sum_from) {
        return sum_to - sum_from;
    }
    else {
        return sum_to + 10 - sum_from;
    }
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
