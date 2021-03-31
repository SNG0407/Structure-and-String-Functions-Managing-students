#include <iostream>

using namespace std;

#define NAME_SIZE       32
#define ADDRESS_SIZE    128
#define PHONE_SIZE      14
#define STUDENT_MAX     10

struct _tagStudent { // �� 56bite�� ���� ��� �װ� �����ؼ� �迭 ó�� ���� ����
    char strName[NAME_SIZE];// = {}; //string 1���� 1bite // 32�� 32bite
    char strAddress[ADDRESS_SIZE];
    char strPhoneNumber[PHONE_SIZE];
    int iNumber; //int ���� 4 bite
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    int fAvg;
    float iE; // float ���� 4bite
};

enum MENU {
    MENU_NONE,
    MENU_INSERT,
    MENU_DELETE,
    MENU_SEARCH,
    MENU_OUTPUT,
    MENU_EXIT
};

int main() {
    _tagStudent tStudentArr[STUDENT_MAX] = {};
    // �迭�� �߰��� ������ ������ ������ ������ش�.
    int iStudentCount = 0;

    while (true) {
        system("cls");

        //�޴� ���
        cout << "1. �л����" << endl;
        cout << "2. �л�����" << endl;
        cout << "3. �л�Ž��" << endl;
        cout << "4. �л����" << endl;
        cout << "5. ����" << endl;
        cout << "�޴��� �����ϼ��� : ";
        int iMenu;
        cin >> iMenu;

        /* cin�� int ������ �ޱ�� ������ ���� Ÿ�Կ� ���� ���� �Է��ؾ� ��
        �ٸ� ���ڸ� �Է��ϸ� ������ �߻�. �� ��츦 ����ó���ؼ� ���� �߻���
        cin ������ ���� ���۸� ���� cin ���� �Է� ���ۿ� �Է��� ���� �����ϰ�
        �� ���� ������ �־��ִ� ������ ��. �� �Է¹��ۿ� \n�� ����������
        ���۸� ��ȸ�Ͽ� �����ش�.*/

        //1. ���� üũ : cin.fail()�� ���� �� �Է� ������ �߻��ϸ� true�� ��ȯ��
        if (cin.fail()) {
            //���� ���۸� ����ش�.
            cin.clear();

            //�Է¹��ۿ� \n�� ���������Ƿ� �Է¹��۸� �˻��Ͽ� \n�� �����ش�.
            //1. �˻��ϰ��� �ϴ� ���� ũ�⸦ ���� // �˳��ϰ� 1024��
            //2. ã���� �ϴ� ���ڸ� �־��ش�. 
            //3. ó������ \n�� �ִ� ������ ã�Ƽ� �� �κ� ��� �����ְ� �ٽ� �Է¹ް� �ϱ�
            cin.ignore(1024, '\n');
            continue;
        }


        if (iMenu == MENU_EXIT) {
            break;
        }
        switch (iMenu) {
        case MENU_NONE:
            break;

        case    MENU_INSERT:
            //�л����� �߰��� �л������� �̸�, �ּ�, �� ��ȣ
            //����, ����, ���� ������ �Է¹ް� �й�, ����, ����� ������ ���� ���

            break;  
        case    MENU_DELETE:
            break;
        case      MENU_OUTPUT:
            break;
        case MENU_SEARCH:
            break;   
        default:
            cout << "�޴��� �߸� �����߽��ϴ�." << endl;
            break;
        }
        system("pause");
    }

	return 0;
}