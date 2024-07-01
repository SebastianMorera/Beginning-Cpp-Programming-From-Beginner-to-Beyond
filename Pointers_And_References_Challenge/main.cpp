#include <iostream>

using namespace std;

int* apply_all(const int *array1, int array1_size, const int *array2, int array2_size);
void print(const int *array, int array_size);

int main() {
    constexpr size_t array1_size {5};
    constexpr size_t array2_size {3};

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    cout << "Array 1: " ;
    print(array1,array1_size);

    cout << "Array 2: " ;
    print(array2,array2_size);

    const int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);

    cout << endl;
    delete [] results;
    return 0;
}

void print(const int *array, const int array_size)
{
    cout << "[";
    for(size_t i{0}; i < array_size; i++)
        cout << array[i] << " ";
    cout << "]" << endl;
}

int* apply_all(const int *array1, const int array1_size, const int *array2, const int array2_size)
{
    int* result {};
    result = new int[array1_size * array2_size];
    size_t index {0};
    for(size_t i {0}; i < array1_size; i++)
        for(size_t j {0}; j < array2_size; j++)
        {
            result[index] = array1[i]*array2[j];
            index++;
        }

    return result;
}