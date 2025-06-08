///////////////////////////////////////////
// �ѳ����б� AI�����а� 20232536 ����� //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>

#define ROOM_WIDTH 15                       // �� �ʺ�
#define HME_POS 1                           // �� ��ġ
#define BWL_POS (ROOM_WIDTH - 2)            // ���� ��ġ

int main(void) {

    srand((unsigned int)time(NULL));        // ���α׷� ������ ������ �õ带 �ٸ��� �ϱ� ����

    // ------------------------------------------------------ ���� ���� ------------------------------------------------------ //
    int soup = 0;                           // ���� ����
    int relationship = 2;                   // ģ�е� (0~4)
    int cat_left = 0;                       // �߿����� ���� ��ġ (��� �������� ���� ���� ��)
    int previous_location = -1;             // ���� ��ġ ǥ�ÿ� (������ -1)
    int dice;                               // �ֻ��� ��
    int random, action;                     // ������ �޴� ����(���� ���� ������ �� ���), �ൿ �Է� �޴� ����(0 �Ǵ� 1)
    char cat_name[16];                      // �߿��� �̸�
    int CP = 0;                             // �ڿ�(CP)
    int feeling = 3;                        // ���(0~3)
    bool scratcher = false;                 // ��ũ���� ����
    bool cat_tower = false;                 // ĹŸ�� ����
    bool toy_mouse = false;                 // �峭�� �� ����
    bool toy_laser = false;                 // �峭�� ������ ����
    int produce_CP = 0;                     // ������ CP��
    int choice;                             // ���� ���ð�
    int SCRATCHER_POS = -1;                 // ��ũ��ó ��ġ
    int CAT_TOWER_POS = -1;                 // ĹŸ�� ��ġ


    // ------------------------------------------------------ ��Ʈ�� ------------------------------------------------------ //
    // ���� �̸�
    printf("***�߿��̿� ����***\n\n");

    // �߿��� �׸�
    printf("    /\\__/\\   ))\n");
    printf("   (=O��O=) // \n");
    printf("   /      \\// \n");
    printf("  (        )  \n");
    printf("   \\_v__v_/    \n\n");

    // �߿��� �̸� ����
    printf("�߿����� �̸��� �Է��� �ּ��� (5�� �̳�) : ");
    scanf_s("%s", cat_name, 16);
    printf("�߿����� �̸��� '%s'�Դϴ�!\n\n", cat_name);

    // 1�� �� ȭ�� �����
    Sleep(1000);
    system("cls");

    Sleep(500);                                                                              // �� �ܰ� ���̿� ��� ���߱�


    // ------------------------------------------------------ ���� ��� ------------------------------------------------------ //
    while (1) {

        // CP����Ʈ
        if (feeling - 1 == 0) {
            produce_CP = relationship;
        }
        else {
            produce_CP = (feeling - 1) + relationship;
        }

        // ���� ���
        printf("============================== ���� ���� ==============================\n");
        printf("������� ���� ���� : %d��\n", soup);
        printf("CP : %d ����Ʈ\n", CP);
        printf("%s ���(0~3) : %d\n", cat_name, feeling);
        switch (feeling) {
        case 0: printf("\t����� �ſ� ���޴ϴ�.\n"); break;
        case 1: printf("\t�ɽ����մϴ�.\n"); break;
        case 2: printf("\t�Ļ��� �����ϴ�.\n"); break;
        case 3: printf("\t������ �θ��ϴ�.\n"); break;
        }
        printf("������� ���� (0~4) : %d\n", relationship);
        printf("\t                                           /\\__/\\ \n");
        switch (relationship) {
        case 0: printf("\t�翡 ���� ������ �Ⱦ��մϴ�..            = �Ѥ��� =\n"); break;
        case 1: printf("\t���� ���Ǳ� ����Դϴ�..                  = -��- =\n"); break;
        case 2: printf("\t�׷����� �� ���� �����Դϴ�.              = o��o =\n"); break;
        case 3: printf("\t�Ǹ��� ����� ���� �ް� �ֽ��ϴ�!         = O��O =\n"); break;
        case 4: printf("\t���� �������Դϴ�!                        = >��< =\n"); break;
        }
        printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", cat_name, produce_CP);
        CP += produce_CP;
        printf("���� CP : %d ����Ʈ\n", CP);
        printf("=======================================================================\n\n");

        Sleep(500);                                                                          // �� �ܰ� ���̿� ��� ���߱�


        // ------------------------------------------------------ ��� ------------------------------------------------------ //
        printf("�ƹ� ���� ���� ����� �������ϴ�. ����̴ϱ�?\n");
        printf("6-%d : �ֻ��� ���� %d���ϸ� �׳� ����� �������ϴ�.\n", relationship, 6 - relationship);
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
        Sleep(1000);
        dice = rand() % 6 + 1;                                                               // 1~6������ ���� ����
        printf("%d��(��) ���Խ��ϴ�.\n", dice);

        if (dice <= (6 - relationship)) {
            if (feeling > 0) {
                printf("%s�� ����� �������ϴ� : %d -> %d\n\n", cat_name, feeling, feeling - 1);
                feeling--;
            }
            else {
                printf("%s�� ����� �������ϴ� : % d -> % d\n\n", cat_name, feeling, feeling);
            }


        }
        else {
            printf("%s�� ����� �״���Դϴ� : %d\n\n", cat_name, feeling);
        }

        Sleep(500);                                                                          // �� �ܰ� ���̿� ��� ���߱�


        // ------------------------------------------------------ �߿��� �� �׸��� ------------------------------------------------------ //
        // ����
        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        // 1�� ��(H)�� ����(B)
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

        // 2��: �߿���(C)�� ���� ��ġ(.) ǥ��
        printf("#");
        for (int i = 1; i <= ROOM_WIDTH - 2; i++) {
            if (i == cat_left + 1) {                                                          // ���� ��ġ
                printf("C");
            }
            else if (i == previous_location) {                                                // ���� ��ġ
                printf(".");
            }
            else {
                printf(" ");
            }
        }
        printf("#\n");

        // �Ʒ���
        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n\n");

        Sleep(500);                                                                          // �� �ܰ� ���̿� ��� ���߱�


        // ------------------------------------------------------ ��ȣ �ۿ� ------------------------------------------------------ //
        action = -1;

        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n0 : �ƹ��͵� ���� ����\n1 : �ܾ� �ֱ�\n");
        if (toy_mouse == true) {
            printf("2 : �峭�� ��� ��� �ֱ�\n");
            if (toy_laser == true) {
                printf("3 : ������ �����ͷ� ��� �ֱ�\n");
            }
        }
        else if (toy_laser == true) {
            printf("2 : ������ �����ͷ� ��� �ֱ�\n");
            if (toy_mouse == true) {
                printf("3 : �峭�� ��� ��� �ֱ�\n");
            }
        }

        if (toy_mouse == true && toy_laser == true) {                                        // 0~2���� ������
            while (action != 0 && action != 1 && action != 2 && action != 3) {               // ��ȣ�ۿ뿡�� ���� ���� ���� �Է� �Ǹ� �ٽ� �Է� �ޱ�
                printf(">> ");
                scanf_s("%d", &action);
            }
        }
        else if (toy_mouse == true || toy_laser == true) {                                   // 0~3���� ������
            while (action != 0 && action != 1 && action != 2) {                              // ��ȣ�ۿ뿡�� ���� ���� ���� �Է� �Ǹ� �ٽ� �Է� �ޱ�
                printf(">> ");
                scanf_s("%d", &action);
            }
        }
        else {                                                                               // 0~1���� ������
            while (action != 0 && action != 1) {                                             // ��ȣ�ۿ뿡�� ���� ���� ���� �Է� �Ǹ� �ٽ� �Է� �ޱ�
                printf(">> ");
                scanf_s("%d", &action);
            }
        }

        dice = rand() % 6 + 1;                                                               // 1~6������ ���� ����

        if (action == 0) {                                                                   // 0 : �ƹ��͵� ���� �ʱ�
            printf("\n�ƹ��͵� ���� �ʾҽ��ϴ�. %s�� ����� ���������ϴ�.\n", cat_name);
            if (feeling > 0) {
                feeling--;
            }
            printf("�ֻ��� ���� 5 ���ϸ� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
            Sleep(1000);                                                                     // �߰� (�ֻ��� ��ٸ��� ����)
            printf("%d��(��) ���Խ��ϴ�!\n", dice);
            Sleep(1000);                                                                     // �߰� (���� ��� ����)

            if (dice <= 5 && relationship > 0) {                                             // �ֻ��� ���� 5 ���ϸ� ģ�е� �϶�
                relationship--;
                printf("ģ�е��� ���������ϴ�.\n");
            }
            else {                                                                           // ģ�е��� 0���� ���� ������ �������� ����
                printf("������ ģ�е��� �״���Դϴ�.\n");
            }
        }
        else if (action == 1) {                                                              // 1 : �ܾ��ֱ�
            printf("\n'%s'�� ���� �ܾ��־����ϴ�! %s�� ����� �״�� �Դϴ�.\n", cat_name, cat_name);
            printf("�ֻ��� ���� 5 �̻��̸� ģ�е��� �����մϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
            Sleep(1000);                                                                     // �߰� (�ֻ��� ��ٸ��� ����)
            printf("%d��(��) ���Խ��ϴ�!\n", dice);
            Sleep(1000);                                                                     // �߰� (���� ��� ����)

            if (dice >= 5 && relationship < 4) {                                             // �ֻ��� ���� 5 �̻��̸� ģ�е� ���
                relationship++;
                printf("ģ�е��� 1 �ö󰬽��ϴ�.\n");
            }
            else {                                                                           // ģ�е��� 4���� ū ������ �ö����� ����
                printf("ģ�е��� �״���Դϴ�.\n");
            }
        }
        else if (action == 2) {
            if (feeling < 3) {
                printf("�峭�� ��� %s�� ��� �־����ϴ�. %s�� ����� ���� ���������ϴ� : %d -> %d\n", cat_name, cat_name, feeling, feeling + 1);
                feeling++;
            }
            else {
                printf("�峭�� ��� %s�� ��� �־����ϴ�. %s�� ����� ���� ���������ϴ� : %d -> %d\n", cat_name, cat_name, feeling, feeling);
            }
            printf("�ֻ��� ���� 4 �̻��̸� ģ�е��� �����մϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
            Sleep(1000);                                                                     // �߰� (�ֻ��� ��ٸ��� ����)
            printf("%d��(��) ���Խ��ϴ�!\n", dice);
            Sleep(1000);                                                                     // �߰� (���� ��� ����)

            if (dice >= 4 && relationship < 4) {                                             // �ֻ��� ���� 4 �̻��̸� ģ�е� ���
                relationship++;
                printf("ģ�е��� 1 �ö󰬽��ϴ�.\n");
            }
            else {                                                                           // ģ�е��� 4���� ū ������ �ö����� ����
                printf("ģ�е��� �״���Դϴ�.\n");
            }
        }
        else {
            if (feeling < 3) {
                printf("������ �����ͷ� %s�� �ų��� ��� �־����ϴ�. %s�� ����� �� ���������ϴ� : %d -> %d\n", cat_name, cat_name, feeling, feeling + 2);
                feeling+=2;
            }
            else {
                printf("������ �����ͷ� %s�� �ų��� ��� �־����ϴ�. %s�� ����� �� ���������ϴ� : %d -> %d\n", cat_name, cat_name, feeling, feeling);
            }
            printf("�ֻ��� ���� 2 �̻��̸� ģ�е��� �����մϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
            Sleep(1000);                                                                     // �߰� (�ֻ��� ��ٸ��� ����)
            printf("%d��(��) ���Խ��ϴ�!\n", dice);
            Sleep(1000);                                                                     // �߰� (���� ��� ����)

            if (dice >= 2 && relationship < 4) {                                             // �ֻ��� ���� 2 �̻��̸� ģ�е� ���
                relationship++;
                printf("ģ�е��� 1 �ö󰬽��ϴ�.\n");
            }
            else {                                                                           // ģ�е��� 4���� ū ������ �ö����� ����
                printf("ģ�е��� �״���Դϴ�.\n");
            }
        }

        Sleep(1000);                                                                         // �߰� (���� ��� ����)

        printf("���� ģ�е� : %d\n\n", relationship);                                        // ģ�е� ���

        Sleep(500);                                                                          // �� �ܰ� ���̿� ��� ���߱�


        // ------------------------------------------------------ �̵� ------------------------------------------------------ //
        previous_location = cat_left + 1;                                                   // ���� ��ġ ��� = ���� ��ġ

        switch (feeling) {

        case 0:
            printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", cat_name);
            if (cat_left > 0) {                                                             // �������� �� ĭ �̵�
                cat_left--;
            }
            else {                                                                          // ���� ��ġ = 0 : �̵��Ϸ��� ������ ���� ������ �� �ڸ��� ����
                printf("���� ���� �̵����� �ʽ��ϴ�.\n");                                   // �̵��Ϸ��� ������ ���� ������ �� �ڸ��� ����
                printf("��� +1\n");                                                        // ������ �� ���� �� ������ ��� +1
                if (feeling < 3) {
                    feeling++;
                }
            }
            break;

        case 1:
            if (scratcher == true || cat_tower == true) {
                if (abs((cat_left + 2) - SCRATCHER_POS) < abs((cat_left + 2) - CAT_TOWER_POS)) {        // �߿��� ��ġ���� �� ���̱ⱸ������ �Ÿ��� ���� ����� ���̱ⱸ�� �̵��ϵ��� ��
                    printf("%s��(��) �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n", cat_name);
                    if (((cat_left + 2) - SCRATCHER_POS) > 0) {                                         // �߿��̺��� ���ʿ� ������
                        cat_left--;                                                                     // �߿��� �������� �̵�
                    }
                    else {                                                                              // �߿��̺��� �����ʿ� ������
                        cat_left++;                                                                     // �߿��� ���������� �̵�
                    }
                }
                else {
                    printf("%s��(��) �ɽ��ؼ� ĹŸ�� ������ �̵��մϴ�.\n", cat_name);
                    if (((cat_left + 2) - CAT_TOWER_POS) > 0) {                                         // �߿��̺��� ���ʿ� ������
                        cat_left--;                                                                     // �߿��� �������� �̵�
                    }
                    else {                                                                              // �߿��̺��� �����ʿ� ������
                        cat_left++;                                                                     // �߿��� ���������� �̵�
                    }
                }
            }
            else {
                printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
                if (feeling > 0) {
                    feeling--;
                }
            }
            break;

        case 2: 
            printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�.\n", cat_name);
            break;

        case 3: 
            printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", cat_name);
            if (cat_left < ROOM_WIDTH - 3) {                                                // ���������� �� ĭ �̵�
                cat_left++;
            }
            else {                                                                          // ���� ��ġ = 7 : �̵��Ϸ��� ������ ���� ������ �� �ڸ��� ����
                printf("���� ���� �̵����� �ʽ��ϴ�.\n");
            }
            break;
        }

        printf("\n");

        Sleep(500);                                                                         // �� �ܰ� ���̿� ��� ���߱�


        // ------------------------------------------------------ �ൿ ------------------------------------------------------ //

        if (cat_left + 1 == BWL_POS) {                                                      // �߿��̰� ����� ���� ���� ������ ���� 1�� ����
            soup++;
            random = rand() % 3 + 1;                                                        // ����� ������ ����, �����, ����ݸ� ���� �� �������� ���

            if (random == 1) {
                printf("\n'%s'��(��) ���� ������ ��������ϴ�!\n", cat_name);
            }
            else if (random == 2) {
                printf("\n'%s'��(��) ����� ������ ��������ϴ�!\n", cat_name);
            }
            else {
                printf("\n'%s'��(��) ����ݸ� ������ ��������ϴ�!\n", cat_name);
            }
            printf("������� ���� ���� : %d��\n\n", soup);
        }
        else if (cat_left + 1 == SCRATCHER_POS) {                                           // ��ũ��ó�� ��ġ
            printf("%s��(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n", cat_name);
            if (feeling < 3) {
                printf("����� ���� ���������ϴ� : %d -> %d\n", feeling, feeling + 1);
                feeling++;
            }
            else {
                printf("����� ���� ���������ϴ� : %d -> %d\n", feeling, feeling);
            }
            
            
            
        }
        else if (cat_left + 1 == CAT_TOWER_POS) {                                           // ĹŸ���� ��ġ
            printf("%s��(��) ĹŸ���� �پ�ٴմϴ�.\n", cat_name);
            if (feeling < 3) {
                printf("����� ���� ���� ���������ϴ� : %d -> %d\n", feeling, feeling + 2);
                feeling+=2;
            }
            else {
                printf("����� ���� ���� ���������ϴ� : %d -> %d\n", feeling, feeling);
            }
        }
        else if (cat_left + 1 == HME_POS) {                                                 // ���� ��ġ
            printf("\n'%s'��(��) �ڽ��� ������ ������� �����ϴ�..\n\n", cat_name);
        }

        Sleep(500);


        // ------------------------------------------------------ ���� ------------------------------------------------------ //
        printf("�������� ������ �� �� �ֽ��ϴ�.\n");
        printf("� ������ �����ұ��?\n");
        printf("\t0. �ƹ� �͵� ���� �ʴ´�.\n");
        printf("\t1. �峭�� �� : 1 CP");
        if (toy_mouse == true) {
            printf("(ǰ��)\n");
        }
        else {
            printf("\n");
        }
        printf("\t2. ������ ������ : 2 CP");
        if (toy_laser == true) {
            printf("(ǰ��)\n");
        }
        else {
            printf("\n");
        }
        printf("\t3. ��ũ��ó : 4 CP");
        if (scratcher == true) {
            printf("(ǰ��)\n");
        }
        else {
            printf("\n");
        }
        printf("\t4. Ĺ Ÿ�� : 6 CP");
        if (cat_tower == true) {
            printf("(ǰ��)\n");
        }
        else {
            printf("\n");
        }
        printf(">>");
        scanf_s("%d", &choice);

        if (choice == 1) {
            if (toy_mouse == true) {
                printf("�峭�� �㸦 �̹� �����߽��ϴ�.\n");
            }
            else {
                if (CP < 1) {
                    printf("CP�� �����մϴ�.");
                }
                else {
                    CP -= 1;
                    printf("�峭���㸦 �����߽��ϴ�.\n���� CP %d ����Ʈ\n", CP);
                    toy_mouse = true;
                }
            }
        }
        else if (choice == 2) {
            if (toy_laser == true) {
                printf("������ �����͸� �̹� �����߽��ϴ�.\n");
            }
            else {
                if (CP < 2) {
                    printf("CP�� �����մϴ�.");
                }
                else {
                    CP -= 2;
                    printf("������ �����͸� �����߽��ϴ�.\n���� CP %d ����Ʈ\n", CP);
                    toy_laser = true;
                }
            }
        }
        else if (choice == 3) {
            if (scratcher == true) {
                printf("��ũ��ó�� �̹� �����߽��ϴ�.\n");
            }
            else {
                if (CP < 4) {
                    printf("CP�� �����մϴ�.");
                }
                else {
                    CP -= 4;
                    printf("��ũ��ó�� �����߽��ϴ�.\n���� CP %d ����Ʈ\n", CP);
                    scratcher = true;
                    do {
                        SCRATCHER_POS = rand() % (ROOM_WIDTH - 3) + 2;                            // 2 ~ ROOM_WIDTH - 3����
                    } while (SCRATCHER_POS == CAT_TOWER_POS);
                }
            }
        }
        else if (choice == 4) {
            if (cat_tower == true) {
                printf("ĹŸ���� �̹� �����߽��ϴ�.\n");
            }
            else {
                if (CP < 6) {
                    printf("CP�� �����մϴ�.");
                }
                else {
                    CP -= 6;
                    printf("ĹŸ���� �����߽��ϴ�.\n���� CP %d ����Ʈ\n", CP);
                    cat_tower = true;
                    do {
                        CAT_TOWER_POS = rand() % (ROOM_WIDTH - 3) + 2;                            // 2 ~ ROOM_WIDTH - 3����
                    } while (CAT_TOWER_POS == SCRATCHER_POS);
                }
            }
        }
        else {
            printf("�ƹ� �͵� ���� �ʾҽ��ϴ�.\n");
        }

        Sleep(2500);                                                                        // 2.5�� ���
        system("cls");                                                                      // ȭ�� ����
    }

    return 0;
}
