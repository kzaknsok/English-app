#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
void init_rand() {
    srand((unsigned int)time(NULL));
}

// 配列のシャッフル（JavaScript側のInt32Arrayを直接操作）
EMSCRIPTEN_KEEPALIVE
void shuffle_array(int *arr, int size) {
    if (size <= 1) return;
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// ランダムなインデックスを取得
EMSCRIPTEN_KEEPALIVE
int get_random_index(int total_count) {
    if (total_count <= 0) return 0;
    return rand() % total_count;
}