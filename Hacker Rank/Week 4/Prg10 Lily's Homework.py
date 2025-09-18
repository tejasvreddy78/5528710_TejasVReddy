def count_swaps(arr, target):
    pos = {v: i for i, v in enumerate(arr)}
    visited = [False] * len(arr)
    swaps = 0

    for i in range(len(arr)):
        if visited[i] or arr[i] == target[i]:
            continue
        j = i
        cycle = 0
        while not visited[j]:
            visited[j] = True
            j = pos[target[j]]
            cycle += 1
        swaps += cycle - 1
    return swaps

def lilysHomework(arr):
    asc = sorted(arr)
    desc = asc[::-1]
    return min(count_swaps(arr[:], asc), count_swaps(arr[:], desc))