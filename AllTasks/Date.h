#include <string>

class Date {
 private:
  int days_in_month_[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year_, month_, day_;

 public:
  Date(int year, int month, int day) : year_(year), month_(month), day_(day) {
    if (IsLeap()) days_in_month_[2] = 29;
  };

  bool IsLeap() { return IsLeap(year_); }

  bool IsLeap(int year) {
    if ((year % 4 != 0) || (year % 100 == 0) && (year % 400 != 0)) return false;
    return true;
  }

  std::string ToString() {
    auto to_date = [](int num, bool year) {
      auto str = std::to_string(num);
      if (year) {
        int amount = 4 - str.size();
        for (int i(0); i < amount; i++) str.insert(str.begin(), '0');
      } else {
        if (num < 10) str.insert(str.begin(), '0');
      }
      return str;
    };
    return to_date(day_, 0) + '.' + to_date(month_, 0) + '.' +
           to_date(year_, 1);
  }

  Date DaysLater(int days) {
    int new_year = year_, new_month = month_, new_day = day_;
    for (int i(0); i < days; i++) {
      new_day++;
      if (new_day > days_in_month_[new_month]) {
        new_day = 1;
        new_month++;
        if (new_month > 12) {
          new_month = 1;
          new_year++;
          if (IsLeap(new_year))
            days_in_month_[2] = 29;
          else
            days_in_month_[2] = 28;
        }
      }
    }
    return Date(new_year, new_month, new_day);
  }

  int DaysLeft(Date date) {
    int days_left = 0, new_year = year_, new_month = month_, new_day = day_;
    while (date.day_ != new_day || date.month_ != new_month ||
           date.year_ != new_year) {
      days_left++;
      new_day++;
      if (new_day > days_in_month_[new_month]) {
        new_day = 1;
        new_month++;
        if (new_month > 12) {
          new_month = 1;
          new_year++;
          if (IsLeap(new_year))
            days_in_month_[2] = 29;
          else
            days_in_month_[2] = 28;
        }
      }
    }
    return days_left;
  }
};
