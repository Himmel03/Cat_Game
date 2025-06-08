///////////////////////////////////////////
// 한남대학교 AI융합학과 20232536 김민정 //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>

#define ROOM_WIDTH 15                       // 방 너비
#define HME_POS 1                           // 집 위치
#define BWL_POS (ROOM_WIDTH - 2)            // 냄비 위치

int main(void) {

    srand((unsigned int)time(NULL));        // 프로그램 실행할 때마다 시드를 다르게 하기 위해

    // ------------------------------------------------------ 변수 설정 ------------------------------------------------------ //
    int soup = 0;                           // 수프 개수
    int relationship = 2;                   // 친밀도 (0~4)
    int cat_left = 0;                       // 야옹이의 현재 위치 (출력 기준으로 왼쪽 공백 수)
    int previous_location = -1;             // 이전 위치 표시용 (없으면 -1)
    int dice;                               // 주사위 값
    int random, action;                     // 랜덤값 받는 변수(수프 종류 선택할 때 사용), 행동 입력 받는 변수(0 또는 1)
    char cat_name[16];                      // 야옹이 이름
    int CP = 0;                             // 자원(CP)
    int feeling = 3;                        // 기분(0~3)
    bool scratcher = false;                 // 스크래쳐 유무
    bool cat_tower = false;                 // 캣타워 유무
    bool toy_mouse = false;                 // 장난감 쥐 유무
    bool toy_laser = false;                 // 장난감 레이저 유무
    int produce_CP = 0;                     // 생산한 CP값
    int choice;                             // 상점 선택값
    int SCRATCHER_POS = -1;                 // 스크래처 위치
    int CAT_TOWER_POS = -1;                 // 캣타워 위치


    // ------------------------------------------------------ 인트로 ------------------------------------------------------ //
    // 게임 이름
    printf("***야옹이와 수프***\n\n");

    // 야옹이 그림
    printf("    /\\__/\\   ))\n");
    printf("   (=OㅅO=) // \n");
    printf("   /      \\// \n");
    printf("  (        )  \n");
    printf("   \\_v__v_/    \n\n");

    // 야옹이 이름 설정
    printf("야옹이의 이름을 입력해 주세요 (5자 이내) : ");
    scanf_s("%s", cat_name, 16);
    printf("야옹이의 이름은 '%s'입니다!\n\n", cat_name);

    // 1초 후 화면 지우기
    Sleep(1000);
    system("cls");

    Sleep(500);                                                                              // 각 단계 사이에 잠시 멈추기


    // ------------------------------------------------------ 상태 출력 ------------------------------------------------------ //
    while (1) {

        // CP포인트
        if (feeling - 1 == 0) {
            produce_CP = relationship;
        }
        else {
            produce_CP = (feeling - 1) + relationship;
        }

        // 상태 출력
        printf("============================== 현재 상태 ==============================\n");
        printf("현재까지 만든 수프 : %d개\n", soup);
        printf("CP : %d 포인트\n", CP);
        printf("%s 기분(0~3) : %d\n", cat_name, feeling);
        switch (feeling) {
        case 0: printf("\t기분이 매우 나쁩니다.\n"); break;
        case 1: printf("\t심심해합니다.\n"); break;
        case 2: printf("\t식빵을 굽습니다.\n"); break;
        case 3: printf("\t골골송을 부릅니다.\n"); break;
        }
        printf("집사와의 관계 (0~4) : %d\n", relationship);
        printf("\t                                           /\\__/\\ \n");
        switch (relationship) {
        case 0: printf("\t곁에 오는 것조차 싫어합니다..            = ㅡㅅㅡ =\n"); break;
        case 1: printf("\t간식 자판기 취급입니다..                  = -ㅅ- =\n"); break;
        case 2: printf("\t그럭저럭 쓸 만한 집사입니다.              = oㅅo =\n"); break;
        case 3: printf("\t훌륭한 집사로 인정 받고 있습니다!         = OㅅO =\n"); break;
        case 4: printf("\t집사 껌딱지입니다!                        = >ㅅ< =\n"); break;
        }
        printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", cat_name, produce_CP);
        CP += produce_CP;
        printf("보유 CP : %d 포인트\n", CP);
        printf("=======================================================================\n\n");

        Sleep(500);                                                                          // 각 단계 사이에 잠시 멈추기


        // ------------------------------------------------------ 기분 ------------------------------------------------------ //
        printf("아무 이유 없이 기분이 나빠집니다. 고양이니까?\n");
        printf("6-%d : 주사위 눈이 %d이하면 그냥 기분이 나빠집니다.\n", relationship, 6 - relationship);
        printf("주사위를 굴립니다. 또르르...\n");
        Sleep(1000);
        dice = rand() % 6 + 1;                                                               // 1~6사이의 난수 생성
        printf("%d이(가) 나왔습니다.\n", dice);

        if (dice <= (6 - relationship)) {
            if (feeling > 0) {
                printf("%s의 기분이 나빠집니다 : %d -> %d\n\n", cat_name, feeling, feeling - 1);
                feeling--;
            }
            else {
                printf("%s의 기분이 나빠집니다 : % d -> % d\n\n", cat_name, feeling, feeling);
            }


        }
        else {
            printf("%s의 기분이 그대로입니다 : %d\n\n", cat_name, feeling);
        }

        Sleep(500);                                                                          // 각 단계 사이에 잠시 멈추기


        // ------------------------------------------------------ 야옹이 방 그리기 ------------------------------------------------------ //
        // 윗줄
        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        // 1행 집(H)과 냄비(B)
        printf("#");
        for (int i = 1; i <= ROOM_WIDTH - 2; i++) {
            if (i == HME_POS) {
                printf("H");
            }
            else if (i == BWL_POS) {
                printf("B");
            }
            else if (i == SCRATCHER_POS) {
                printf("S");
            }
            else if (i == CAT_TOWER_POS) {
                printf("T");
            }
            else {
                printf(" ");
            }
        }
        printf("#\n");

        // 2행: 야옹이(C)와 이전 위치(.) 표시
        printf("#");
        for (int i = 1; i <= ROOM_WIDTH - 2; i++) {
            if (i == cat_left + 1) {                                                          // 현재 위치
                printf("C");
            }
            else if (i == previous_location) {                                                // 직전 위치
                printf(".");
            }
            else {
                printf(" ");
            }
        }
        printf("#\n");

        // 아랫줄
        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n\n");

        Sleep(500);                                                                          // 각 단계 사이에 잠시 멈추기


        // ------------------------------------------------------ 상호 작용 ------------------------------------------------------ //
        action = -1;

        printf("어떤 상호작용을 하시겠습니까?\n0 : 아무것도 하지 않음\n1 : 긁어 주기\n");
        if (toy_mouse == true) {
            printf("2 : 장난감 쥐로 놀아 주기\n");
            if (toy_laser == true) {
                printf("3 : 레이저 포인터로 놀아 주기\n");
            }
        }
        else if (toy_laser == true) {
            printf("2 : 레이저 포인터로 놀아 주기\n");
            if (toy_mouse == true) {
                printf("3 : 장난감 쥐로 놀아 주기\n");
            }
        }

        if (toy_mouse == true && toy_laser == true) {                                        // 0~2까지 선택지
            while (action != 0 && action != 1 && action != 2 && action != 3) {               // 상호작용에서 범위 외의 값이 입력 되면 다시 입력 받기
                printf(">> ");
                scanf_s("%d", &action);
            }
        }
        else if (toy_mouse == true || toy_laser == true) {                                   // 0~3까지 선택지
            while (action != 0 && action != 1 && action != 2) {                              // 상호작용에서 범위 외의 값이 입력 되면 다시 입력 받기
                printf(">> ");
                scanf_s("%d", &action);
            }
        }
        else {                                                                               // 0~1까지 선택지
            while (action != 0 && action != 1) {                                             // 상호작용에서 범위 외의 값이 입력 되면 다시 입력 받기
                printf(">> ");
                scanf_s("%d", &action);
            }
        }

        dice = rand() % 6 + 1;                                                               // 1~6사이의 난수 생성

        if (action == 0) {                                                                   // 0 : 아무것도 하지 않기
            printf("\n아무것도 하지 않았습니다. %s의 기분이 나빠졌습니다.\n", cat_name);
            if (feeling > 0) {
                feeling--;
            }
            printf("주사위 눈이 5 이하면 친밀도가 떨어집니다.\n주사위를 굴립니다. 또르륵...\n");
            Sleep(1000);                                                                     // 추가 (주사위 기다리는 느낌)
            printf("%d이(가) 나왔습니다!\n", dice);
            Sleep(1000);                                                                     // 추가 (빠른 출력 방지)

            if (dice <= 5 && relationship > 0) {                                             // 주사위 눈이 5 이하면 친밀도 하락
                relationship--;
                printf("친밀도가 떨어졌습니다.\n");
            }
            else {                                                                           // 친밀도는 0보다 작은 값으로 내려가지 않음
                printf("다행히 친밀도는 그대로입니다.\n");
            }
        }
        else if (action == 1) {                                                              // 1 : 긁어주기
            printf("\n'%s'의 턱을 긁어주었습니다! %s의 기분은 그대로 입니다.\n", cat_name, cat_name);
            printf("주사위 눈이 5 이상이면 친밀도가 증가합니다.\n주사위를 굴립니다. 또르륵...\n");
            Sleep(1000);                                                                     // 추가 (주사위 기다리는 느낌)
            printf("%d이(가) 나왔습니다!\n", dice);
            Sleep(1000);                                                                     // 추가 (빠른 출력 방지)

            if (dice >= 5 && relationship < 4) {                                             // 주사위 눈이 5 이상이면 친밀도 상승
                relationship++;
                printf("친밀도가 1 올라갔습니다.\n");
            }
            else {                                                                           // 친밀도는 4보다 큰 값으로 올라가지는 않음
                printf("친밀도는 그대로입니다.\n");
            }
        }
        else if (action == 2) {
            if (feeling < 3) {
                printf("장난감 쥐로 %s와 놀아 주었습니다. %s의 기분이 조금 좋아졌습니다 : %d -> %d\n", cat_name, cat_name, feeling, feeling + 1);
                feeling++;
            }
            else {
                printf("장난감 쥐로 %s와 놀아 주었습니다. %s의 기분이 조금 좋아졌습니다 : %d -> %d\n", cat_name, cat_name, feeling, feeling);
            }
            printf("주사위 눈이 4 이상이면 친밀도가 증가합니다.\n주사위를 굴립니다. 또르륵...\n");
            Sleep(1000);                                                                     // 추가 (주사위 기다리는 느낌)
            printf("%d이(가) 나왔습니다!\n", dice);
            Sleep(1000);                                                                     // 추가 (빠른 출력 방지)

            if (dice >= 4 && relationship < 4) {                                             // 주사위 눈이 4 이상이면 친밀도 상승
                relationship++;
                printf("친밀도가 1 올라갔습니다.\n");
            }
            else {                                                                           // 친밀도는 4보다 큰 값으로 올라가지는 않음
                printf("친밀도는 그대로입니다.\n");
            }
        }
        else {
            if (feeling < 3) {
                printf("레이저 포인터로 %s와 신나게 놀아 주었습니다. %s의 기분이 꽤 좋아졌습니다 : %d -> %d\n", cat_name, cat_name, feeling, feeling + 2);
                feeling+=2;
            }
            else {
                printf("레이저 포인터로 %s와 신나게 놀아 주었습니다. %s의 기분이 꽤 좋아졌습니다 : %d -> %d\n", cat_name, cat_name, feeling, feeling);
            }
            printf("주사위 눈이 2 이상이면 친밀도가 증가합니다.\n주사위를 굴립니다. 또르륵...\n");
            Sleep(1000);                                                                     // 추가 (주사위 기다리는 느낌)
            printf("%d이(가) 나왔습니다!\n", dice);
            Sleep(1000);                                                                     // 추가 (빠른 출력 방지)

            if (dice >= 2 && relationship < 4) {                                             // 주사위 눈이 2 이상이면 친밀도 상승
                relationship++;
                printf("친밀도가 1 올라갔습니다.\n");
            }
            else {                                                                           // 친밀도는 4보다 큰 값으로 올라가지는 않음
                printf("친밀도는 그대로입니다.\n");
            }
        }

        Sleep(1000);                                                                         // 추가 (빠른 출력 방지)

        printf("현재 친밀도 : %d\n\n", relationship);                                        // 친밀도 출력

        Sleep(500);                                                                          // 각 단계 사이에 잠시 멈추기


        // ------------------------------------------------------ 이동 ------------------------------------------------------ //
        previous_location = cat_left + 1;                                                   // 현재 위치 기억 = 이전 위치

        switch (feeling) {

        case 0:
            printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", cat_name);
            if (cat_left > 0) {                                                             // 집쪽으로 한 칸 이동
                cat_left--;
            }
            else {                                                                          // 현재 위치 = 0 : 이동하려는 방향이 벽에 막히면 그 자리에 앉음
                printf("벽에 막혀 이동하지 않습니다.\n");                                   // 이동하려는 방향이 벽에 막히면 그 자리에 앉음
                printf("기분 +1\n");                                                        // 집에서 한 턴을 쉴 떄마다 기분 +1
                if (feeling < 3) {
                    feeling++;
                }
            }
            break;

        case 1:
            if (scratcher == true || cat_tower == true) {
                if (abs((cat_left + 2) - SCRATCHER_POS) < abs((cat_left + 2) - CAT_TOWER_POS)) {        // 야옹이 위치에서 각 놀이기구까지의 거리를 구해 가까운 놀이기구로 이동하도록 함
                    printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.\n", cat_name);
                    if (((cat_left + 2) - SCRATCHER_POS) > 0) {                                         // 야옹이보다 왼쪽에 있으면
                        cat_left--;                                                                     // 야옹이 왼쪽으로 이동
                    }
                    else {                                                                              // 야옹이보다 오른쪽에 있으면
                        cat_left++;                                                                     // 야옹이 오른쪽으로 이동
                    }
                }
                else {
                    printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.\n", cat_name);
                    if (((cat_left + 2) - CAT_TOWER_POS) > 0) {                                         // 야옹이보다 왼쪽에 있으면
                        cat_left--;                                                                     // 야옹이 왼쪽으로 이동
                    }
                    else {                                                                              // 야옹이보다 오른쪽에 있으면
                        cat_left++;                                                                     // 야옹이 오른쪽으로 이동
                    }
                }
            }
            else {
                printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
                if (feeling > 0) {
                    feeling--;
                }
            }
            break;

        case 2: 
            printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n", cat_name);
            break;

        case 3: 
            printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", cat_name);
            if (cat_left < ROOM_WIDTH - 3) {                                                // 냄비쪽으로 한 칸 이동
                cat_left++;
            }
            else {                                                                          // 현재 위치 = 7 : 이동하려는 방향이 벽에 막히면 그 자리에 앉음
                printf("벽에 막혀 이동하지 않습니다.\n");
            }
            break;
        }

        printf("\n");

        Sleep(500);                                                                         // 각 단계 사이에 잠시 멈추기


        // ------------------------------------------------------ 행동 ------------------------------------------------------ //

        if (cat_left + 1 == BWL_POS) {                                                      // 야옹이가 냄비와 같은 열에 있으면 수프 1개 만듦
            soup++;
            random = rand() % 3 + 1;                                                        // 만드는 수프는 감자, 양송이, 브로콜리 수프 중 무작위로 출력

            if (random == 1) {
                printf("\n'%s'이(가) 감자 수프를 만들었습니다!\n", cat_name);
            }
            else if (random == 2) {
                printf("\n'%s'이(가) 양송이 수프를 만들었습니다!\n", cat_name);
            }
            else {
                printf("\n'%s'이(가) 브로콜리 수프를 만들었습니다!\n", cat_name);
            }
            printf("현재까지 만든 수프 : %d개\n\n", soup);
        }
        else if (cat_left + 1 == SCRATCHER_POS) {                                           // 스크래처에 위치
            printf("%s은(는) 스크래처를 긁고 놀았습니다.\n", cat_name);
            if (feeling < 3) {
                printf("기분이 조금 좋아졌습니다 : %d -> %d\n", feeling, feeling + 1);
                feeling++;
            }
            else {
                printf("기분이 조금 좋아졌습니다 : %d -> %d\n", feeling, feeling);
            }
            
            
            
        }
        else if (cat_left + 1 == CAT_TOWER_POS) {                                           // 캣타워에 위치
            printf("%s은(는) 캣타워를 뛰어다닙니다.\n", cat_name);
            if (feeling < 3) {
                printf("기분이 조금 제법 좋아졌습니다 : %d -> %d\n", feeling, feeling + 2);
                feeling+=2;
            }
            else {
                printf("기분이 조금 제법 좋아졌습니다 : %d -> %d\n", feeling, feeling);
            }
        }
        else if (cat_left + 1 == HME_POS) {                                                 // 집에 위치
            printf("\n'%s'은(는) 자신의 집에서 편안함을 느낍니다..\n\n", cat_name);
        }

        Sleep(500);


        // ------------------------------------------------------ 상점 ------------------------------------------------------ //
        printf("상점에서 물건을 살 수 있습니다.\n");
        printf("어떤 물건을 구매할까요?\n");
        printf("\t0. 아무 것도 사지 않는다.\n");
        printf("\t1. 장난감 쥐 : 1 CP");
        if (toy_mouse == true) {
            printf("(품절)\n");
        }
        else {
            printf("\n");
        }
        printf("\t2. 레이저 포인터 : 2 CP");
        if (toy_laser == true) {
            printf("(품절)\n");
        }
        else {
            printf("\n");
        }
        printf("\t3. 스크래처 : 4 CP");
        if (scratcher == true) {
            printf("(품절)\n");
        }
        else {
            printf("\n");
        }
        printf("\t4. 캣 타워 : 6 CP");
        if (cat_tower == true) {
            printf("(품절)\n");
        }
        else {
            printf("\n");
        }
        printf(">>");
        scanf_s("%d", &choice);

        if (choice == 1) {
            if (toy_mouse == true) {
                printf("장난감 쥐를 이미 구매했습니다.\n");
            }
            else {
                if (CP < 1) {
                    printf("CP가 부족합니다.");
                }
                else {
                    CP -= 1;
                    printf("장난감쥐를 구매했습니다.\n보유 CP %d 포인트\n", CP);
                    toy_mouse = true;
                }
            }
        }
        else if (choice == 2) {
            if (toy_laser == true) {
                printf("레이저 포인터를 이미 구매했습니다.\n");
            }
            else {
                if (CP < 2) {
                    printf("CP가 부족합니다.");
                }
                else {
                    CP -= 2;
                    printf("레이저 포인터를 구매했습니다.\n보유 CP %d 포인트\n", CP);
                    toy_laser = true;
                }
            }
        }
        else if (choice == 3) {
            if (scratcher == true) {
                printf("스크래처를 이미 구매했습니다.\n");
            }
            else {
                if (CP < 4) {
                    printf("CP가 부족합니다.");
                }
                else {
                    CP -= 4;
                    printf("스크래처를 구매했습니다.\n보유 CP %d 포인트\n", CP);
                    scratcher = true;
                    do {
                        SCRATCHER_POS = rand() % (ROOM_WIDTH - 3) + 2;                            // 2 ~ ROOM_WIDTH - 3까지
                    } while (SCRATCHER_POS == CAT_TOWER_POS);
                }
            }
        }
        else if (choice == 4) {
            if (cat_tower == true) {
                printf("캣타워를 이미 구매했습니다.\n");
            }
            else {
                if (CP < 6) {
                    printf("CP가 부족합니다.");
                }
                else {
                    CP -= 6;
                    printf("캣타워를 구매했습니다.\n보유 CP %d 포인트\n", CP);
                    cat_tower = true;
                    do {
                        CAT_TOWER_POS = rand() % (ROOM_WIDTH - 3) + 2;                            // 2 ~ ROOM_WIDTH - 3까지
                    } while (CAT_TOWER_POS == SCRATCHER_POS);
                }
            }
        }
        else {
            printf("아무 것도 사지 않았습니다.\n");
        }

        Sleep(2500);                                                                        // 2.5초 대기
        system("cls");                                                                      // 화면 지움
    }

    return 0;
}
