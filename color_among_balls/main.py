def queryResults(limit, queries):
    ball_colors = {}
    color_count = {}
    unique_colors_count = 0
    result = []

    for x, y in queries:
        if x in ball_colors:
            old_color = ball_colors[x]
            color_count[old_color] -= 1
            if color_count[old_color] == 0:
                unique_colors_count -= 1
                
        ball_colors[x] = y

        if y in color_count:
            if color_count[y] == 0:
                unique_colors_count += 1
            color_count[y] += 1
        else:
            color_count[y] = 1
            unique_colors_count += 1

        result.append(unique_colors_count)

    return result

def main():
    limit = int(input("Enter limit: "))
    n = int(input("Enter number of queries: "))
    
    queries = []
    print("Enter queries (ball color):")
    for _ in range(n):
        x, y = map(int, input().split())
        queries.append([x, y])

    results = queryResults(limit, queries)

    print("Results:", results)

if __name__ == "__main__":
    main()
