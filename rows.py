with open("rows.txt") as file:
  lines = 0
  sum = 0
  n = 0
  for line in file:
    lines += 1
    if lines % 5 == 3:
      sum += float(line)
      n += 1
  print(sum / n)
