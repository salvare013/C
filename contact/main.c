#include "contact.h"

void contact() {
  List *contact = mListCreate(Contact);
  ContactLoad(contact, "./contact.txt");
  int flag;
  do {
    Menu();
    printf("请选择>>>");
    scanf("%d", &flag);
    switch (flag) {
      case EXIT:
        ListDestory(contact);
        printf("退出程序!\n");
        break;
      case ADD:
        ListPushBack(contact, SendData());
        break;
      case DEL:
        ContactDel(contact);
        break;
      case FIND:
        ContactFind(contact);
        break;
      case MODIFY:
        ContactModify(contact);
        break;
      case SHOW:
        ListPrint(contact, PrintContact);
        break;
      case SORT:
        ListSort(contact, CmpName);
        break;
      case SAVE:
        ContactSave(contact, "./contact.txt");
        break;
      default:
        printf("请重新选择!\n");
        break;
    }
  } while (flag);
}
int main(void) {
  contact();

  return 0;
}