#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from pycparser import c_parser, c_ast, parse_file

class FuncDeclVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.wso = ""

    def wso_add(self):
        self.wso = self.wso + "  "

    def wso_sub(self):
        self.wso = self.wso[0:-2]

    def visit_FuncDecl(self, node):
        self.wso_add()
        if type(node).__name__ == "FuncDecl":
            if type(node.type).__name__ == "TypeDecl":
                func_name = node.type.declname
            func_str = "<function name=\"" + func_name.replace("cublas", "").lower() + "\" type=\""
            for q in node.type.quals: func_str = func_str + n.upper() + "_"
            for n in node.type.type.names: func_str = func_str + n.replace("cu","").upper() + "_"
            func_str = func_str + "TYPE\">"
            print self.wso + func_str
            
            if type(node.args).__name__ == "ParamList":
                self.wso_add()
                for p in node.args.params:
                    if type(p).__name__ == "EllipsisParam":
                        param_str = "<params/>"
                    else:
                        param_str = "<param name=\"" + p.name.lower() + "\" type=\""
                        type_str = ""
                        for s in p.storage: type_str = type_str + s.upper() + "_"
                        for q in p.quals: type_str = type_str + q.upper() + "_"
                        if type(p.type).__name__ == "TypeDecl":
                            for n in p.type.type.names: type_str = type_str + n.replace("cu","").upper() + "_"
                        elif type(p.type).__name__ == "PtrDecl":
                            type_str = "PTR_" + type_str + p.type.type.type.names[0].replace("cu","").upper() + "_"
                        param_str = param_str + type_str + "TYPE\"/>"
                    print self.wso + param_str
                self.wso_sub()
            
            print self.wso + "</function>"
        self.wso_sub()

def generate_xml(filename):
    ast = parse_file(filename, use_cpp=True)
    visitor = FuncDeclVisitor()
    print "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    print "<blas_functions>"
    visitor.visit(ast)
    print "</blas_functions>"

def usage():
    print "usage:", sys.argv[0], "path/to/cblas.h"
    print

if __name__ == "__main__":
    if len(sys.argv) == 2:
        generate_xml(sys.argv[1])
    else:
        usage()

