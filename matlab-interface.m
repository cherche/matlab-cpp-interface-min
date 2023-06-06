mex -setup cpp;
libName = "rops";
libFile = "/Users/ryan/Documents/MATLAB/test/bin/librops.dylib";
headerFile = "/Users/ryan/Documents/MATLAB/test/include/librops.h";
clibgen.generateLibraryDefinition(headerFile, "Libraries", libFile, "PackageName", libName);
