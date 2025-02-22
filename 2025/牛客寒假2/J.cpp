#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

// 将时间转化为总秒数便于比较
int timeToSeconds(const string& time) {
    int h, m, s;
    sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

// 判断一个时间点是否在给定的时间段内
bool inTimeRange(const string& time, const string& start, const string& end) {
    int t = timeToSeconds(time);
    int s = timeToSeconds(start);
    int e = timeToSeconds(end);
    if (s <= e) {
        return t >= s && t <= e;
    } else {
        return t >= s || t <= e; // 处理跨午夜的时间段
    }
}

int main() {
    int n, h, m;
    cin >> n >> h >> m;

    // 转换为字符串以便比较年份和月份
    string year_month = to_string(h) + "-" + (m < 10 ? "0" : "") + to_string(m);

    // 定义三个时间段的范围
    string commute_start1 = "07:00:00", commute_end1 = "09:00:00";
    string commute_start2 = "18:00:00", commute_end2 = "20:00:00";
    string lunch_start = "11:00:00", lunch_end = "13:00:00";
    string sleep_start = "22:00:00", sleep_end = "01:00:00";

    set<string> commute_users, lunch_users, sleep_users;

    for (int i = 0; i < n; ++i) {
        string user_id, login_date, login_time;
        cin >> user_id >> login_date >> login_time;

        // 检查是否是指定的年份和月份
        if (login_date.substr(0, 7) != year_month) {
            continue;
        }

        // 判断登录时间属于哪个时间段
        if (inTimeRange(login_time, commute_start1, commute_end1) || inTimeRange(login_time, commute_start2, commute_end2)) {
            commute_users.insert(user_id);
        } else if (inTimeRange(login_time, lunch_start, lunch_end)) {
            lunch_users.insert(user_id);
        } else if (inTimeRange(login_time, sleep_start, sleep_end)) {
            sleep_users.insert(user_id);
        }
    }

    // 输出结果
    cout << commute_users.size() << " " << lunch_users.size() << " " << sleep_users.size() << endl;
    return 0;
}
