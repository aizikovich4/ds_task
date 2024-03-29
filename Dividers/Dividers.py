import sys, getopt,os
import prime_divides

sys.path.append(os.getcwd())

class PrimeDivide:
    def __init__(self, input, output):
        self.inputFile = input
        self.outputFile = output
        self.numbers =[]

        try:
            array = []
            with open(self.inputFile, 'r') as f:
                for line in f:
                    try:
                        array.append(int(line))
                    except ValueError:
                        pass
            array = list(dict.fromkeys(array))
            self.numbers = array
        except IOError:
            print("Input file not accessible: "+self.inputFile)

    def run(self):
        if not self.numbers:
            return

        current_counter = 0
        size = len(self.numbers)
        with open(self.outputFile, 'w') as out:
            for number in self.numbers:
                divs = prime_divides.get_divides(number)
                if not divs:
                    continue
                current_counter += 1
                current_percent = current_counter / size * 100
                print(str(round(current_percent, 3)) + "%")
                out.write(str(number) + " = 1")
                for d in divs:
                    out.write("*" + str(d))
                out.write("\n")
        print("100%")

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


def main(argv):
    inputFile, outputFile = check_params(argv)
    dividersTest = PrimeDivide(inputFile, outputFile)
    dividersTest.run()


if __name__ == "__main__":
    if len(sys.argv) < 5:
        print("use next parameters: -i <inputfile> -o <outputfile>")
        sys.exit(1)
    main(sys.argv[1:])
