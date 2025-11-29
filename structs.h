#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_PRODUCTS 50
#define MAX_CHECKPOINTS 50

// Checkpoint structure
struct Checkpoint {
    char location[50];
    char status[50];
    char timestamp[30];
};

// Product structure
struct Product {
    int trackingID;
    int checkpointCount;
    struct Checkpoint *checkpoints;
};

#endif
