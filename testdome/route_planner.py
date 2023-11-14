from collections import deque

def route_exists(from_row, from_column, to_row, to_column, map_matrix):
  if map_matrix[from_row][from_column] is False or map_matrix[to_row][to_column] is False:
    return False

  visited_matrix = [[False for _ in row] for row in map_matrix]

  to_visit = deque()

  to_visit.append((from_row, from_column))

  while(len(to_visit) > 0):
    current_row, current_column = to_visit.pop()
    if(current_row == to_row and current_column == to_column):
      return True
    visited_matrix[current_row][current_column] = True
    for i in [1, -1]:
      for j in ['x', 'y']:
        if(j == 'x'):
          next_row = current_row + i
          next_col = current_column
        else:
          next_col = current_column + i
          next_row = current_row
        if(next_row >= 0 and next_row < len(map_matrix) and next_col >= 0 and next_col < len(map_matrix[0]) and visited_matrix[next_row][next_col] is False and map_matrix[next_row][next_col] is True):
          to_visit.append((next_row, next_col))

  return False
  
  

if __name__ == '__main__':
  map_matrix = [
      [True, False, False],
      [True, True, False],
      [False, True, True]
  ];
  

  print(route_exists(0, 0, 2, 2, map_matrix))