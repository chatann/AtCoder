from datetime import datetime, timedelta

data = []
while True:
    try:
        line = input()
        if line:
            data.append(line)
        else:
            break
    except EOFError:
        break

start_time = None
tot_dist = 0
short_dist = None
long_dist = None
tmp_lowtime = 0

fare = 0
for line in data:
    time_str, dist = line.split()
    tot_dist += float(dist)
    # 24時以降の時間を0時から始まるようにする
    hour = float(time_str[:2])
    if hour >= 24:
        hour -= 24
        time_str = str(hour) + time_str[2:]
    current_time = datetime.strptime(time_str, "%H:%M:%S.%f")
    
    if start_time is None:
        start_time = current_time
        # 初乗り運賃
        if current_time.hour < 6:
            fare += 600
        elif current_time.hour < 9 or (current_time.hour == 9 and current_time.minute < 30):
            fare += 520
        else:
            fare += 400
    
    # 日をまたぐ場合を考慮
    if current_time < start_time:
        current_time += timedelta(days=1)
    elapsed_time = current_time - start_time

    add_fare = 0
    # 初乗距離区間
    if tot_dist <= 1000:
        add_fare = 0
    # 短距離区間
    elif tot_dist <= 10000:
        if short_dist is None:
            short_dist = tot_dist - 1000
        if short_dist > 400:
            add_fare += 40
            short_dist -= 400
    # 長距離区間
    else:
        if long_dist is None:
            long_dist = tot_dist - 10000
        if long_dist > 350:
            add_fare += 40
            long_dist -= 350

    # 低速運賃
    if elapsed_time.total_seconds() > 0:
        vel = float(dist) / elapsed_time.total_seconds() # m/s
        vel *= 3.6 # km/h
        if vel < 10:
            tmp_lowtime += elapsed_time.total_seconds()
            if tmp_lowtime >= 45:
                add_fare += 40
                tmp_lowtime -= 45

    # 深夜割増
    if current_time.hour < 6:
        add_fare *= 1.5
    # ピークタイム割増
    elif current_time.hour < 9 or (current_time.hour == 9 and current_time.minute < 30):
        add_fare *= 1.3

    fare += add_fare
    start_time = current_time

if fare >= 0:
    print(fare)