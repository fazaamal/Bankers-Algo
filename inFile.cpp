#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int i = 0;
const int P = 5, R = 3;

// Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int max[][R],
            int alloc[][R])
{
    int need[P][R];
    
    // Calculate Need (Need = Max - Allocation)
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Mark all processes as unfinish
    bool finish[P] = {0};

    // To store safe sequence
    int safeSeq[P];

    // Make a copy of available resources
    int work[R];
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    // While all processes are not finished or system is not in safe state.
    int count = 0;
    while (count < P)
    {
        // Find a process which is not finish and
        // whose needs can be satisfied with current work[] resources.
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0)
            {
                // Check if for all resources of current P need is less than work
                int j;
                for (j = 0; j < R; j++)
                {
                    if (need[p][j] > work[j])
                    {
                        break;
                    }
                }
                // cout << "Process " << processes[p] << " is finished." << endl;

                // If all needs of p were satisfied.
                if (j == R)
                {
                    // Add the allocated resources of current P to
                    // the available/work resources i.e.free the resources
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[p][k];

                    // Add this process to safe sequence.
                    safeSeq[count++] = p;

                    // Mark this p as finished
                    finish[p] = 1;
                    cout << "Process " << processes[p] << " is finished." << endl;

                    found = true;
                }
            }
        }

        // If we could not find a next process in safe sequence.
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }

    // If system is in safe state then safe sequence will be as below
    cout << "\nSystem is in safe state."
            "\nSafe sequence is: ";
    for (int i = 0; i < P; i++)
        cout << safeSeq[i] << " ";
	
	cout<<endl;
	
    return true;
}

bool isSafeUpdatedAlloc(int processes[], int avail[], int max[][R],
            int alloc[][R])
{
    int need[P][R];
    
    // Calculate Need (Need = Max - Allocation)
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Mark all processes as unfinish
    bool finish[P] = {0};

    // To store safe sequence
    int safeSeq[P];

    // Make a copy of available resources
    int work[R];
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    // While all processes are not finished or system is not in safe state.
    int count = 0;
    while (count < P)
    {
        // Find a process which is not finish and
        // whose needs can be satisfied with current work[] resources.
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0)
            {
                // Check if for all resources of current P need is less than work
                int j;
                for (j = 0; j < R; j++)
                {
                    if (need[p][j] > work[j])
                    {
                        break;
                    }
                }
                // cout << "Process " << processes[p] << " is finished." << endl;

                // If all needs of p were satisfied.
                if (j == R)
                {
                    // Add the allocated resources of current P to
                    // the available/work resources i.e.free the resources
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[p][k];

                    // Add this process to safe sequence.
                    safeSeq[count++] = p;

                    // Mark this p as finished
                    finish[p] = 1;

                    found = true;
                }
            }
        }

        // If we could not find a next process in safe sequence.
        if (found == false)
        {
        	cout << -1 << endl;
            return false;
        }
    }
	
	cout<< 0 << endl;
	
    return true;
}

int main()
{
    // ------------------- Open File and Assign to Respective Array -------------------------
    // Create input file obj
    fstream inputFile;
    string filename = "inputFile.txt";

    // Open file and read content
    inputFile.open(filename.c_str());

    int processes[] = {0, 1, 2, 3, 4};
    int max[P][R], alloc[P][R], allocCopy[P][R], avail[R];

    // Check Input file and assign to respective Array
    if (inputFile.is_open())
    {
        cout << "Reading File and Assigning content to respective arrays..." << endl;
        // Available Array
        while (i < 3)
        {
            inputFile >> avail[i];
            i++;
        }

        // Maximum Array
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                inputFile >> max[i][j];
            }
        }

        // Allocation Array
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                inputFile >> alloc[i][j];
            }
        }
        inputFile.close(); // Close file
    }
    else
    {
        cout << "File not found. Make sure inputFile.txt on the same directory";
    }

    // Check System is in safe state or not
    isSafe(processes, avail, max, alloc);
    
    while(true){
    	int threadNo;
    	
    	for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                allocCopy[i][j] = alloc[i][j];
            }
        }
        
    	cout << "Enter the process number and the new allocation values to check whether it will be successful: ";
    	cin >> threadNo;
    	for(int i=0; i<R; i++){
    		cin >> allocCopy[threadNo][i];
		}
		
		bool safe = isSafeUpdatedAlloc(processes, avail, max, allocCopy);

	}

    return 0;
}
