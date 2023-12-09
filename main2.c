#include <stdio.h>
#include <pthread.h>

void rust_global_set(int value);
int rust_global_get();

void* thread_func(void* arg) {
    int value = (int)(arg);
    rust_global_set(value);
    printf("Thread set value to %d, get value: %d\n", value, rust_global_get());
    return NULL;
}

int main() {
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)(i + 1));
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
