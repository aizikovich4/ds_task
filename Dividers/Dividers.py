import sys, getopt
import prime_divides
import time
from threading import Thread

class PrintProcess(Thread):
    def __init__(self, count):
        Thread.__init__(self)
        self.count = count
        self.current_percent =0
    def set(self, current):
        if current:
            self.current_percent = self.count/100 * current
    def run(self):
        old_percent = self.current_percent
        while 1 or self.current_percent != 100:
            if old_percent != self.current_percent:
                print(self.current_percent)
                old_percent = self.current_percent
                time.sleep(10)

def check_params(argv):
    try:
        opts, args = getopt.getopt(argv, "hi:o:", ["ifile=", "ofile="])
    except getopt.GetoptError:
        print("test.py -i <inputfile> -o <outputfile>")
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print("use next parameters: -i <inputfile> -o <outputfile>")
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-o", "--ofile"):
            outputfile = arg

    if not inputfile \
            or not outputfile:
        print("use next parameters: -i <inputfile> -o <outputfile>")
        exit(1)
    return inputfile, outputfile


def read_values(inputFile):
    try:
        array = []
        with open(inputFile, 'r') as f:
            for line in f:
                try:
                    array.append(int(line))
                except ValueError:
                    pass
        # array = list(dict.fromkeys(array))
        return array
    except IOError:
        print("Input file not accessible: "+inputFile)
        return


def main(argv):
    inputFile, outputFile = check_params(argv)
    print("Input file: "+ inputFile)
    print("Output file: "+ outputFile)

    values = read_values(inputFile)
    if not values:
        exit(1)

    current_counter = 0
    with open(outputFile, 'w') as out:
        for number in values:
            divs = prime_divides.get_divides(number)
            if not divs:
                continue
            current_counter += 1
            current_percent = current_counter/len(values) * 100
            print(str(round(current_percent, 3))+"%")
            out.write(str(number)+" = 1")
            for d in divs:
                out.write("*"+str(d))
            out.write("\n")
    print("100%")

if __name__ == "__main__":
    if len(sys.argv) < 5:
        print("use next parameters: -i <inputfile> -o <outputfile>")
        sys.exit(1)
    main(sys.argv[1:])
