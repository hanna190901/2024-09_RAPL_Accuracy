#include <EMA.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For usleep or sleep functions
#include <sys/time.h> // For time measurement


// FUNKTIONS

long long get_current_time_in_microseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int)(tv.tv_sec * 1000000 + tv.tv_usec);
}

void do_work(int dur){
    srand(1024);
    long long t_before = get_current_time_in_microseconds();
    long long t_new;
    do{
        rand();
        t_new = get_current_time_in_microseconds();
    } while(t_new - t_before < dur);
}

// MAIN

int main(int argc, char **argv)
{
    int err = EMA_init(NULL); // Initialize EMA

    if( err )		// Check for errors. If `err` is 0 then no error occurred.
        return 1;

    Filter *filter = EMA_filter_exclude_plugin("NVML"); // Create a filter to disable the NVML plugin.

    // Initialize a region.
    EMA_REGION_DECLARE(region_v0); // declares a region handle that holds the measurement data
    EMA_REGION_DECLARE(region_v1); 
    EMA_REGION_DECLARE(region_v2);
    EMA_REGION_DECLARE(region_v3);
    EMA_REGION_DECLARE(region_v4);
    EMA_REGION_DECLARE(region_v5);
    EMA_REGION_DECLARE(region_v6);
    EMA_REGION_DECLARE(region_v7);
    EMA_REGION_DECLARE(region_v8);
    EMA_REGION_DECLARE(region_v9);
    EMA_REGION_DECLARE(region_v10);

	// EMA_REGION_DEFINE` defines the region by setting a name
    EMA_REGION_DEFINE_WITH_FILTER(&region_v0, "v0", filter); //is an extended version that takes an optional filter argument
    EMA_REGION_DEFINE_WITH_FILTER(&region_v1, "v1", filter); 
    EMA_REGION_DEFINE_WITH_FILTER(&region_v2, "v2", filter);
    EMA_REGION_DEFINE_WITH_FILTER(&region_v3, "v3", filter);
    EMA_REGION_DEFINE_WITH_FILTER(&region_v4, "v4", filter);
    EMA_REGION_DEFINE_WITH_FILTER(&region_v5, "v5", filter);
    EMA_REGION_DEFINE_WITH_FILTER(&region_v6, "v6", filter);
    EMA_REGION_DEFINE_WITH_FILTER(&region_v7, "v7", filter);
    EMA_REGION_DEFINE_WITH_FILTER(&region_v8, "v8", filter);
    EMA_REGION_DEFINE_WITH_FILTER(&region_v9, "v9", filter);
    EMA_REGION_DEFINE_WITH_FILTER(&region_v10, "v10", filter);
    // Alternatively: `EMA_REGION_DEFINE(&region, "region");`

    
    int block_size = 1000; // 1ms
    int replication_num = 1; // block_size * replication_num = 10 s

    //srand(time(NULL)); // Zufallsgenerator mit dem aktuellen Zeitpunkt initialisieren
    
    int duration = 0;
    EMA_REGION_BEGIN(region_v0); //starts a measurement and stores the data in the region handle.
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v0); //stops a measurement and stores the data in the region handle.

    duration = 100;
    EMA_REGION_BEGIN(region_v1); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v1); 

    duration = 200;
    EMA_REGION_BEGIN(region_v2); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v2); 

    duration = 300;
    EMA_REGION_BEGIN(region_v3); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v3);

    duration = 400;
    EMA_REGION_BEGIN(region_v4); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v4); 

    duration = 500;
    EMA_REGION_BEGIN(region_v5); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v5); 

    duration = 600;
    EMA_REGION_BEGIN(region_v6); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v6);

    duration = 700;
    EMA_REGION_BEGIN(region_v7); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v7); 

    duration = 800;
    EMA_REGION_BEGIN(region_v8); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v8); 

    duration = 900;
    EMA_REGION_BEGIN(region_v9); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v9);

    duration = 1000;
    EMA_REGION_BEGIN(region_v10); 
	for(int x=0; x<replication_num; x++){
        do_work(duration);
		usleep(block_size-duration);
	}
    EMA_REGION_END(region_v10); 


    EMA_filter_finalize(filter); // releases a previously created filter. This is just required if a filter was initialized.

    EMA_finalize(); // Finalize EMA. This cleans up the EMA framework and prints out the measurement data.

    return 0;
}
