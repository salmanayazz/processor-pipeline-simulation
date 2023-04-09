#include <iostream>
#include <fstream>
#include <sstream>

#include "FileReader.h"
#include "InstructionNode.h"
#include "InstructionQueue.h"
#include "Simulator.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Usage: ./program path_to_trace_file start_instruction_# instruction_count" << endl;
        return 1;
    }

    string path = argv[1];
    int start_inst = atoi(argv[2]);
    int inst_count = atoi(argv[3]);
    int pipelineWidth = atoi(argv[4]);

    // Create a TraceFileParser object and parse the trace file
    FileReader parser = FileReader(path, atoi(argv[2]), atoi(argv[3]));

    // Get the parsed instructions and print them to the console
    InstructionQueue* instructionQueue = parser.getInstructions();
    parser.printInstructions();

    Simulator simulator = Simulator(instructionQueue, pipelineWidth);
    simulator.start();
    return 0;
}
