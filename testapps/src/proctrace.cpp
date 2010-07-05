//
// This tool counts the number of a routine is executed and counts
// the number of instructions executed in a routine
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "pin.H"

KNOB<string> KnobOutputFile(KNOB_MODE_WRITEONCE, "pintool", "f", "proctrace.out", "specify output file name");
KNOB<string> KnobLibMatchStr(KNOB_MODE_WRITEONCE, "pintool", "l", "", "library match string");
KNOB<string> KnobProcMatchStr(KNOB_MODE_WRITEONCE, "pintool", "p", "", "procedure match string");

ofstream output;

string last_lib;
string lib_match_str;
string proc_match_str;

VOID print_rtn(string* library, string* proc_name, ADDRINT* addr) {
    if ((library->find(lib_match_str)!=string::npos) && (proc_name->find(proc_match_str)!=string::npos)) {
        output << *library << endl;
        output << "  " << *proc_name << endl;
    }
}

// Pin calls this function every time a new rtn is executed
VOID Routine(RTN rtn, VOID *v) {
    RTN_Open(rtn);
    // Insert a call at the entry point of a routine to increment the call count
    RTN_InsertCall(rtn, IPOINT_BEFORE, (AFUNPTR)print_rtn,
                   IARG_PTR, new string(IMG_Name(SEC_Img(RTN_Sec(rtn)))),
                   IARG_PTR, new string(RTN_Name(rtn)),
                   IARG_PTR, new ADDRINT(RTN_Address(rtn)),
                   IARG_END);
    RTN_Close(rtn);
}

INT32 Usage() {
    cerr << "This tool produces a trace of calls.\n\n";
    cerr << KNOB_BASE::StringKnobSummary();
    cerr << endl;
    
    return -1;
}

// This function is called when the application exits
// It prints the name and count for each procedure
VOID Fini(INT32 code, VOID *v) {
    output.close();
}

// argc, argv are the entire command line, including pin -t <toolname> -- ...
int main(int argc, char * argv[]) {
    // Initialize pin
    if (PIN_Init(argc,argv))
        return Usage();

    // Initialize parameter
    lib_match_str = KnobLibMatchStr.Value();
    proc_match_str = KnobProcMatchStr.Value();
    output.open(KnobOutputFile.Value().c_str());

    output << showbase << hex;

    // Initialize symbol table code, needed for rtn instrumentation
    PIN_InitSymbols();

    // Register Routine to be called to instrument rtn
    RTN_AddInstrumentFunction(Routine, 0);

    // Register Fini to be called when the application exits
    PIN_AddFiniFunction(Fini, 0);
    
    // Start the program, never returns
    PIN_StartProgram();
    
    return 0;
}

