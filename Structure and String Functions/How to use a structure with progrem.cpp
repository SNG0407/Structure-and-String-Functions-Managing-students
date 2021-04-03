#include <iostream>
#include <fstream>

using namespace std;

// define으로 각 배열의 크기를 정해주자.
#define NAME_SIZE       32
#define ADDRESS_SIZE    128
#define PHONE_SIZE      14 //000-0000-0000
#define STUDENT_MAX     3 

struct _tagStudent { // 총 56byte를 먼저 잡고 그걸 분할해서 배열 처럼 쓰는 거임
    char strName[NAME_SIZE];// = {}; //string 1개당 1byte // 32개 32byte
    char strAddress[ADDRESS_SIZE];
    char strPhoneNumber[PHONE_SIZE];
    int iNumber; //int 개당 4 byte
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvg;
    float iE; // float 개당 4byte
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
    // 배열에 추가된 개수를 저장할 변수를 만들어준다.
    int iStudentCount = 0;
    int iStdNumber = 1;
    char strName[NAME_SIZE] = {};

    ofstream outToTxt("Profiles of students.txt");
    while (true) {
        system("cls");

        //메뉴 출력
        cout << "1. 학생등록" << endl;
        cout << "2. 학생삭제" << endl;
        cout << "3. 학생탐색" << endl;
        cout << "4. 학생출력" << endl;
        cout << "5. 종료" << endl;
        cout << "메뉴를 선택하세요 : ";
        int iMenu;
        cin >> iMenu;

        /* cin은 int 변수를 받기로 했으면 변수 타입에 맞춰 값을 입력해야 됨
        다른 문자를 입력하면 에러가 발생. 그 경우를 예외처리해서 에러 발생시
        cin 내부의 에러 버퍼를 비우고 cin 내부 입력 버퍼에 입력한 값을 저장하고
        그 값을 변수에 넣어주는 역할을 함. 이 입력버퍼에 \n이 남아있으니
        버퍼를 순회하여 지워준다.*/

        //1. 에러 체크 : cin.fail()을 했을 때 입력 에러가 발생하면 true를 반환함
        if (cin.fail()) {
            //에러 버퍼를 비워준다.
            cin.clear();

            //입력버퍼에 \n이 남아있으므로 입력버퍼를 검색하여 \n을 지워준다.
            //1. 검색하고자 하는 버퍼 크기를 지정 // 넉넉하게 1024함
            //2. 찾고자 하는 문자를 넣어준다. 
            //3. 처음부터 \n이 있는 곳까지 찾아서 그 부분 모두 지워주고 다시 입력받게 하기
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
            cout << "------------학생 추가------------" << endl;

            // 등록된 학생이 등록할 수 있는 최대치 일 경우 더이상 등록 안되게 막기
            if (iStdNumber == STUDENT_MAX+1) //STUDENT_MAX로 하면 최대 10명이라고 해놓고 9명까지 밖에 못 받음
                break;


            //학생정보 추가시 학생정보는 이름, 주소, 폰 번호
            //국어, 영어, 수학 점수는 입력받고 학번, 총점, 평균은 연산을 통해 계산
            // 이름 입력받기
            cout << "이름 : ";
            cin >> tStudentArr[iStudentCount].strName;

            cin.ignore(1024, '\n');
            cout << "주소 : ";
            cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);
            //cin만 하게되면 스페이스바도 입력의 끝으로 받아 들여버려
            //cin.getline은 입력받고자 하는 변수 + 입력 받을  최대 수치
            cout << tStudentArr[iStudentCount].strAddress<< endl;

            cout << "전화번호 : ";
            cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

            cout << "국어 : ";
            cin >> tStudentArr[iStudentCount].iKor;
            cout << "영어 : ";
            cin >> tStudentArr[iStudentCount].iEng;
            cout << "수학 : ";
            cin >> tStudentArr[iStudentCount].iMath;

            tStudentArr[iStudentCount].iTotal =
                tStudentArr[iStudentCount].iKor +
                tStudentArr[iStudentCount].iEng +
                tStudentArr[iStudentCount].iMath;
            tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.f;
            tStudentArr[iStudentCount].iNumber = iStdNumber;
            ++iStudentCount;
            ++iStdNumber;

            cout << "학생 추가 완료" << endl;

            break;  
        case    MENU_DELETE:
            system("cls");


            cout << "------------학생 삭제------------" << endl;

            cin.ignore(1024, '\n');
            cout << "삭제할 이름을 입력하세요 : ";
            cin.getline(strName, NAME_SIZE);

            //등록된 학생 수 만큼 반복하여 학생 찾기
            for (int i = 0; i < iStudentCount; i++) {

                //학생을 찾았을 경우
                // 총 학생이 7명 있고, i = 2인 경우 j는 2부터 7-1=6 미만 까지 
                //즉 j = 2,3,4,5     a[2]=a[3], a[3] =a[4], a[4]=a[5], a[5] = a[6]
                if (strcmp(tStudentArr[i].strName, strName) == 0) {
                    for (int j = i; j < iStudentCount - 1; j++) {
                        tStudentArr[j] = tStudentArr[j + 1];
                    }
                    -- iStudentCount;
                }
                cout << "학생을 삭제하였습니다." << endl;
            }

            break;
        case      MENU_OUTPUT:
            system("cls");
            cout << "------------학생 출력------------" << endl;
            
            //등록된 학생 수만큼 반복하여  학생정보 출력
            for (int i = 0; i < iStudentCount; i++) {
                cout << "이름 : " << tStudentArr[i].strName << endl;
                cout << "전화번후 : " << tStudentArr[i].strPhoneNumber << endl;
                cout << "주소 : " << tStudentArr[i].strAddress << endl;
                cout << "학번 : " << tStudentArr[i].iNumber << endl;
                cout << "국어 : " << tStudentArr[i].iKor << endl;
                cout << "영어 : " << tStudentArr[i].iEng << endl;
                cout << "수학 : " << tStudentArr[i].iMath << endl;
                cout << "총점 : " << tStudentArr[i].iTotal << endl;
                cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
            }
          
            for (int i = 0; i < iStudentCount; i++) {
                outToTxt << "이름 : " << tStudentArr[i].strName << endl;
                outToTxt << "전화번후 : " << tStudentArr[i].strPhoneNumber << endl;
                outToTxt << "주소 : " << tStudentArr[i].strAddress << endl;
                outToTxt << "학번 : " << tStudentArr[i].iNumber << endl;
                outToTxt << "국어 : " << tStudentArr[i].iKor << endl;
                outToTxt << "영어 : " << tStudentArr[i].iEng << endl;
                outToTxt << "수학 : " << tStudentArr[i].iMath << endl;
                outToTxt << "총점 : " << tStudentArr[i].iTotal << endl;
                outToTxt << "평균 : " << tStudentArr[i].fAvg << endl << endl;
            }
            outToTxt.close();

            break;
        case MENU_SEARCH:
            system("cls");

            
            cout << "------------학생 탐색------------" << endl;

            cin.ignore(1024, '\n');
            cout << "탐색할 이름을 입력하세요 : ";
            cin.getline(strName, NAME_SIZE);

            //등록된 학생 수 만큼 반복하여 학생 찾기
            for (int i = 0; i < iStudentCount; i++) {

                //학생을 찾았을 때
                if (strcmp(tStudentArr[i].strName, strName) == 0) {
                    cout<< "이름 : " << tStudentArr[i].strName << endl;
                    cout << "전화번후 : " << tStudentArr[i].strPhoneNumber << endl;
                    cout << "주소 : " << tStudentArr[i].strAddress << endl;
                    cout << "학번 : " << tStudentArr[i].iNumber << endl;
                    cout << "국어 : " << tStudentArr[i].iKor << endl;
                    cout << "영어 : " << tStudentArr[i].iEng << endl;
                    cout << "수학 : " << tStudentArr[i].iMath << endl;
                    cout << "총점 : " << tStudentArr[i].iTotal << endl;
                    cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
                    break;
                }
            }


            break;   
        default:
            cout << "메뉴를 잘못 선택했습니다." << endl;
            break;
        }
        system("pause");
    }

	return 0;
}