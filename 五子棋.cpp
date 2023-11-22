#include<iostream>
using namespace std;

// -------------------- 数据设计 --------------------
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
int map[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;
// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/*
    *难点1
    负责人: 张三
    功能: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/*
    负责人: 张三
    功能: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)
        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    功能: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
*/
void menuView();

/*
    负责人: 张三
    功能: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();

/*
    负责人: 张三
    功能: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    //menuView();

    

    int testflag = 0;
    //init测试代码
    
    init();
    if (flag != 0) {
        printf("init()错误");
        exit(0);
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (map[i][j]) {
                printf("init()错误");
                exit(0);
            }
        }
    }
    printf("init()测试成功\n");
    testflag++;
    

    //playerMove测试代码
    
    int result = 1;
    result &= playerMove(2, 2);
    result &= playerMove(2, 3);
    result &= playerMove(2, 4);
    result &= playerMove(2, 5);
    if (result != 1 || (map[2][2] && map[2][3] && map[2][4] && map[2][5]) != 1) {
        printf("playerMove()错误");
        exit(0);
    }
    flag = 1;
    result &= playerMove(2, 5);
    if (result != 0 || map[2][5] != 1) {
        printf("playerMove()错误");
        exit(0);
    }
    printf("playerMove()测试成功\n");
    testflag++;
    

    //isWin测试代码
    /*
    playerMove(2, 1);
    if (isWin(2, 1)) {
        printf("isWin()错误");
        exit(0);
    }
    playerMove(1, 0);
    playerMove(3, 2);
    playerMove(4, 3);
    playerMove(5, 4);
    if (isWin(1, 0) != 2) {
        printf("isWin()错误");
        exit(0);
    }
    printf("isWin()测试成功\n");
    testflag++;
    

    if (testflag == 3) {
        printf("service代码测试成功\n");
    }
    return 0;

    */
}

void init() {
    //在此处完成代码
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            map[i][j] = 0;
        }
    }

    flag = 0;

    return;
}

int isWin(int x, int y) {
    //在此处完成代码
    int win = flag % 2 == 0 ? 1: 2;

    int result = -1;

    //水平方向
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

    //竖直方向
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
    
    //左上->右下
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
        
    //右上->左下
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
    //在此处完成代码
    int select = -1;
        
    while (true) {
        cout << "1-进入游戏\t2-游戏设置\t3-退出游戏\n" << endl;
        cout << "请输入你的选择:";

        cin >> select;
        switch (select) {
        case 1:   //进入游戏
            system("cls");
            gameView();
            break;
        case 2:     //游戏设置
            cout << "敬请期待..." << endl;
            system("pause");
            system("cls");
            break;
        case 3:     //退出游戏
            system("pause");
            exit(0);
        default:    //其他
            cout << "输入有误,请从新输入!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return;
}

void gameView_ShowMap() {
    //打印棋盘
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
    //在此处完成代码
    cout << (flag % 2 == 0 ? "黑子赢了" : "白子赢了") << endl;
    
    return;
}

void gameView() {
    //在此处完成代码
    int x = -1, y = -1;
    int ret = -1;

    init();

    while (1) {
        gameView_ShowMap();

        cout << "当前为" << (flag % 2 == 0 ? "黑子," : "白子,") << "请输入坐标x y:";
        cin >> x >> y;
        while ((x < 0 || x>18) || (y < 0 || y>18)) {
            cout << "输入有误,请从新输入:";

            // 清除错误状态
            cin.clear();

            // 忽略缓冲区中的无效输入
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cin >> x >> y;
        }

        while ((ret = playerMove(x, y)) == 0) {
            cout << "当前坐标已有棋子,请重新输入:";
            cin >> x >> y;
            while ((x < 0 || x>18) || (y < 0 || y>18)) {
                cout << "输入有误,请从新输入:";

                // 清除错误状态
                cin.clear();

                // 忽略缓冲区中的无效输入
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