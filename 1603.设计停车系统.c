typedef struct {
    int s;
    int m;
    int b;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *obj = (ParkingSystem *)malloc(sizeof(ParkingSystem));
    if (obj == NULL) {
        return NULL;
    }
    obj->s = small;
    obj->m = medium;
    obj->b = big;
    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (carType == 3) {
        if (obj->s > 0) {
            obj->s -= 1;
            return true;
        }
    }
    if (carType == 1) {
        if (obj->b > 0) {
            obj->b -= 1;
            return true;
        }
    }
    if (carType == 2) {
        if (obj->m > 0) {
            obj->m -= 1;
            return true;
        }
    }
    return false;
}

void parkingSystemFree(ParkingSystem* obj) {
    if (obj != NULL) {
        free(obj);
        obj = NULL;
    }
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/