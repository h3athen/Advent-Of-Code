def part_one(left, right):
    total = 0
    left  = sorted(left)
    right = sorted(right)
    total = sum(abs(l - r) for l,r in zip(left,right))
    print("part one:",total)

def part_two(left, right):
    total = 0
    for i in left:
        total += i * right.count(i)
    print("part two:",total)
        

def main():
    left, right = [],[]
    with open('input.txt', 'r') as input:
        for line in input.readlines():
            x, y = (int(value) for value in line.split())
            left.append(x)
            right.append(y)
    
    part_one(left, right)
    part_two(left, right)

if __name__ == "__main__":
    main()