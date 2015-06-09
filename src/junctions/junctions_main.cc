/*  junctions_main.cc -- handle the 'junction' commands

    Copyright (c) 2015, The Griffith Lab

    Author: Avinash Ramu <aramu@genome.wustl.edu>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.  */

#include <iostream>
#include <getopt.h>
#include "junctions_annotator.h"

using namespace std;

//Usage for junctions subcommands
int junctions_usage() {
    cout << "\nUsage:\t\t" << "regtools junctions <command> [options]";
    cout << "\nCommand:\t" << "annotate\tAnnotate the junctions.";
    cout << "\n";
    return 0;
}

//Run 'junctions annotate' subcommand
int annotate_junctions(int argc, char *argv[]) {
    JunctionsAnnotator anno;
    anno.parse_options(argc, argv);
    cout << endl << anno.get_reference_sequence("22:12000000-12000400");
    return 0;
}

//Parse out subcommands under junctions
int junctions_main(int argc, char *argv[]) {
    if(argc > 1) {
        string subcmd(argv[1]);
        if(subcmd == "annotate") {
            return annotate_junctions(argc - 1, argv + 1);
        }
    }
    return junctions_usage();
}

