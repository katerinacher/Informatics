#include <iostream>

void prog(float** M, int n, int j) {
  float differ = 0;

  float max = **(M + j);
  float min = **(M + j);
  for (int i = 0; i < n; i++) {
    if (*(*(M + i) + j) > max) {
      max = *(*(M + i) + j);
    }
    if (*(*(M + i) + j) < min) {
      min = *(*(M + i) + j);
    }
  }
  printf("\n������������ ������� j-��� �������: %4.2f\n", max);
  printf("����������� ������� j-��� �������: %4.2f\n", min);
  differ = max - min;
  printf("������� ������������� � ������������ ��������� j-��� �������: %4.2f\n", differ);
  *(*(M + j) + j) = differ;
}