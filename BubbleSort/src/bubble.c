#include <bubble.h>

void PrintStu(Stu stu[], int size) {
  for (int i = 0; i < size; i++) {
    printf("name:%s\tage:%d\theight:%d\tweight:%.1f\n", stu[i].name, stu[i].age,
           stu[i].height, stu[i].weight);
  }
  printf("\n");
}
int CmpInt(const void* e1, const void* e2) {
  return CMP_VOID_NUM(e1, e2, int);
}
int CmpFloat(const void* e1, const void* e2) {
  return CMP_VOID_NUM(e1, e2, float);
}
int CmpStuAge(const void* e1, const void* e2) {
  return ((Stu*)e1)->age - ((Stu*)e2)->age;
}
int CmpStuName(const void* e1, const void* e2) {
  return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);
}
void Swap(char* buf1, char* buf2, int width) {
  for (int i = 0; i < width; i++) {
    char tmp = *buf1;
    *buf1 = *buf2;
    *buf2 = tmp;
    buf1++;
    buf2++;
  }
}
void BubbleSort(void* start,
                int count,
                int width,
                int (*pCmpF)(const void*, const void*)) {
  int flag = 1;
  for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count - 1 - i; j++) {
      if (pCmpF((char*)start + j * width, (char*)start + (j + 1) * width) > 0) {
        Swap((char*)start + j * width, (char*)start + (j + 1) * width, width);
        flag = 0;
      }
    }
    if (flag == 1) {
      break;
    }
  }
}
