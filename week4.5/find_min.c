#include <climits>


int main(void) {
    int size = 6;
    int a = 3, b = 6, c = 2, d = 4, e = 0, f = 8;
    int *array[6] = {&a, &b, &c, &d, &e, &f};


}

int *min(int *array, int size) {
    int *min = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}
