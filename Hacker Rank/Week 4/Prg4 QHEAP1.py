import sys, heapq

def process_queries(queries):
    min_heap = []
    pending_delete = set()
    results = []

    for q in queries:
        if q[0] == 1:
            heapq.heappush(min_heap, q[1])
        elif q[0] == 2:
            pending_delete.add(q[1])
        else:
            while min_heap and min_heap[0] in pending_delete:
                pending_delete.remove(min_heap[0])
                heapq.heappop(min_heap)
            results.append(min_heap[0])
    return results


if __name__ == "__main__":
    data = sys.stdin.read().strip().split("\n")
    t = int(data[0])
    queries = []
    for i in range(1, t + 1):
        parts = data[i].split()
        if len(parts) == 1:
            queries.append((3, 0))
        else:
            queries.append((int(parts[0]), int(parts[1])))

    output = process_queries(queries)
    print("\n".join(map(str, output)))