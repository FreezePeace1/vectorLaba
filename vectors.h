#ifndef VECTORS_VECTORS_H
#define VECTORS_VECTORS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data;
    int size;
    int capacity;
} vector;

vector createVector(int n) {
    if(n < __SIZE_MAX__) {
        vector *vector;
        vector->data = (int *)malloc(n * sizeof(int));
        vector->size = 0;
        vector->capacity = n;
        return *vector;
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void reserve(vector *vector, int newCapacity) {
    if(newCapacity >= __SIZE_MAX__) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity < vector->size)  {
        vector->data = (int *) realloc(vector->data, sizeof(int) * newCapacity);
        vector->size = newCapacity;
        vector->capacity = newCapacity;
    } else if (newCapacity == 0) {
        vector->data = NULL;
        vector->size = 0;
        vector->capacity = 0;
    } else {
        vector->data = (int*) realloc(vector->data, sizeof(int) * newCapacity);
        vector->capacity = newCapacity;
    }
}

void clear(vector *vector) {
    vector->size = 0;
}

void shrinkToFit(vector *vector) {
    vector->capacity = vector->size;
}

void deleteVector(vector *vector) {
    free(vector);
}

bool isEmpty(vector *vector) {
    return vector->size == 0 ? true : false;
}

bool isFull(vector *vector) {
    return vector->size == vector->capacity ? true : false;
}

int getVectorValue(vector *vector, int i) {
    return vector->data[i];
}

void pushBack(vector *vector, int x) {
    if(vector->capacity == vector->size) {
        reserve(vector, vector->capacity * 2);
    }
    vector->data[vector->size] = x;
    vector->size++;
}

void popBack(vector *vector) {
    if(vector->size == 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    vector->size--;
}

#endif //VECTORS_VECTORS_H
