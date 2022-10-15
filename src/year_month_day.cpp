#include <iostream>
using namespace std;


class Date
{
        protected:
                int year, month, day;
                int days_month[12] = {31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        public:
                Date(int n1, int n2, int n3);
                void show();
};

//判断是否是闰年，更新月份天数数组
Date :: Date(int n1, int n2,int n3): year(n1), month(n2), day(n3)
{
        if(n1 % 4 == 0 && n1 % 100 != 0) 
                days_month[1] = 29;
        else 
                days_month[1] = 28;
};

void Date :: show()
{
        cout << year << "-" << month << "-" << day;
};


class WDate : public Date
{
        protected:
                int week;
                string weeks[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        public:
                WDate(int n1,int n2, int n3):Date(n1,n2,n3){ 
                        week = get_week(n1, n2, n3);};
                int get_week(int n1, int n2, int n3);
                void show();
                void add(int day_plus);
                void comparison(int n1, int n2, int n3);
                int get_day(int n1, int n2, int n3);
};

//获取星期的下标，公元第一天是星期一
//(day+1+2*month+3*(month+1)/5+year+year/4-year/100+year/400-1)%7
//(Day + 2*Month + 3*(Month+1)/5 + Year + Year/4 - Year/100 + Year/400) % 7
int WDate :: get_week(int n1, int n2, int n3)
{
        if(n2 == 1 || n2 == 2)
        {
                n2 += 12;
                n1 --;
        }
        // return (n3+1+2*n2+3*(n2+1)/5+n1+n1/4-n1/100+n1/400-1)%7;
        return (n3 + 2*n2 + 3*(n2+1)/5 + n1 + n1/4 - n1/100 + n1/400) % 7;
};


void WDate :: show()
{       
        Date :: show();
        cout << "(" << weeks[week] << ")" << endl;
}


//相加，先判断会不会加上月，再判断会不会过年，过年就更新月份数组
void WDate :: add(int day_plus)
{
        cout << "Beginning Date :";
        show();
        int n1 = year, n2 = month, n3 = day;
        n3 = n3+day_plus;
        int temp_week;
        if(n1 % 4 == 0 && n1 % 100 != 0) 
                days_month[1] = 29;
        else 
                days_month[1] = 28;
        while(n3 > days_month[n2 -1])
        {
                n3 -= days_month[n2 -1];
                if(n2 + 1 > 12)
                {
                        n1 ++;
                        n2 = 1;
                        if(n1 % 4 == 0 && n1 % 100 != 0) 
                                days_month[1] = 29;
                        else 
                                days_month[1] = 28;
                }
                else
                {
                        n2 ++;
                }

        }
        temp_week = get_week(n1, n2, n3);
        
        cout << "After " << day_plus << " days :";
        cout << n1 << "-" << n2 << "-" << n3;
        cout << "(" << weeks[temp_week] << ")" << endl;
};


//两种情况，同一年和不同年
void WDate :: comparison(int n1, int n2, int n3)
{
        int week_comp = get_week(n1, n2, n3);
        int max_year, min_year, max_month, min_month, max_day, min_day;
        int temp1 = n1*10000+ n2*100 + n3;
        int temp2 = year*10000 + month*100 + day;
        if(temp1 >= temp2)
        {
                max_year = n1, max_month = n2, max_day = n3;
                min_year = year, min_month = month, min_day = day;
        }
        else
        {
                max_year = year, max_month = month, max_day = day;
                min_year = n1, min_month = n2, min_day = n3;
        }
        int sum = 0;

        if(min_year ==  max_year)
        {
                if(min_year % 4 == 0 && min_year % 100 != 0)
                        days_month[1] = 29;
                else
                        days_month[1] = 28;
                for(int i = min_month; i < max_month - 1; i++)
                {
                        sum += days_month[month];
                }
                sum += days_month[min_month] - min_day;
                sum += max_day - 1;
        }
        else
        {
                for(int i = min_year + 1; i < max_year; i++)
                {
                        sum += get_day(i, 12, 31);
                }
                sum += get_day(min_year,12,31) - get_day(min_year, min_month, min_day);
                sum += get_day(max_year, max_month,max_day);
        }
        
        float d_week = (float)sum / 7.0;
        if(d_week - sum / 7 >= 0.5)
                d_week ++;


        cout << "Comparison Date : " << n1 << "-" << n2 << "-" << n3 << "(" << weeks[week_comp] << ")" << endl;
        cout << "Results: " <<  sum  << " days and " <<  int(d_week) << " weeks" << endl;
}


//获取该年到该天过了多少天
int WDate :: get_day(int n1, int n2, int n3)
{
        if(n1 % 4 == 0 && n1 % 100 != 0)
                days_month[1] = 29;
        else
                days_month[1] = 28;
        if(n2 == 12 && n3 == 31)
                return 337 + days_month[1];
        else
        {       int sum = 0;
                for(int i = 0; i < n2; i++)
                {
                        sum += days_month[i];
                }
                sum += n3;
                return sum;
        }
};


int main(void)
{

        WDate x(2022,10,15);
        // x.show();
        x.add(110);
        cout << endl;
        // x.show();
        x.comparison(2020,9,16);
        return 0;
}