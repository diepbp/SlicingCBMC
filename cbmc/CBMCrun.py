from os import path
import sys, getopt
import re
import argparse
import platform
import os.path
import subprocess
import commands

from subprocess import call
# Store input and output file names
i1file='_thin1.txt'
i2file='_thin2.txt'
number = ''
typeTest = 'rfi'
# Read command line args
myopts, args = getopt.getopt(sys.argv[1:],"i:")
 
###############################
# o == option
# a == argument passed to the o
###############################
for o, a in myopts:
    if o == '-i':
         number = a
         i1file = a + i1file
         i2file = a + i2file
    else:
         print("Usage: %s -i input" % sys.argv[0])
 
	# Display input and output file name passed as the args
print ("Input file : %s " % (i1file) )

fileName1 = '/Users/diepbp/Documents/workspace/SlicingCBMC/test/pthread-wmm/' + typeTest + number + '_power.oepc_true-unreach-call.c'
fileName2 = '/Users/diepbp/Documents/workspace/SlicingCBMC/test/pthread-wmm/' + typeTest + number + '_power.opt_true-unreach-call.c'
fileName3 = '/Users/diepbp/Documents/workspace/SlicingCBMC/test/pthread-wmm/' + typeTest + number + '_pso.oepc_true-unreach-call.c'
fileName4 = '/Users/diepbp/Documents/workspace/SlicingCBMC/test/pthread-wmm/' + typeTest + number + '_pso.opt_true-unreach-call.c'
fileName5 = '/Users/diepbp/Documents/workspace/SlicingCBMC/test/pthread-wmm/' + typeTest + number + '_rmo.oepc_true-unreach-call.c'
fileName6 = '/Users/diepbp/Documents/workspace/SlicingCBMC/test/pthread-wmm/' + typeTest + number + '_rmo.opt_true-unreach-call.c'
fileName7 = '/Users/diepbp/Documents/workspace/SlicingCBMC/test/pthread-wmm/' + typeTest + number + '_tso.oepc_true-unreach-call.c'
fileName8 = '/Users/diepbp/Documents/workspace/SlicingCBMC/test/pthread-wmm/' + typeTest + number + '_tso.opt_true-unreach-call.c'

command1 = ['time', 'cbmc', '--no-unwinding-assertions', fileName1]
command2 = ['time', 'cbmc', '--no-unwinding-assertions', fileName2]
command3 = ['time', 'cbmc', '--no-unwinding-assertions', fileName3]
command4 = ['time', 'cbmc', '--no-unwinding-assertions', fileName4]
command5 = ['time', 'cbmc', '--no-unwinding-assertions', fileName5]
command6 = ['time', 'cbmc', '--no-unwinding-assertions', fileName6]
command7 = ['time', 'cbmc', '--no-unwinding-assertions', fileName7]
command8 = ['time', 'cbmc', '--no-unwinding-assertions', fileName8]

with open(i1file, "a") as outfile, open(i2file, "a") as errfile:
	p = subprocess.call(command1, stdout=outfile, stderr=errfile)
with open(i1file, "a") as outfile, open(i2file, "a") as errfile:
	p = subprocess.call(command2, stdout=outfile, stderr=errfile)
with open(i1file, "a") as outfile, open(i2file, "a") as errfile:
	p = subprocess.call(command3, stdout=outfile, stderr=errfile)
with open(i1file, "a") as outfile, open(i2file, "a") as errfile:
	p = subprocess.call(command4, stdout=outfile, stderr=errfile)
with open(i1file, "a") as outfile, open(i2file, "a") as errfile:
	p = subprocess.call(command5, stdout=outfile, stderr=errfile)
with open(i1file, "a") as outfile, open(i2file, "a") as errfile:
	p = subprocess.call(command6, stdout=outfile, stderr=errfile)
with open(i1file, "a") as outfile, open(i2file, "a") as errfile:
	p = subprocess.call(command7, stdout=outfile, stderr=errfile)
with open(i1file, "a") as outfile, open(i2file, "a") as errfile:
	p = subprocess.call(command8, stdout=outfile, stderr=errfile)