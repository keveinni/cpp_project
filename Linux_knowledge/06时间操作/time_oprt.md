# 时间操作

# 数据类型

1. **time_t**
定义在<time.h>头文件中，是一个long类型的别名。

2. ** tm结构体** 
定义在<time.h>中。
```
struct tm
{
  int tm_year;	// 年份：其值等于实际年份减去1900
  int tm_mon;	// 月份：取值区间为[0,11]，其中0代表一月，11代表12月
  int tm_mday;	// 日期：一个月中的日期，取值区间为[1,31]
  int tm_hour; 	// 时：取值区间为[0,23]
  int tm_min;	// 分：取值区间为[0,59]
  int tm_sec;     	// 秒：取值区间为[0,59]
  int tm_wday;	// 星期：取值区间为[0,6]，其中0代表星期天，6代表星期六
  int tm_yday;	// 从每年的1月1日开始算起的天数：取值区间为[0,365] 
  int tm_isdst;   // 夏令时标识符，该字段意义不大
};

```


## 实用函数

1. time()函数

```
time_t now = time(0); //获取操作系统当前时间

或者

time_t now;
time(&now);
```

2. localtime()
将time_t格式转换为tm格式,包含在time.h。

```
localtime_r(const time_t *timep, struct tm *result)
```

3. mktime()
将tm格式转换为time_t格式，包含在time.h

```
time_t mktime(struct tm *tm)
```

4. sleep()
睡眠函数，包含在<unistd.h>

```
unsigned int sleep(unsigned int seconds);

```