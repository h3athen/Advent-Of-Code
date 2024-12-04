import re

def part_one(line):
    sum=0
    matches = re.findall("mul\\(\\d+\\,\\d+\\)",line)  
    for match in matches:
        digits = (re.findall("\\d+",match))
        x,y = map(int, digits)
        sum += x*y
    print("Part 1:",sum)


def main():
    with open('input.txt', 'r') as input:
        line = input.read().strip()

    part_one(line)

if __name__ == "__main__":
    main()