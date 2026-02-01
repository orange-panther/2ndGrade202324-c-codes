/*
 * Übung 10: Ausgabe-Matrix Balkendiagramm
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    15.01.2024
 */

#include <stdio.h>

#define DATA_ROWS 3
#define DATA_COLS 24
#define OUTPUT_ROWS 24
#define OUTPUT_COLS 24

int main()
{
  int data[DATA_ROWS][DATA_COLS] = {
      {8, 12, 18, 5, 11, 1, 4, 13, 16, 2, 9, 6, 0, 7, 15, 3, 14, 10, 19, 17, 1, 3, 2, 4},
      {6, 3, 4, 5, 2, 11, 13, 14, 4, 5, 10, 6, 8, 2, 9, 12, 7, 13, 1, 3, 2, 15, 4, 5},
      {11, 13, 10, 12, 5, 7, 6, 3, 13, 1, 14, 9, 8, 12, 3, 4, 2, 1, 15, 0, 11, 2, 0, 1}};

  char output[OUTPUT_ROWS][OUTPUT_COLS];

  EmptyOutput(output);

  printf("Balkendiagramm:\n");

  for (int i = 0; i < DATA_COLS; i++)
  {
    for (int j = 0; j < data[0][i]; j++)
    {
      output[i][j] = '*';
    }
  }

  for (int i = 0; i < OUTPUT_ROWS; i++)
  {
    for (int j = 0; j < OUTPUT_COLS; j++)
    {
      printf("%c", output[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  EmptyOutput(output);

  printf("Stabdiagramm:\n");

  for (int i = 0; i < DATA_COLS; i++)
  {
    for (int j = 0; j < data[0][i]; j++)
    {
      output[OUTPUT_ROWS - j - 1][i] = '*';
    }
  }

  for (int i = 0; i < OUTPUT_ROWS; i++)
  {
    for (int j = 0; j < OUTPUT_COLS; j++)
    {
      printf("%c", output[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < OUTPUT_ROWS; i++)
  {
    for (int j = 0; j < OUTPUT_COLS; j++)
    {
      output[i][j] = ' ';
    }
  }

  printf("Kurvendiagramm Tag 1:\n");

  for (int i = 0; i < DATA_COLS; i++)
  {
    if (data[0][i] > 0)
    {
      output[OUTPUT_ROWS - data[0][i] - 1][i] = '*';
    }
  }

  for (int i = 0; i < OUTPUT_ROWS; i++)
  {
    for (int j = 0; j < OUTPUT_COLS; j++)
    {
      printf("%c", output[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < OUTPUT_ROWS; i++)
  {
    for (int j = 0; j < OUTPUT_COLS; j++)
    {
      output[i][j] = ' ';
    }
  }

  printf("Kurvendiagramm Tag 2:\n");

  for (int i = 0; i < DATA_COLS; i++)
  {
    if (data[1][i] > 0)
    {
      output[OUTPUT_ROWS - data[1][i] - 1][i] = '*';
    }
  }

  for (int i = 0; i < OUTPUT_ROWS; i++)
  {
    for (int j = 0; j < OUTPUT_COLS; j++)
    {
      printf("%c", output[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < OUTPUT_ROWS; i++)
  {
    for (int j = 0; j < OUTPUT_COLS; j++)
    {
      output[i][j] = ' ';
    }
  }

  printf("Kurvendiagramm Tag 3:\n");

  for (int i = 0; i < DATA_COLS; i++)
  {
    if (data[2][i] > 0)
    {
      output[OUTPUT_ROWS - data[2][i] - 1][i] = '*';
    }
  }

  for (int i = 0; i < OUTPUT_ROWS; i++)
  {
    for (int j = 0; j < OUTPUT_COLS; j++)
    {
      printf("%c", output[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}

int EmptyOutput(int *output[24][24])
{
  for (int i = 0; i < 24; i++)
  {
    for (int j = 0; j < 24; j++)
    {
      output[i][j] = ' ';
    }
  }

  return 0;
}
