#include"CScreen.h"
#include "CMobilePhone.h"
#include "CPerson.h"
using namespace std;
//参考的main函数，可以根据自己的情况修改
int main() {
    // 创建一个手机对象，带完整参数（包含屏幕参数），打印，
    CMobilePhone phoneA
    (
        "小米手机A",            // 手机名
        "Xiaomi 14",              // 型号
        15.26,                         // 长
        7.13,                           // 宽
        0.82,                           // 厚
        "张三",                       // 使用人s
        "13800138000",       // 手机号
        6.36,                           // 屏幕尺寸
        "2670x1200",            // 分辨率
        "AMOLED",               // 技术类型
        "三星",                      // 厂家
        "Xiaomi 14"              // 适配型号
    );

    CPerson xiaoqiang("王小强", 18, true, &phoneA);// 创建一个人对象，拥有手机A
    CPerson uncle("王叔叔", 45, true, NULL);

    xiaoqiang.whoareyou();
    uncle.whoareyou();

    cout << endl;
    xiaoqiang.callsomeone(&uncle);

    cout << endl;
    cout << "王小强把手机A送给了王叔叔。" << endl;
    uncle.setPhone(xiaoqiang.getPhone());
    xiaoqiang.setPhone(NULL);
    phoneA.setUser("王叔叔");

    CMobilePhone phoneB(
        "华为手机B",
        "Huawei Pura80",
        16.35,
        7.48,
        0.82,
        "王小强",
        "13900139000",
        6.7,
        "3200*1440",
        "OLED",
        "京东方",
        "Huawei Pura80"
    );

    cout << endl;
    cout << "王小强获得了一部新手机B。" << endl;
    xiaoqiang.setPhone(&phoneB);

    cout << endl;
    xiaoqiang.callsomeone(&uncle);
    uncle.callsomeone(&xiaoqiang);

    return 0;
}
