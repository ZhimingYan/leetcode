typedef struct {
        int phoneNum;
        bool used;
} PhoneDirectory;

/** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */

int g_len;
PhoneDirectory* phoneDirectoryCreate(int maxNumbers) {
        PhoneDirectory *obj = (PhoneDirectory *)malloc(maxNumbers * sizeof(PhoneDirectory));
        if (obj == NULL) {
                return NULL;
        }
        for (int i = 0; i  < maxNumbers; i++) {
                obj[i].phoneNum = i;
                obj[i].used = false;
        }
        g_len = maxNumbers;
        return obj;
}

/** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
int phoneDirectoryGet(PhoneDirectory* obj) {
        int index = 0;
        while (index < g_len) {
                if (obj[index].used == false) {
                        obj[index].used = true;
                        return index;
                }
                index ++;
        }
        return -1;
}

/** Check if a number is available or not. */
bool phoneDirectoryCheck(PhoneDirectory* obj, int number) {
        return !obj[number].used;
}

/** Recycle or release a number. */
void phoneDirectoryRelease(PhoneDirectory* obj, int number) {
        if(obj[number].used == true) {
                obj[number].used = false;
        }
}

void phoneDirectoryFree(PhoneDirectory* obj) {
        free(obj);
}

/**
 * Your PhoneDirectory struct will be instantiated and called as such:
 * PhoneDirectory* obj = phoneDirectoryCreate(maxNumbers);
 * int param_1 = phoneDirectoryGet(obj);
 
 * bool param_2 = phoneDirectoryCheck(obj, number);
 
 * phoneDirectoryRelease(obj, number);
 
 * phoneDirectoryFree(obj);
*/