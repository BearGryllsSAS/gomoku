#include<iostream>
using namespace std;

// -------------------- ������� --------------------
/*
    ����:
        map[i][j]��ʾ����(i,j)��ֵ
        0��ʾ�յ�
        1��ʾ����
        2��ʾ����
    ��: map[3][6] = 1  ��ʾ(3,6)��λ���Ǻ���
*/
int map[19][19];

// ��ʾ��ǰ�غ���  ż����ʾ��������  ������ʾ��������
// ��: flag = 20 ��ʾ��ǰ�ǵ�[20]������  �ɺڷ�����
int flag;
// -------------------- ������� --------------------


// -------------------- service --------------------
/*
    ������: ����
    ����: ��ʼ����Ϸ����
        �����̵�ֵ��ʼ��Ϊ0
        ��ǰ�غ���Ϊ����(flag��Ϊ0)
    ����: void
    ����ֵ: void
*/
void init();

/*
    *�ѵ�1
    ������: ����
    ����: ���ݴ��������(map��Ӧλ��)��flagֵ �ж������Ƿ��ʤ
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾû�л�ʤ
        1��ʾ����ʤ��
        2��ʾ����ʤ��
*/
int isWin(int x, int y);

/*
    ������: ����
    ����: ��ָ��λ������
        ���map[x][y]�ǿյ� ���޸�map[x][y]��ֵ:��Ϊ��Ӧ��ɫ(flag��Ӧ��ɫ)
        ���򲻲���
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾ����ʧ�� (�����Ѿ�����)
        1��ʾ���ӳɹ�

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    ����: չʾѡ��, ��ҿ���������ѡ�������Ϸ, �������û��˳���Ϸ
        ������Ϸ: ������Ϸ���溯��gameView();
        ��������: �����ڴ�...
        �˳���Ϸ: ����exit(0);
*/
void menuView();

/*
    ������: ����
    ����: ����map���� ��ӡ��Ϸ����
    ����: void
    ����ֵ: void
*/
void gameView_ShowMap();

/*
    ������: ����
    ����: ����flag��ֵ  ��ӡ��Ϸʤ������  �û����԰�������ص����˵�
    ����: void
    ����ֵ: void
*/
void winView();

/*
    *�ѵ�2
    ������: ����
    ����: ��Ϸ��������
        ��ʼ����Ϸ����(���ú���init())
        while(1){
            ��ӡ��Ϸ����(���ú���gameView_ShowMap())
            ���������������

            ����(�������Ӻ���playerMove())
                (�������ʧ�� ���¿�ʼѭ��)

            �ж���Ϸ�Ƿ�ʤ��(����ʤ���жϺ���isWin())
                (�����Ϸʤ�� ����ʤ�����溯�� Ȼ�������ǰ����)
            �л����(�޸�flagֵ)
        }
    ����: void
    ����ֵ: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    //menuView();

    

    int testflag = 0;
    //init���Դ���
    
    init();
    if (flag != 0) {
        printf("init()����");
        exit(0);
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (map[i][j]) {
                printf("init()����");
                exit(0);
            }
        }
    }
    printf("init()���Գɹ�\n");
    testflag++;
    

    //playerMove���Դ���
    
    int result = 1;
    result &= playerMove(2, 2);
    result &= playerMove(2, 3);
    result &= playerMove(2, 4);
    result &= playerMove(2, 5);
    if (result != 1 || (map[2][2] && map[2][3] && map[2][4] && map[2][5]) != 1) {
        printf("playerMove()����");
        exit(0);
    }
    flag = 1;
    result &= playerMove(2, 5);
    if (result != 0 || map[2][5] != 1) {
        printf("playerMove()����");
        exit(0);
    }
    printf("playerMove()���Գɹ�\n");
    testflag++;
    

    //isWin���Դ���
    /*
    playerMove(2, 1);
    if (isWin(2, 1)) {
        printf("isWin()����");
        exit(0);
    }
    playerMove(1, 0);
    playerMove(3, 2);
    playerMove(4, 3);
    playerMove(5, 4);
    if (isWin(1, 0) != 2) {
        printf("isWin()����");
        exit(0);
    }
    printf("isWin()���Գɹ�\n");
    testflag++;
    

    if (testflag == 3) {
        printf("service������Գɹ�\n");
    }
    return 0;

    */
}

void init() {
    //�ڴ˴���ɴ���
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            map[i][j] = 0;
        }
    }

    flag = 0;

    return;
}

int isWin(int x, int y) {
    //�ڴ˴���ɴ���
    int win = flag % 2 == 0 ? 1: 2;

    int result = -1;

    //ˮƽ����
    result = 0;
    for (int j = max(0, y - 4); j <= min(18, y + 4); j++) {
        if (map[x][j] == win) {
            result++;

            if (result == 5) {
                return win;
            }
        }
        else {
            result = 0;
        }
    }

    //��ֱ����
    result = 0;
    for (int i = max(0, x - 4); i <= min(18, x + 4); i++) {
        if (map[i][y] == win) {
            result++;

            if (result == 5) {
                return win;
            }
        }
        else {
            result = 0;
        }
    }

    //---------------------------------------------------------------------------------------//
    
    int count = -1;
    int tempX1 = -1, tempX2 = -1;
    int tempY1 = -1, tempY2 = -1;
    
    //����->����
    count = 4, tempX1 = x, tempY1 = y;
    while (count-- && (tempX1 - 1) >= 0 && (tempY1 - 1) >= 0) {
        tempX1--;
        tempY1--;
    }
    count = 4, tempX2 = x, tempY2 = y;
    while (count-- && (tempX2 + 1) <= 18 && (tempY2 + 1) <= 18) {
        tempX2++;
        tempY2++;
    }

    result = 0;
    for (int j = tempY1, i = tempX1; j <= tempY2 && i <= tempX2; i++, j++) {
        if (map[i][j] == win) {
            result++;

            if (result == 5) {
                return win;
            }
        }
        else {
            result = 0;
        }
    }
        
    //����->����
    count = 4, tempX1 = x, tempY1 = y;
    while (count-- && (tempX1 - 1) >= 0 && (tempY1 + 1) <= 18) {
        tempX1--;
        tempY1++;
    }
    count = 4, tempX2 = x, tempY2 = y;
    while (count-- && (tempX2 + 1) <= 18 && (tempY2 - 1) >= 0) {
        tempX2++;
        tempY2--;
    }

    result = 0;
    for (int j = tempY1, i = tempX1; j >= tempY2 && i <= tempX2; i++, j--) {
        if (map[i][j] == win) {
            result++;

            if (result == 5) {
                return win;
            }
        }
        else {
            result = 0;
        }
    }

    return 0;
}

int playerMove(int x, int y) {
    if (map[x][y] != 0) {
        return 0;
    }
    else {
        if (flag % 2 == 0) {
            map[x][y] = 1;
        }
        else {
            map[x][y] = 2;
        }

        return 1;
    }
}

void menuView() {
    //�ڴ˴���ɴ���
    int select = -1;
        
    while (true) {
        cout << "1-������Ϸ\t2-��Ϸ����\t3-�˳���Ϸ\n" << endl;
        cout << "���������ѡ��:";

        cin >> select;
        switch (select) {
        case 1:   //������Ϸ
            system("cls");
            gameView();
            break;
        case 2:     //��Ϸ����
            cout << "�����ڴ�..." << endl;
            system("pause");
            system("cls");
            break;
        case 3:     //�˳���Ϸ
            system("pause");
            exit(0);
        default:    //����
            cout << "��������,���������!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return;
}

void gameView_ShowMap() {
    //��ӡ����
    cout << "   " << "\t\t\t\t\t\t\t\t\t\t" << "-----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 19; i++) {
        cout << "   " << "\t\t\t\t\t\t\t\t\t\t" << "| ";

        for (int j = 0; j < 19; j++) {
            cout << map[i][j] << " | ";
        }
       
        cout <<endl<< "   " << "\t\t\t\t\t\t\t\t\t\t" << "-----------------------------------------------------------------------------" << endl;
    }

    return;
}

void winView() {
    //�ڴ˴���ɴ���
    cout << (flag % 2 == 0 ? "����Ӯ��" : "����Ӯ��") << endl;
    
    return;
}

void gameView() {
    //�ڴ˴���ɴ���
    int x = -1, y = -1;
    int ret = -1;

    init();

    while (1) {
        gameView_ShowMap();

        cout << "��ǰΪ" << (flag % 2 == 0 ? "����," : "����,") << "����������x y:";
        cin >> x >> y;
        while ((x < 0 || x>18) || (y < 0 || y>18)) {
            cout << "��������,���������:";

            // �������״̬
            cin.clear();

            // ���Ի������е���Ч����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cin >> x >> y;
        }

        while ((ret = playerMove(x, y)) == 0) {
            cout << "��ǰ������������,����������:";
            cin >> x >> y;
            while ((x < 0 || x>18) || (y < 0 || y>18)) {
                cout << "��������,���������:";

                // �������״̬
                cin.clear();

                // ���Ի������е���Ч����
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cin >> x >> y;
            }
        }
            
        if (isWin(x, y) != 0) {
            winView();
            init();
            system("pause");
            system("cls");

            return;
        }

        flag++;

        system("cls");
    }
}