#include <stdio.h>

int main() {

  // границы поля
  int height = 25;
  int width = 79;

  // стартовые координаты ракеток
  int rocket_1_Y = height / 2;
  int rocket_2_Y = rocket_1_Y;

  // стартовые координаты мяча
  int ball_Y = height / 2;
  int ball_X = width / 2;

  // направление в зависимостри от знака и скорость мяча
  int velocity_x = 1;
  int velocity_y = 1;

  // управление
  char in;

  // счет
  int score_Player_1 = 0;
  int score_Player_2 = 0;

  // управление ракетками Aa/Zz Kk/Mm
  while (1) {

    scanf("%c", &in);
    if (((in == 'A') || (in == 'a')) && (rocket_1_Y != 24))
      rocket_1_Y++;
    else if (((in == 'Z') || (in == 'z')) && (rocket_1_Y != 2))
      rocket_1_Y--;
    else if (((in == 'K') || (in == 'k')) && (rocket_2_Y != 24))
      rocket_2_Y++;
    else if (((in == 'M') || (in == 'm')) && (rocket_2_Y != 2))
      rocket_2_Y--;

    // координаты всей ракетки1
    int pixel1_rocket1 = rocket_1_Y - 1;
    int pixel2_rocket1 = rocket_1_Y;
    int pixel3_rocket1 = rocket_1_Y + 1;
    int pixelX_rocket1 = 0;

    // координаты всей ракетки2
    int pixel1_rocket2 = rocket_2_Y - 1;
    int pixel2_rocket2 = rocket_2_Y;
    int pixel3_rocket2 = rocket_2_Y + 1;
    int pixelX_rocket2 = width;

    // координаты мяча при передвижении
    int new_ball_Y = ball_Y + velocity_y;
    int new_ball_X = ball_X + velocity_x;

    // отбивание мяча ракеткой 1
    if (new_ball_X == pixelX_rocket1) {
      if ((new_ball_Y == pixel1_rocket1) || (new_ball_Y == pixel2_rocket1) ||
          (new_ball_Y == pixel3_rocket1))
        velocity_x = -velocity_x;

      else {
        score_Player_2++;
        //  сброс позиции при голе
        ball_Y = height / 2;
        ball_X = width / 2;
        rocket_1_Y = height / 2;
        velocity_x = -velocity_x;
        velocity_y = -velocity_y;
      }
    }

    // отбивание мяча ракеткой 2
    if (new_ball_X == pixelX_rocket2) {
      if ((new_ball_Y == pixel1_rocket2) || (new_ball_Y == pixel2_rocket2) ||
          (new_ball_Y == pixel3_rocket2))
        velocity_x = -velocity_x;

      else {
        score_Player_1++;
        //  сброс позиции при голе
        ball_Y = height / 2;
        ball_X = width / 2;
        rocket_2_Y = height / 2;
        velocity_x = -velocity_x;
        velocity_y = -velocity_y;
      }
    }

    // отскок от границ верха/низа
    if ((new_ball_Y == 0) || (new_ball_Y == height + 1))
      velocity_y = -velocity_y;

    // движение мяча
    ball_X += velocity_x;
    ball_Y += velocity_y;

    // условие победы
    if (score_Player_1 == 21) {
      printf("Первый игрок победил!\n");
      return 0;
    }
    if (score_Player_2 == 21) {
      printf("Второй игрок победил!\n");
      return 0;
    }

    // отрисовка потолка
    if ((score_Player_1 < 10) && (score_Player_2 < 10)) {
      for (int x = 0; x < width - 6; x++) {
        if (x == 0)
          printf("%d", score_Player_1);
        printf("-");
        if (x == width - 7)
          printf("%d", score_Player_2);
        if (x == 35)
          printf("SCORE");
      }
    } else if ((score_Player_1 >= 10) && (score_Player_2 < 10)) {
      for (int x = 0; x < width - 7; x++) {
        if (x == 0)
          printf("%d", score_Player_1);
        printf("-");
        if (x == width - 8)
          printf("%d", score_Player_2);
        if (x == 34)
          printf("SCORE");
      }
    } else if ((score_Player_1 < 10) && (score_Player_2 >= 10)) {
      for (int x = 0; x < width - 7; x++) {
        if (x == 0)
          printf("%d", score_Player_1);
        printf("-");
        if (x == width - 8)
          printf("%d", score_Player_2);
        if (x == 35)
          printf("SCORE");
      }
    } else if ((score_Player_1 >= 10) && (score_Player_2 >= 10)) {
      for (int x = 0; x < width - 8; x++) {
        if (x == 0)
          printf("%d", score_Player_1);
        printf("-");
        if (x == width - 9)
          printf("%d", score_Player_2);
        if (x == 34)
          printf("SCORE");
      }
    }
    printf("\n");

    // отрисовка поля и элементов
    for (int y = height; y > 0; y--) {
      for (int x = 0; x < width + 1; x++) {
        // отрисовка ракетки1
        if ((y == pixel1_rocket1 || y == pixel2_rocket1 ||
             y == pixel3_rocket1) &&
            x == pixelX_rocket1) {
          printf("|");
          continue;
        }

        // отрисовка ракетки2
        if ((y == pixel1_rocket2 || y == pixel2_rocket2 ||
             y == pixel3_rocket2) &&
            x == pixelX_rocket2) {
          printf("|");
          continue;
        }
        // отрисовка мяча
        if (y == ball_Y && x == ball_X) {
          printf("o");
          continue;
        }
        // отрисовка центра
        if (x == width / 2) {
          printf("|");
          continue;
        }

        printf(" ");
      }

      printf("\n");
    }
    if ((score_Player_1 < 22) && (score_Player_2 < 22)) {
      for (int x = 0; x < width - 1; x++)
        printf("-");
    }
    printf("\n");
  }
}
