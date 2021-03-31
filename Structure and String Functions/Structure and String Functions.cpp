#include <iostream>

using namespace std;

#define NAME_SIZE 32

/*
//구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능
//사용자 정의 변수 타입이다.
//형태 : struct 구조체 명{}; 의 형태로 구성된다.
//배열과 구조체의 공통점 : 
1. 데이터 집합이다.
2. 연속된 메모리 블럭에 할당된다. 구조체 멤버들은 연속된 메모리 블럭으로 잡히게 됨.
*/

struct _tagStudent { // 총 56bite를 먼저 잡고 그걸 분할해서 배열 처럼 쓰는 거임
    char strName[NAME_SIZE];// = {}; //string 1개당 1bite // 32개 32bite
    int iNumber; //int 개당 4 bite
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float iE; // float 개당 4bite
};

int main()
{
    _tagStudent tStudent;// = {}; //초기화 해주면 전부 0으로 들어가는데 /안해주면 쓰레기 값이 들어감
    _tagStudent studentArr[100] = {}; // 56bite짜리 100개를 연속되게 선언

    //구조체 멤버에 접근할 땐 .을 사용
    tStudent.iNumber = 5;
    tStudent.iKor = 100;
    // tStudent.strName = "";
    
    /*문자열을 배열에 넣어줄 때에는 단순 대입으로는 불가능하다 
    strcpy_s 라는 함수를 이용해서 문자열을 '복사'해 주어야 한다.
    이 함수는 오른쪽에 있는 문자열을 왼쪽으로 복사 해준다.    */
    //strcpy_s(tStudent.strName, "SeungChae Kim"); // 이친구는 다음 문자를 넣고 다음에 자동으로 0을 채워줘 그래서 쓰레기값 x

    /*문자열의 끝은 항상 0(NULL)로 끝나야한다. 그런데 쓰레기 값이 들어가 있는 상태에서
    아래처럼 각 배열 요소에 값을 넣어주게 되면 그 값이 출력되고 나머지는 쓰레기 값이 출력된다. 
    문자열의 끝을 인식할 수 없기 때문이다. 0을 넣어주면 뒤에 뭐가 오든 딱 거기까지만 출력해준다.*/

    tStudent.strName[0] = 'a';
    tStudent.strName[15]= 'C';
    tStudent.strName[5] = 0;
    strcpy_s(tStudent.strName, "SeungChae Kim");
    tStudent.strName[15] = 'C';
    for(int i =0; i <32;i++) cout << "strcpy 배열 확인" << tStudent.strName[i] << endl;

    cout << "Name : " << tStudent.strName << endl;
    cout << "Number : " << tStudent.iNumber << endl;
    cout << "Kor : " << tStudent.iKor << endl;
    cout << "Eng : " << tStudent.iEng << endl;
    cout << "Math : " << tStudent.iMath<< endl;
    cout << "Total : " << tStudent.iTotal<< endl;
    cout << "Mean : " << tStudent.iE << endl;
    
    return 0;
}