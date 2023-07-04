
distances_h = [
    [0,    20,   37.0, 49.6, 72.8, 77.6, 71.6, 50.8, 35.2, 18.2, 33.4, 54.6, 55.2, 59.6], # E1
    [20,   0,    17.0, 29.6, 53.2, 58.2, 52.2, 34.6, 20.0, 7.0,  31.0, 41.8, 38.2, 43.6], # E2
    [37.0, 17.0, 0,    12.6, 36.4, 41.2, 35.2, 27.2, 18.8, 20.6, 39.0, 38.2, 24.2, 33.2], # E3
    [49.6, 29.6, 12.6, 0,    24.0, 28.8, 23.0, 24.8, 25.2, 33.4, 47.2, 37.2, 21.2, 30.8], # E4
    [72.8, 53.2, 36.4, 24.0, 0,    6,    4.8,  38.8, 46.6, 56.4, 68.4, 49.6, 29.0, 35.8], # E5
    [77.6, 58.2, 41.2, 28.8, 6,    0,    6.6,  44.6, 51.4, 60.6, 73.4, 55.2, 30.4, 36.4], # E6
    [71.6, 52.2, 35.2, 23.0, 4.8,  6.6,  0,    40.0, 46.0, 54.6, 68.4, 51.4, 24.8, 31.2], # E7
    [50.8, 34.6, 27.2, 24.8, 38.8, 44.6, 40.0, 0,    16.4, 40.6, 32.2, 12.8, 45.4, 55.2], # E8
    [35.2, 20.0, 18.8, 25.2, 46.6, 51.4, 46.0, 16.4, 0,    27.0, 22.4, 21.8, 42.4, 53.2], # E9
    [18.2, 7.0,  20.6, 33.4, 56.4, 60.6, 54.6, 40.6, 27.0, 0,    35.2, 48.4, 37.4, 42.4], # E10
    [33.4, 31.0, 39.0, 47.2, 68.4, 73.4, 68.4, 32.2, 22.4, 35.2, 0,    28.4, 63.0, 71.0], # E11
    [54.6, 41.8, 38.2, 37.2, 49.6, 55.2, 51.4, 12.8, 21.8, 48.4, 28.4, 0,    57.6, 67.2], # E12
    [55.2, 38.2, 24.2, 21.2, 29.0, 30.4, 24.8, 45.4, 42.4, 37.4, 63.0, 57.6, 0,    10.2], # E13
    [59.6, 43.6, 33.2, 30.8, 35.8, 36.4, 31.2, 55.2, 53.2, 42.4, 71.0, 67.2, 10.2, 0]     # E14
]

distances_g = {
    1 : [(2, 20, 'azul')], #'2' refere-se a E2
    2 : [(3, 17, 'azul'), (1, 20, 'azul'), (9, 20, 'amarela'), (10, 7, 'amarela')], #'3' refere-se a E3; '1' refere-se a E1; '9' refere-se a E9;
    3 : [(2, 17, 'azul'), (4, 12.6, 'azul'), (9, 18.8, 'vermelha'), (13, 37.4, 'vermelha')],
    4 : [(3, 12.6, 'azul'), (5, 26, 'azul'), (8, 30.6, 'verde'), (13, 25.6, 'verde')],
    5 : [(4, 26, 'azul'), (6, 6, 'azul'), (7, 4.8, 'amarela'), (8, 60, 'amarela')],
    6 : [(5, 6, 'azul')],
    7 : [(5, 4.8, 'amarela')],
    8 : [(5, 60, 'amarela'), (4, 30.6, 'verde'), (9, 19.2, 'amarela'), (12, 12.8, 'verde')],
    9 : [(8, 19.2, 'amarela'), (2, 20, 'amarela'), (3, 18.8, 'vermelha'), (11, 24.4, 'vermelha')],
    10: [(2, 7, 'amarela')],
    11: [(9, 24.4, 'vermelha')],
    12: [(8, 12.8, 'verde')],
    13: [(3, 37.4, 'vermelha'), (4, 25.6, 'verde'), (14, 10.2, 'verde')],
    14: [(13, 10.2, 'verde')]
    }


def get_neighbors(nodes: tuple, graph: dict):
    if nodes in graph:
        return graph[nodes]
    else:
        return None


def astar(graph: dict, heuristic: list, start_point: tuple, stop_point: tuple):
    frontier = [start_point]
    final_list = []

    g_sum = {}
    parents = {}

    g_sum[start_point] = 0
    parents[start_point] = start_point

    while len(frontier) > 0:
        prev = None

        for s in frontier:
            if prev is None or g_sum[s] + heuristic[s[0] - 1][stop_point[0] - 1] < g_sum[prev] + heuristic[prev[0] - 1][stop_point[0] - 1]:
                prev = s

        if prev == stop_point or graph[prev[0]] is None:

            pass

        else:

            for e, dist, line in get_neighbors(prev[0], graph):

                station = (e, line)

                if station not in frontier and station not in final_list:
                    frontier.append(station)

                    parents[station] = prev
                    g_sum[station] = g_sum[prev] + dist

                    if prev[1] != station[1]:
                        g_sum[station] += 4

                else:

                    if g_sum[station] > g_sum[prev] + dist:
                        g_sum[station] = g_sum[prev] + dist
                        parents[station] = prev

                        if e in final_list:
                            final_list.remove(station)
                            frontier.append(station)

        if prev is None:
            print("404 Not Found")
            return None

        if prev == stop_point:

            path = []
            while parents[prev] != prev:
                path.append(prev)
                prev = parents[prev]

            path.append(start_point)

            print(f"Path: {path.reverse()}")
            print(f"Tempo final: {g_sum[s] + heuristic[s[0] - 1][stop_point[0] - 1]}  min")

            return path

        frontier.remove(prev)
        final_list.append(prev)

    print("404 Not Found, try again")

    return None


def main():
    astar(distances_g, distances_h, (6, "azul"), (13, "verde"))

main()
