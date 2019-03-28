import re
import random
import sys
from collections import OrderedDict

fl = open("obfs/keyload.txt", "r") 
data = fl.read()# loading book
data = re.sub(r'[^a-zA-Z \n]', '', data).lower()
data = data.split(' ')

for i in range(len(data)): #cleaning book
    data[i] = re.sub('\t', '', data[i])
    data[i] = re.sub('\n', '', data[i])
while('' in data) : 
    data.remove('')

keywords = ['auto', 'a', 'break', 'const', 
'continue', 'do', 'else', 'enum', 'extern', 'for', 
'goto', 'if','int', 'char', 'short', 'long', 'float', 'double', 'register', 'return', 'sizeof', 
'static', 'struct', 'typedef', 'union', 'void', 
'volatile', 'while'] # c keywords

with open(sys.argv[1], 'r') as algfile: #reading file to obfurcificate
    algdata=algfile.read()
akw = re.sub(r'[^a-zA-Z \n]', '', algdata).lower()
akw = re.sub('\n', ' ', akw)
akw = akw.split(' ')
while('' in akw) : 
    akw.remove('')
keywords = keywords + akw 
algdata = algdata.split('\n') #variable names

for word in keywords: #removing c keywords from dict
    try:
        data.remove(word)
    except ValueError:
        pass

for row in algdata:
    try: 
        if row[0] == '#':
            algdata.remove(row)
    except IndexError:
        pass

outdict = open("out.h", "w")
outfile = open("main.c", "w")
outfile.write("#include \"out.h\"\n")
outfile.write("#include <stdio.h>\n")

empties = []
outh = []
count = 0
for line in algdata:
    fakes = random.randrange(120)
    
    for a in range(fakes): #generating empty consts
        c = data[count+a] + ' '
        if a < fakes/10:
            h = "#define " + data[count + a]+'\n'
        else:
            h = "#define " + data[count + a]+' ' + empties[random.randrange(len(empties))]+'\n'
        outh.append(h)
        outfile.write(c);
        empties.append(data[count+a])
    count = count + fakes
    c = data[count] + ' ' #to main file
    h = "#define " + data[count] + " " + line + "\n" #to dictionary
    outh.append(h)
    outfile.write(c);
    count += 1
    

outh = list(dict.fromkeys(outh))
ouths = ""
for h in outh:
    ouths = ouths + h
outdict.write(ouths);
outdict.close();
outfile.close();