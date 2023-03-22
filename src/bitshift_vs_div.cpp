// #include <time.h>

// #include <iostream>
// using namespace std;

// int main() {
//   clock_t start, end;
//   int x = 1000000000;
//   for (int i = 0; i < 1000; i++) {
//   }
//   cout << "start" << endl;

//   start = clock();
//   for (int i = 0; i < 1000000000; i++) {
//     x /= 2;
//   }
//   end = clock();
//   cout << "/: " << end - start << endl;

//   x = 1000000000;
//   for (int i = 0; i < 1000; i++) {
//   }
//   start = clock();
//   for (int i = 0; i < 1000000000; i++) {
//     x >>= 2;
//   }
//   end = clock();
//   cout << ">>: " << end - start << endl;
// }

#include <stdio.h>
#include <time.h>

int main()
{
    int a = 100, b = 200;
    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < 1000000000; i++) {
        a = a / 2;
        b = b / 2;
    }
    start = clock();
    for (int i = 0; i < 1000000000; i++) {
        a = a / 2;
        b = b / 2;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by division: %f\n", cpu_time_used);

    for (int i = 0; i < 1000000000; i++) {
        a = a << 1;
        b = b << 1;
    }
    start = clock();
    for (int i = 0; i < 1000000000; i++) {
        a = a << 1;
        b = b << 1;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by left shift: %f\n", cpu_time_used);

    return 0; 
}