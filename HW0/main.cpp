/* This Program is the main entry point
 * in order to call insertion_sort
 */

#include <insertion_sort.cpp>

int main(int argc, char const *argv[])
{

    /**
     * YOUR CODE HERE
     * 1. Check for the number of arguments.
     * Only proceed if the number of argument is correct,
     * We will only check for ./main [INPUT_FILE] [OUTPUT_FILE]
     * 
     */

    if(argc != 3){
        cerr << "USAGE: ./main [INPUT_FILE] [OUTPUT_FILE]" << endl;
        exit(1);
    }

    //Read the file [INPUT_FILE]

    ifstream input;
    input.open(argv[1]);

    if(input.fail())
    {
        cerr << "Error: File did not work" << endl;
        exit(1);
    }

    else{
        //Build Int Sequence
        IntSequence A;
        input >> A.length;
        A.array = (int*)malloc(A.length * sizeof(int));

        for (int i = 0; i < A.length; i++)
        {
            input >> A.array[i];
        }

        //Run Insertion Sort
        insertion_sort(A);
        
        //Write the sort into [OUTPUT_FILE]
        ofstream output;
        output.open(argv[2], ios::out);

        if(!output.is_open())
        {
            cerr << "Failure to open output file" << endl;
            exit(1); 
        }

        for (int i = 0; i < A.length; i++)
        {
            output << A.array[i] << " ";
        }

        input.close();
        output.close();
    }

    return 0;
}
