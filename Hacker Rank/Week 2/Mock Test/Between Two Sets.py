def getTotalX(a, b):
    count = 0
    start = max(a)
    end = min(b)

    for val in range(start, end + 1):
        valid = True
        for x in a:
            if val % x != 0:
                valid = False
                break

        if valid:
            for y in b:
                if y % val != 0:
                    valid = False
                    break

        if valid:
            count += 1

    return count