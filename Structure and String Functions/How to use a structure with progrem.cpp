#include <iostream>
#include <fstream>

using namespace std;

// define���� �� �迭�� ũ�⸦ ��������.
#define NAME_SIZE       32
#define ADDRESS_SIZE    128
#define PHONE_SIZE      14 //000-0000-0000
#define STUDENT_MAX     3 

struct _tagStudent { // �� 56byte�� ���� ��� �װ� �����ؼ� �迭 ó�� ���� ����
    char strName[NAME_SIZE];// = {}; //string 1���� 1byte // 32�� 32byte
    char strAddress[ADDRESS_SIZE];
    char strPhoneNumber[PHONE_SIZE];
    int iNumber; //int ���� 4 byte
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvg;
    float iE; // float ���� 4byte
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
    int iStdNumber = 1;
    char strName[NAME_SIZE] = {};

    ofstream outToTxt("Profiles of students.txt");
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
            system("cls");
            cout << "------------�л� �߰�------------" << endl;

            // ��ϵ� �л��� ����� �� �ִ� �ִ�ġ �� ��� ���̻� ��� �ȵǰ� ����
            if (iStdNumber == STUDENT_MAX+1) //STUDENT_MAX�� �ϸ� �ִ� 10���̶�� �س��� 9����� �ۿ� �� ����
                break;


            //�л����� �߰��� �л������� �̸�, �ּ�, �� ��ȣ
            //����, ����, ���� ������ �Է¹ް� �й�, ����, ����� ������ ���� ���
            // �̸� �Է¹ޱ�
            cout << "�̸� : ";
            cin >> tStudentArr[iStudentCount].strName;

            cin.ignore(1024, '\n');
            cout << "�ּ� : ";
            cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);
            //cin�� �ϰԵǸ� �����̽��ٵ� �Է��� ������ �޾� �鿩����
            //cin.getline�� �Է¹ް��� �ϴ� ���� + �Է� ����  �ִ� ��ġ
            cout << tStudentArr[iStudentCount].strAddress<< endl;

            cout << "��ȭ��ȣ : ";
            cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

            cout << "���� : ";
            cin >> tStudentArr[iStudentCount].iKor;
            cout << "���� : ";
            cin >> tStudentArr[iStudentCount].iEng;
            cout << "���� : ";
            cin >> tStudentArr[iStudentCount].iMath;

            tStudentArr[iStudentCount].iTotal =
                tStudentArr[iStudentCount].iKor +
                tStudentArr[iStudentCount].iEng +
                tStudentArr[iStudentCount].iMath;
            tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.f;
            tStudentArr[iStudentCount].iNumber = iStdNumber;
            ++iStudentCount;
            ++iStdNumber;

            cout << "�л� �߰� �Ϸ�" << endl;

            break;  
        case    MENU_DELETE:
            system("cls");


            cout << "------------�л� ����------------" << endl;

            cin.ignore(1024, '\n');
            cout << "������ �̸��� �Է��ϼ��� : ";
            cin.getline(strName, NAME_SIZE);

            //��ϵ� �л� �� ��ŭ �ݺ��Ͽ� �л� ã��
            for (int i = 0; i < iStudentCount; i++) {

                //�л��� ã���� ���
                // �� �л��� 7�� �ְ�, i = 2�� ��� j�� 2���� 7-1=6 �̸� ���� 
                //�� j = 2,3,4,5     a[2]=a[3], a[3] =a[4], a[4]=a[5], a[5] = a[6]
                if (strcmp(tStudentArr[i].strName, strName) == 0) {
                    for (int j = i; j < iStudentCount - 1; j++) {
                        tStudentArr[j] = tStudentArr[j + 1];
                    }
                    -- iStudentCount;
                }
                cout << "�л��� �����Ͽ����ϴ�." << endl;
            }

            break;
        case      MENU_OUTPUT:
            system("cls");
            cout << "------------�л� ���------------" << endl;
            
            //��ϵ� �л� ����ŭ �ݺ��Ͽ�  �л����� ���
            for (int i = 0; i < iStudentCount; i++) {
                cout << "�̸� : " << tStudentArr[i].strName << endl;
                cout << "��ȭ���� : " << tStudentArr[i].strPhoneNumber << endl;
                cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
                cout << "�й� : " << tStudentArr[i].iNumber << endl;
                cout << "���� : " << tStudentArr[i].iKor << endl;
                cout << "���� : " << tStudentArr[i].iEng << endl;
                cout << "���� : " << tStudentArr[i].iMath << endl;
                cout << "���� : " << tStudentArr[i].iTotal << endl;
                cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
            }
          
            for (int i = 0; i < iStudentCount; i++) {
                outToTxt << "�̸� : " << tStudentArr[i].strName << endl;
                outToTxt << "��ȭ���� : " << tStudentArr[i].strPhoneNumber << endl;
                outToTxt << "�ּ� : " << tStudentArr[i].strAddress << endl;
                outToTxt << "�й� : " << tStudentArr[i].iNumber << endl;
                outToTxt << "���� : " << tStudentArr[i].iKor << endl;
                outToTxt << "���� : " << tStudentArr[i].iEng << endl;
                outToTxt << "���� : " << tStudentArr[i].iMath << endl;
                outToTxt << "���� : " << tStudentArr[i].iTotal << endl;
                outToTxt << "��� : " << tStudentArr[i].fAvg << endl << endl;
            }
            outToTxt.close();

            break;
        case MENU_SEARCH:
            system("cls");

            
            cout << "------------�л� Ž��------------" << endl;

            cin.ignore(1024, '\n');
            cout << "Ž���� �̸��� �Է��ϼ��� : ";
            cin.getline(strName, NAME_SIZE);

            //��ϵ� �л� �� ��ŭ �ݺ��Ͽ� �л� ã��
            for (int i = 0; i < iStudentCount; i++) {

                //�л��� ã���� ��
                if (strcmp(tStudentArr[i].strName, strName) == 0) {
                    cout<< "�̸� : " << tStudentArr[i].strName << endl;
                    cout << "��ȭ���� : " << tStudentArr[i].strPhoneNumber << endl;
                    cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
                    cout << "�й� : " << tStudentArr[i].iNumber << endl;
                    cout << "���� : " << tStudentArr[i].iKor << endl;
                    cout << "���� : " << tStudentArr[i].iEng << endl;
                    cout << "���� : " << tStudentArr[i].iMath << endl;
                    cout << "���� : " << tStudentArr[i].iTotal << endl;
                    cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
                    break;
                }
            }


            break;   
        default:
            cout << "�޴��� �߸� �����߽��ϴ�." << endl;
            break;
        }
        system("pause");
    }

	return 0;
}