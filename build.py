import os
import sys

compilecppfilename = sys.argv[1]
#print(compilecppfilename)
for root,dirs,files in os.walk(os.getcwd()):
    for file in files:
        if compilecppfilename + ".cpp" == file:
            os.system("g++ -std=c++17 {} -o output".format(os.path.join(root, file)))
            if os.path.exists('output'):
                os.system("./output")
                os.system("rm output")
            #print(os.path.join(root, file))



