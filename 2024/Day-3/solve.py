import re

def part_one(line):
    sum=0
    matches = re.findall("mul\\(\\d+\\,\\d+\\)",line)  
    for match in matches:
        digits = (re.findall("\\d+",match))
        x,y = map(int, digits)
        sum += x*y
    print("Part 1:",sum)

def part_two(line):
    enable = True
    sum=0
    matches = re.findall("mul\\(\\d+\\,\\d+\\)|don't\\(\\)|do\\(\\)",line)
    for match in matches:
        if match == "do()":
            enable = True
        elif match == "don't()":
            enable = False
        else:
            if enable:
                digits = (re.findall("\\d+",match))
                x,y = map(int, digits)
                sum += x*y
    print("Part 2:",sum)

def main():
    with open('input.txt', 'r') as input:
        line = input.read().strip()

    part_one(line)
    part_two(line)

if __name__ == "__main__":
    main()