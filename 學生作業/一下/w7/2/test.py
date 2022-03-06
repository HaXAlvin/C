i = 2
for i in (0, 1, 2, 3, 4):
    print(i)
    if i >= 0:
        i = 66
        print(i)
print(i)
# >> 0 66 1 66 2 66 3 66 4 66 66
