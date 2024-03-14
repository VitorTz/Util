#include <random>


int randint(int start, int end);


int randint(int start, int end) {
    // https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c#13445752
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> d(1, end-1); // distribution in range [1, 6]

    return d(rng);
}
