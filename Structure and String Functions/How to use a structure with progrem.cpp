#include <iostream>

using namespace std;

#define NAME_SIZE       32
#define ADDRESS_SIZE    128
#define PHONE_SIZE      14
#define STUDENT_MAX     10

struct _tagStudent { // 총 56bite를 먼저 잡고 그걸 분할해서 배열 처럼 쓰는 거임
    char strName[NAME_SIZE];// = {}; //string 1개당 1bite // 32개 32bite
    char strAddress[ADDRESS_SIZE];
    char strPhoneNumber[PHONE_SIZE];
    int iNumber; //int 개당 4 bite
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    int fAvg;
    float iE; // float 개당 4bite
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
            //학생정보 추가시 학생정보는 이름, 주소, 폰 번호
            //국어, 영어, 수학 점수는 입력받고 학번, 총점, 평균은 연산을 통해 계산

            break;  
        case    MENU_DELETE:
            break;
        case      MENU_OUTPUT:
            break;
        case MENU_SEARCH:
            break;   
        default:
            cout << "메뉴를 잘못 선택했습니다." << endl;
            break;
        }
        system("pause");
    }

	return 0;
}