//課題1のざっくりY抽出

/* カラー画像(RGB)から白黒化(Y抽出)プログラム rgb2y.cpp */
//#include<stdio.h>
//#include<stdlib.h>
#include "mypgpm.h"

void make_y_image()
/* 原画像 image1_ppm からY抽出して image2 に代入する */
{
  int x, y; /* 制御変数 */

  printf("白黒画像を作成します．\n");
  x_size2 = x_size1; /* 横画素数 */
  y_size2 = y_size1; /* 縦画素数 */
  for (y = 0; y < y_size2; y++) {
    //	       ＿＿＿＿＿＿＿＿＿＿
    for (/*	a	 */ x = 0; x < x_size2; x++) {
      //	      ￣￣￣￣￣￣￣￣￣￣
      //変換式
      image2[y][x] =
          (unsigned char)(image1_ppm[y][x][0] / 3 + image1_ppm[y][x][1] / 3 +
                          image1_ppm[y][x][2] / 3);
      //	 			 ＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿
      /*		  b		   */
      //				￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
    }
  }
}

int main() {
  load_image_data_ppm(); /* 画像データを image1_ppm に読み込む */
  make_y_image();        /* image1_ppm をY変換し image2 へ */
  save_image_data();     /* image2 を保存する */
  return 0;
}