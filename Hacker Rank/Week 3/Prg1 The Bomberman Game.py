def bomberMan(n, grid):
    r = len(grid)
    c = len(grid[0])

    if n == 1:
        return grid

    full = ['O' * c for _ in range(r)]

    def explode(current):
        output = [['O'] * c for _ in range(r)]
        for i in range(r):
            for j in range(c):
                if current[i][j] == 'O':
                    output[i][j] = '.'
                    if i > 0:
                        output[i-1][j] = '.'
                    if i < r-1:
                        output[i+1][j] = '.'
                    if j > 0:
                        output[i][j-1] = '.'
                    if j < c-1:
                        output[i][j+1] = '.'
        return [''.join(row) for row in output]

    first = explode(grid)
    second = explode(first)

    if n % 2 == 0:
        return full
    elif n % 4 == 3:
        return first
    else:  # n % 4 == 1
        return second

if __name__ == '__main__':
    r, c, n = map(int, input().split())
    grid = [input().strip() for _ in range(r)]
    result = bomberMan(n, grid)
    for row in result:
        print(row)