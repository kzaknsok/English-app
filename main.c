#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <emscripten.h>

// JavaScript から呼び出せるように export 指定
EMSCRIPTEN_KEEPALIVE
void init_rand() {
    srand((unsigned int)time(NULL));
}

// 選択肢のシャッフル関数（C言語のロジック）
EMSCRIPTEN_KEEPALIVE
void shuffle_indices(int *array, int n) {
    if (n <= 1) return;
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// ランダムな問題インデックスの取得
EMSCRIPTEN_KEEPALIVE
int get_random_index(int total_count) {
    if (total_count <= 0) return 0;
    return rand() % total_count;
}