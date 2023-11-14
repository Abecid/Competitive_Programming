def count_numbers(sorted_list, less_than):
  less_index = -1
  greater_index = len(sorted_list)
  mid = len(sorted_list) // 2
  while(greater_index-less_index != 1):
    if sorted_list[mid] >= less_than:
      greater_index = mid
    else:
      less_index = mid
    mid = (greater_index + less_index) // 2
  return less_index + 1

if __name__ == "__main__":
  sorted_list = [1, 3, 5, 7]
  print(count_numbers(sorted_list, 4)) # should print 2