import sys, getopt


def check_params(argv):
    try:
        opts, args = getopt.getopt(argv, "hi:o:", ["ifile=", "ofile="])
    except getopt.GetoptError:
        print 'test.py -i <inputfile> -o <outputfile>'
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print 'test.py -i <inputfile> -o <outputfile>'
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-o", "--ofile"):
            outputfile = arg

    if not inputfile \
            or not outputfile:
        print 'use next parameters: -i <inputfile> -o <outputfile>'
        exit(1)
    return inputfile, outputfile


def read_values(inputFile):
    try:
        array = []
        # array = [line.rstrip('\n') for line in open(inputFile)]
        # return array
        with open(inputFile, 'r') as f:
            for line in f:
                try:
                    array.append(int(line))
                except ValueError:
                    pass
                    #print("Is not a number: "+line)
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

    print("Numbers for checking:")
    print(values)

if __name__ == "__main__":
    main(sys.argv[1:])
