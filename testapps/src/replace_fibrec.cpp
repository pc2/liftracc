#include "pin.H"
#include <iostream>
#include <fstream>

using namespace std;

static unsigned long long (*pf_fib_rec)(unsigned long long n);

INT32 Usage()
{
    cerr <<
        "This pin tool replaces methods using probes.\n"
        "\n";
    cerr << KNOB_BASE::StringKnobSummary();
    cerr << endl;
    return -1;
}

unsigned long long replaced_fibrec(unsigned long long n)
{
    unsigned long long c0=0;
    unsigned long long c1=1;
    unsigned long long ct=0;

    if (n<2) return n?1:0;

    n--;
    while(n) {
        ct=c1;
        c1=c0+c1;
        c0=ct;
        n--;
    }

    return c1;
}


// Called every time a new image is loaded
// Look for routines that we want to probe
VOID ImageLoad(IMG img, VOID *v)
{
    RTN fibrecRtn = RTN_FindByName(img, "_Z7fib_recy");

    if (RTN_Valid(fibrecRtn)) {
        if (!RTN_IsSafeForProbedReplacement(fibrecRtn)) {
            cout << "Cannot replace exit with my_exit in " << IMG_Name(img) << endl;
        } else {
            // Save the function pointer that points to the new location of
            // the entry point of the original exit in this image.
            pf_fib_rec = (unsigned long long (*)(unsigned long long)) RTN_ReplaceProbed(fibrecRtn, AFUNPTR(replaced_fibrec));        

            cout << "Inserted probe for fibrec() in:"  << IMG_Name(img) << " at address " << hex << RTN_Address(fibrecRtn) << dec << endl;
            cout << "Relocated entry point is at address " << hex << (ADDRINT)pf_fib_rec << dec << endl;
        }
        
    }
}

/* ===================================================================== */

int main(int argc, CHAR *argv[])
{
    
    PIN_InitSymbols();

    if (PIN_Init(argc,argv)) {
        return Usage();
    }

    IMG_AddInstrumentFunction(ImageLoad, 0);
    
    PIN_StartProgramProbed();
    
    return 0;
}

