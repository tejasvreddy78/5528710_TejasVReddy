from collections import defaultdict, deque

def roadsAndLibraries(n, c_lib, c_road, cities):
    if c_lib <= c_road:
        return n * c_lib

    graph = defaultdict(list)
    for u, v in cities:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * (n + 1)
    total_cost = 0

    def bfs(start):
        queue = deque([start])
        visited[start] = True
        size = 1
        while queue:
            node = queue.popleft()
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
                    size += 1
        return size

    for city in range(1, n + 1):
        if not visited[city]:
            comp_size = bfs(city)
            total_cost += c_lib + (comp_size - 1) * c_road

    return total_cost