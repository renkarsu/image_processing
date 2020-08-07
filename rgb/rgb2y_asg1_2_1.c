// 実験1の課題2(i)の、ガチのYUV

/* カラー画像(RGB)から白黒化(Y抽出)プログラム rgb2y.cpp */
//#include<stdio.h>
//#include<stdlib.h>
#include "mypgpm.h"

void make_y_image()
/* 原画像 image1_ppm からY抽出して image2 に代入する */
{
  int x, y; /* 制御変数 */

  double Y = 0.0;
  double U = 0.0;
  double V = 0.0;

  printf("白黒画像を作成します．\n");
  x_size2 = x_size1; /* 横画素数 */
  y_size2 = y_size1; /* 縦画素数 */
  for (y = 0; y < y_size2; y++) {
    for (x = 0; x < x_size2; x++) {
      Y = (image1_ppm[y][x][0] * 0.299 + image1_ppm[y][x][1] * 0.587 +
           image1_ppm[y][x][2] * 0.114);
      U = (-image1_ppm[y][x][0] * 0.169 - image1_ppm[y][x][1] * 0.332 +
           image1_ppm[y][x][2] * 0.500);
      V = (image1_ppm[y][x][0] * 0.500 - image1_ppm[y][x][1] * 0.419 -
           image1_ppm[y][x][2] * 0.081);

      image2_ppm[y][x][0] = (unsigned char)(Y + 1.402 * V);
      image2_ppm[y][x][1] = (unsigned char)(Y - 0.344 * U - V * 0.714);
      image2_ppm[y][x][2] = (unsigned char)(Y + U * 1.772);
    }
  }
}

int main() {
  load_image_data_ppm(); /* 画像データを image1_ppm に読み込む */
  make_y_image();        /* image1_ppm をY変換し image2 へ */
  save_image_data_ppm();     /* image2 を保存する */
  return 0;
}