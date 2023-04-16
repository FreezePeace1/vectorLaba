#include "vectors.h"

void outputVector(vector vector) {
    for(int i = 0; i < vector.size; i++) {
        printf("%d ", vector.data[i]);
    }
}

void test_pushBack_emptyVector(vector *vector) {
    for(int i = 1; i < 6; i++) {
        pushBack(vector, i);
    }
}

void test_pushBack_fullVector(vector *vector) {
    for(int i = 6; i < 11; i++) {
        pushBack(vector, i);
    }
}

void test_popBack_notEmptyVector(vector *vector) {
    for(int i = 0; i < 5; i++) {
        popBack(vector);
    }
}

void test_everything(vector *vector) {
    test_pushBack_emptyVector(vector);
    test_pushBack_fullVector(vector);
    test_popBack_notEmptyVector(vector);
}

int main() {
    vector vector = createVector(4);

    test_everything(&vector);

    outputVector(vector);

    deleteVector(&vector);

    return 0;
}