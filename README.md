# SlicingCBMC
Source code and binary file for Mac OSX(named cbmc): https://www.dropbox.com/s/gq97ynyn58nwdfs/source%20code%20slicing%20cbmc.zip?dl=0

Requirement:
  - CBMC 5.1: http://www.cprover.org/cbmc/

Install:
  - Import project to Eclipse CDT
  - Compile
  - And run with option: --no-unwinding-assertions --unwind 5 --all-properties [C file name]
Several test files are provided in the folder SlicingCBMC/src/tests/pthread-wmm/
