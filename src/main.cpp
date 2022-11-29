#include <iostream>
#include <vector>
#include <cmath>

#include <benchmark/benchmark.h>
#include <tbb/parallel_for.h>

void BM_FILL_SIN_PARALLEL(benchmark::State &bm) {
    for (auto _ : bm) {
        size_t n = 1 << 26;
        std::vector<double> a(n);

        tbb::parallel_for((size_t)0, (size_t)n, [&](size_t i) {
            a[i] = std::sin(i);
        });
    }
}
BENCHMARK(BM_FILL_SIN_PARALLEL);

void BM_FILL_SIN(benchmark::State &bm) {
    for (auto _ : bm) {
        size_t n = 1 << 26;
        std::vector<double> a(n);

        for (int i = 0; i < n; ++i)
            a[i] = std::sin(i);
    }
}
BENCHMARK(BM_FILL_SIN);

BENCHMARK_MAIN();

// int main() {
//     // std::vector<float> v_ = {0.1f, 0.2f, 0.3f};
//     // int t_ = static_cast<int>(v_.size());
//     // std::cout << t_ << std::endl;

//     Base base(0, "b0");
//     std::cout << base.id() << " : " << base.name() << std::endl;

//     std::cout << sizeof(int) << std::endl;

//     return 0;
// }
