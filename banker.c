//Damien Olsen Spring 2023
#include <stdio.h>
int main(){
    int num_proc, num_res, proc_id, res_id, safe_seq;
    FILE *input_file;
    input_file = fopen("input.txt", "r");
	
    // This reads in the first two numbers to determine the number of processes and resources
    
	fscanf(input_file, "%d%d", &num_proc, &num_res);
    
	// Instantiation of the allocated, max and available processes/resources
	int alloc[num_proc][num_res], max[num_proc][num_res], avail[num_res];
    
	// These for loops read what is in the file into the arrays that can be used for the bankers problem
    // Scans in the allocation matrix
    for (proc_id = 0; proc_id < num_proc; proc_id++) {
        for (res_id = 0; res_id < num_res; res_id++)
            fscanf(input_file, "%d", &alloc[proc_id][res_id]);
    }
    
	// Scans in the max matrix
    for (proc_id = 0; proc_id < num_proc; proc_id++) {
        for (res_id = 0; res_id < num_res; res_id++)
            fscanf(input_file, "%d", &max[proc_id][res_id]);
    }
    
	// Scans in for available resources
    for (res_id = 0; res_id < num_res; res_id++) {
        fscanf(input_file, "%d", &avail[res_id]);
    }
    
	// Close the file after reading in all of the data
    fclose(input_file);
    int finish[num_proc], ans[num_proc], ind = 0;
    for (safe_seq = 0; safe_seq < num_proc; safe_seq++) {
        finish[safe_seq] = 0;
    }
    
	// Creates and array for the need matrix, which will help calculate the need of each process
    int need[num_proc][num_res];
    for (proc_id = 0; proc_id < num_proc; proc_id++) {
        for (res_id = 0; res_id < num_res; res_id++)
            need[proc_id][res_id] = max[proc_id][res_id] - alloc[proc_id][res_id];
    }
    
	int y = 0;
    for (safe_seq = 0; safe_seq < num_proc; safe_seq++) {
        for (proc_id = 0; proc_id < num_proc; proc_id++) {
            if (finish[proc_id] == 0) {
                int safe_flag = 0;
                //Checks if the amount of available resources is enough for the process
                for (res_id = 0; res_id < num_res; res_id++) {
                    if (need[proc_id][res_id] > avail[res_id]) {
                        safe_flag = 1;
                        break;
                    }
                }
                // If the process is completed, it is marked as a safe process and releases whatever resources it used
                if (safe_flag == 0) {
                    ans[ind++] = proc_id;
                    for (y = 0; y < num_res; y++)
                        avail[y] += alloc[proc_id][y];
                    finish[proc_id] = 1;
                }
            }
        }
    }
    
	// The safe_flag is set to 1 and is then checked against the processes to ensure that everything is safe
    int safe_flag = 1;
    for (proc_id = 0; proc_id < num_proc; proc_id++) {
        if (finish[proc_id] == 0) {
            safe_flag = 0;
            printf("The system is in an unsafe state.\num_proc");
            break;
        }
    }
    
	// If all the processes are still safe, then it will report it is safe, alongside the sequence
    if (safe_flag == 1) {
        printf("The system is in a safe state.\nThe following is the safe sequence:\n");
        for (proc_id = 0; proc_id < num_proc - 1; proc_id++)
            printf("P%d ->", ans[proc_id]);
        printf("P%d ", ans[num_proc - 1]);
    }
    
	// Cleans up the line for the next run
    printf("\n");
    return 0;
}